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
  /* TODO: ... */
}

static
bool spin() {
  word inst, pc;
  unsigned int op, r, i, s;

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
  op = inst >> 27;

  /* Execute MOVI-type instruction */
  switch (op) {
    case OP_MOVI:
      r = (inst >> 21) & 077;
      i = (inst >>  5) & 0xffff;
      s = (inst      ) & 037;
      regs[r] = i << s;
      break;

    case OP_HALT:
      fprintf(stderr, "HALTed\n");
      return false;

    case OP_LOAD_B:
      break;

    case OP_LOAD_H:
      break;

    case OP_LOAD_W:
      break;

    case OP_STORE_B:
      break;

    case OP_STORE_H:
      break;

    case OP_STORE_W:
      break;

    case OP_ADD:
      break;

    case OP_MUL:
      break;

    case OP_DIV:
      break;

    case OP_NOR:
      break;

    case OP_CMOV:
      break;

    case OP_IN:
      break;

    case OP_OUT:
      break;

    case OP_READ:
      break;

    case OP_WRITE:
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

  disk_read(0, 0);
  while (spin());

  close(disk);

  return EXIT_SUCCESS;
}
