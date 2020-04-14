#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
#include <assert.h>

#define MEM_SIZE  0x100000
#define SECTOR_SIZE  0x200

#define REG_Z       0
#define REG_PC     63

enum {
  OP_LOAD_B      =  0,
  OP_LOAD_H      =  1,
  OP_LOAD_W      =  2,
  OP_STORE_B     =  4,
  OP_STORE_H     =  5,
  OP_STORE_W     =  6,
  OP_ADD         =  8,
  OP_MUL         =  9,
  OP_DIV         = 10,
  OP_NOR         = 11,
  OP_MOVI        = 16,
  OP_CMOV        = 18,
  OP_IN          = 24,
  OP_OUT         = 25,
  OP_READ        = 26,
  OP_WRITE       = 27,
  OP_HALT        = 31,
};

typedef uint8_t  byte;
typedef uint32_t word;

void print_binary(word number)
{
    if (number) {
        print_binary(number >> 1);
        printf("%s", ((number & 1) ? "1" : "0"));
    }
}

/* Machine state */
static int disk;
static byte mem[MEM_SIZE];
static word regs[64] = { 0 };
#define MEM(addr) (*(assert((addr) < MEM_SIZE), &mem[(addr)]))

static
void disk_seek(word sector) {
  if ((off_t)-1 == lseek(disk, sector * 0x200, SEEK_SET)) {
    perror("lseek");
    exit(EXIT_FAILURE);
  }
}

static
void disk_read(word addr, word sector) {
  ssize_t ret;

  assert(addr % SECTOR_SIZE == 0 && "alignment error (read)");

  disk_seek(sector);

  ret = read(disk, &MEM(addr), SECTOR_SIZE);
  switch (ret) {

  case SECTOR_SIZE:
    break;

  case -1:
    perror("read");
    exit(EXIT_FAILURE);

  default:
    fprintf(stderr, "disk read error");
    exit(EXIT_FAILURE);
  }
}

static
void disk_write(word addr, word sector) {
  ssize_t ret;

  assert(addr % SECTOR_SIZE == 0 && "alignment error (write)");

  disk_seek(sector);

  ret = write(disk, &MEM(addr), SECTOR_SIZE);
  switch (ret) {

  case SECTOR_SIZE:
    break;

  case -1:
    perror("write");
    exit(EXIT_FAILURE);

  default:
    fprintf(stderr, "disk write error");
    exit(EXIT_FAILURE);
  }

}
int print_op = 0;
#define ch_size 256
char ch[ch_size] = { 0 };
int ch_in = 0, ch_given = 0;
static
bool spin() {
  word inst, pc, working_value = 0;
  unsigned int op, r, i, s, a, b, c;
  byte working_byte;

  pc = regs[REG_PC];
  assert(pc % 4 == 0 && "PC unaligned");

  /* Read 32bit big endian word */
  inst = \
    MEM(pc    ) << 24 | \
    MEM(pc + 1) << 16 | \
    MEM(pc + 2) <<  8 | \
    MEM(pc + 3);

  /* Increment PC before instruction execution */
  regs[REG_PC] += 4;

  /* Register 0 must always be zero */
  regs[REG_Z] = 0;

  /* Get the operation code */
      r = (inst >> 21) & 077;
      i = (inst >>  5) & 0xffff;
      s = (inst      ) & 037;
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
  op = inst >> 27;

  // if(print_op == 1) printf("%d, ", op);
  
  // printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", op, r, i, s, a, b, c);
  // printf("%x\t%x\t%x\t%x\t%x\t%x\t%x\t\n", op, r, i, s, a, b, c);
  // printf("%x\n", inst);
  // printf("%d\n", op);
  /*
  fprintf(stdout, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
              a, b, c, regs[a], regs[b], regs[c], 
              regs[b] + regs[c], working_value);
  */
  fflush(stdout);
  /* Execute MOVI-type instruction */
  switch (op) {
    case OP_MOVI: // 16
      r = (inst >> 21) & 077;
      i = (inst >>  5) & 0xffff;
      s = (inst      ) & 037;
      regs[r] = i << s;
      break;

    case OP_HALT: // 31
      fflush(stdout);
      fprintf(stderr, "HALTed\n");
      return false;

    case OP_LOAD_B: // 0
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      regs[a] = (word) MEM(regs[b] + regs[c]);
      break;

    case OP_LOAD_H: // 1
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      regs[a] = (word) (((word)MEM(regs[b] + regs[c])) << ((word) 8) |
                        ((word)MEM(regs[b] + regs[c] + 1))   );
      // printf("%x\t%x\t%x\n", regs[a], MEM(regs[b] + regs[c]), 
      //                      MEM(regs[b] + regs[c] + 1));
      break;

    case OP_LOAD_W: // 2
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      regs[a] = \
        MEM(regs[b] + regs[c]    ) << 24 | \
        MEM(regs[b] + regs[c] + 1) << 16 | \
        MEM(regs[b] + regs[c] + 2) <<  8 | \
        MEM(regs[b] + regs[c] + 3);
      /*
      printf("%x\t%x\t%x\t%x\t%x\n", regs[a], MEM(regs[b] + regs[c]), 
                           MEM(regs[b] + regs[c] + 1), 
                           MEM(regs[b] + regs[c] + 2), 
                           MEM(regs[b] + regs[c] + 3));
                           */
      break;

    case OP_STORE_B: // 4
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      working_byte = (byte) regs[a] & 0x000000ff;
      // printf("%d\n", working_byte);
      MEM(regs[b] + regs[c]) = working_byte;
      break;

    case OP_STORE_H: // 5
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      /*
      working_value = ((word)(regs[b] + regs[c])) % ((word) 2);
      if((regs[b] + regs[c]) % 2 != 0 || 1) {
      fprintf(stderr, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
              a, b, c, regs[a], regs[b], regs[c], 
              regs[b] + regs[c], working_value);
      fflush(stderr);
      };
      */
      assert((regs[b] + regs[c]) % 2 == 0 && "PC unaligned");
      MEM(regs[b] + regs[c] + 1) = (byte) (regs[a] & 0xff);
      MEM(regs[b] + regs[c]) = (byte) (regs[a] >> 8) & 0xff;
      break;

    case OP_STORE_W: // 6
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      /*
      if((regs[b] + regs[c]) % 4 != 0) {
      fprintf(stderr, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
              a, b, c, regs[a], regs[b], regs[c], 
              regs[b] + regs[c], (regs[b] + regs[c]) % 4);
      fflush(stderr);
      };
      */
      assert((regs[b] + regs[c]) % 4 == 0 && "PC unaligned");
      MEM(regs[b] + regs[c]    ) = (byte) (regs[a] >> 24  & 0xff);
      MEM(regs[b] + regs[c] + 1) = (byte) (regs[a] >> 16  & 0xff);
      MEM(regs[b] + regs[c] + 2) = (byte) (regs[a] >>  8  & 0xff);
      MEM(regs[b] + regs[c] + 3) = (byte) (regs[a]        & 0xff);
      /*
      printf("%x\t%x\t%x\t%x\t%x\n", regs[a], MEM(regs[b] + regs[c]), 
                           MEM(regs[b] + regs[c] + 1), 
                           MEM(regs[b] + regs[c] + 2), 
                           MEM(regs[b] + regs[c] + 3));
      printf("%x\t%x\t%x\t%x\t%x\n", regs[a], regs[a] >> 24 & 0xff, 
                           regs[a] >> 16 & 0xff, 
                           regs[a] >> 8 & 0xff, 
                           regs[a] & 0xff); 
      */
      break;

    case OP_ADD: // 8
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      // printf("%d\t%d\t%d\t%d\n", regs[a], regs[b], regs[c], working_value);
      working_value = regs[b] + regs[c];
      regs[a] = working_value;
      // printf("%d\t%d\t%d\t%d\n", regs[a], regs[b], regs[c], working_value);
      break;

    case OP_MUL: // 9
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      regs[a] = regs[b] * regs[c];
      break;

    case OP_DIV: // 10
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      regs[a] = regs[b] / regs[c];
      break;

    case OP_NOR: // 11
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      regs[a] = ~(regs[b] | regs[c]);
      break;

    case OP_CMOV: // 18
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      // printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%x\n", op, r, i, s, a, b, c, inst);
      if(regs[c] != 0) regs[a] = regs[b];
      break;

    case OP_IN: // 24
      print_op = 1;
      // printf("\n");
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      // char ch[128] = { 0 };
      // int i;
      // scanf("%s", ch);
      
      if(ch_in == 0) {
        char temp;
        scanf("%[^\n]", ch);
        scanf("%c", &temp);
        int i = 0;
        while(ch[i]) i++;
        ch_in = i;
        regs[a] = ch[ch_given++];
        // printf("given: %s, %d\nregs[a]: %c\n", ch, ch_in, regs[a]);
      } else if(ch_given == ch_in) {
            ch_given = 0;
            ch_in = 0;
            for(int i = 0; i < ch_size; i++) ch[i] = 0;
            regs[a] = 10;
      } else {
        regs[a] = ch[ch_given++];
      }

      break;

    case OP_OUT: // 25
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      printf("%c", (byte) regs[a] & 0xff);
      break;

    case OP_READ: // 26
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      disk_read(regs[a], regs[b]);
      break;

    case OP_WRITE: // 27
      a = (inst >> 21) & 077;
      b = (inst >> 15) & 077;
      c = (inst >>  9) & 077;
      disk_write(regs[a], regs[b]);
      break;

  }
  return true;
}

int main(int argc, char *argv[]) {
  if (2 != argc) {
    fprintf(stderr, "usage: %s <disk>\n", argv[0]);
    return EXIT_FAILURE;
  }

  disk = open(argv[1], O_RDWR);
  if (-1 == disk) {
    perror("open");
    return EXIT_FAILURE;
  }
  printf("start spin\nop\tr\ti\ts\ta\tb\tc\n");

  disk_read(0, 0);
  while (spin());
  printf("stop spin\n");

  close(disk);

  return EXIT_SUCCESS;
}
