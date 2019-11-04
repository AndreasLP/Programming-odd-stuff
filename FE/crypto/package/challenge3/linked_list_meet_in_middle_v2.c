#include<openssl/des.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<byteswap.h>
#include<endian.h>
#include<time.h>
#define BUFSIZE 8
#define KEYLEN 7
#define timed
#define parity(n) (((0x00FE000000000000 & n)<<8) | \
  ((0x0001FC0000000000 & n)<<7) | \
  ((0x000003F800000000 & n)<<6) | \
  ((0x00000007F0000000 & n)<<5) | \
  ((0x000000000FE00000 & n)<<4) | \
  ((0x00000000001FC000 & n)<<3) | \
  ((0x0000000000003F80 & n)<<2) | \
  ((0x000000000000007F & n)<<1))

#define INDEX 0x00000000FFFFFFFF

typedef struct ciphered {
  uint64_t key;
  struct ciphered * next;
} ciphered;

void insert(ciphered ** middle, size_t idx, uint64_t key);
void delete_table(ciphered ** middle, unsigned int table_size);

int test_keys(unsigned char in[4][8],
    unsigned char step1[4][8], unsigned char out[4][8], unsigned char res[4][8],
    uint64_t *pskey1, uint64_t *pskey2,
    DES_key_schedule *pkeysch1, DES_key_schedule *pkeysch2);

int test(ciphered ** middle, uint64_t idx, unsigned char in[4][8],
    unsigned char step1[4][8], unsigned char out[4][8], unsigned char res[4][8],
    uint64_t *pskey2, DES_key_schedule *pkeysch1, DES_key_schedule *pkeysch2);

int main(int argc, char ** argv){
  clock_t start_t, end_t, total_t;
  uint64_t l=0,key1 = 1, key2 = 1, skey1, skey2,
           *pskey1 = &skey1, *pskey2 = &skey2;

  if(argc == 2)
    l = atoi(argv[1]);
  else{
    printf("Syntax: program {l}\n"); return 1;
  };
  
  unsigned long long limit = 1<<l, tmp_l = 0, plain = 0, cipher = 0, count = 0;
  unsigned char in[4][8], step1[4][8], out[4][8], res[4][8], tmp = 0;

  FILE * f = fopen("blocks.txt", "r");
  if(f==NULL){ printf("blocks.txt not found\n"); return 2; };
  while(EOF != fscanf(f, "l-plain-cipher: %02llu %llx %llx\n", 
        &tmp_l, &plain, &cipher)){
    if(tmp_l==l){

      memcpy(in[count],&plain,8);
      memcpy(res[count],&cipher,8);
      for(int j = 0; j < 4; j++){
        tmp = in[count][j]; 
        in[count][j] = in[count][7-j]; 
        in[count][7-j] = tmp;
        
        tmp = res[count][j]; 
        res[count][j] = res[count][7-j]; 
        res[count][7-j] = tmp;
      };
      count++;
    }
    else if(count >= 3 || tmp_l > l) break;
  };
#ifdef debug
  printf("Limit: %llu\n",limit);
#endif
  ciphered **middle;

  unsigned int table_size = 0, loop_type = 0;
  if(limit < (1<<28)){
    loop_type = 1;
    table_size = limit<<2;
    middle = malloc((table_size)*sizeof(ciphered*));
  }
  else{
    loop_type = 2;
    table_size = 1<<29;
    middle = malloc((1<<29)*sizeof(ciphered));
  }
  
  if(middle == NULL) {
    printf("Memory allocation failed\n");
    return 3;
  };

  for(size_t idx = 0; idx < table_size; idx++) middle[idx] = NULL;

  DES_key_schedule keysch1, keysch2;
  DES_key_schedule *pkeysch1 = &keysch1, *pkeysch2 = &keysch2;

  uint64_t indexer = table_size - 1;
  //unsigned int Idx;
  // skey2 = bswap_64(key2);
  uint64_t *idx_step1 = (uint64_t *) step1[0],
           *idx_out   = (uint64_t *)   out[0];
#ifdef debug
  printf("Loop 1\n");
#endif
#ifdef timed
start_t = clock();
#endif



  for(key1 = 0; key1 < limit; key1++){
    skey1 = __bswap_64(parity(key1));

    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
    DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
    //insert(middle, *idx_step1 & indexer, key1);

  };
#ifdef timed
end_t = clock();
total_t = (end_t - start_t)/CLOCKS_PER_SEC;
printf("Time key1: %.3f\nKeys tested: %lu\nKeys pr sec: %.2lf\n\n",
    total_t, key1+1, (double)(key1+1)/total_t);
#endif
goto CLEANUP;
#ifdef debug
  printf("Loop 2\n");
#endif

#ifdef timed
start_t = clock();
#endif
  for(key2 = 1; key2 < limit; key2++){
    skey2 = __bswap_64(parity(key2));
    DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
    DES_ecb_encrypt(&res[0], &out[0], pkeysch2, 0);

    if(middle[*idx_out & indexer] != NULL) {
#ifdef debug
      printf("test call\n");
#endif
      if(test(middle, *idx_out & indexer, in, step1, out, res, 
            pskey2, pkeysch1, pkeysch2) == 1) goto CLEANUP;
    };

  };
  printf("Failed to find key");

  CLEANUP:{printf("Cleanup started\n\n");};

#ifdef timed
end_t = clock();
total_t = (end_t - start_t)/CLOCKS_PER_SEC;
printf("Time key2: %.3f\nKeys tested: %zu\nKeys pr sec: %.2lf\n\n",
    total_t, key2, (double)limit/total_t);
#endif
  delete_table(middle, table_size);
  return 0;
};

void insert(ciphered ** middle, size_t idx, uint64_t key) {
  ciphered * element = malloc(sizeof(ciphered));
  element->key = key;
#ifdef debug
  printf("Key inserted %lx at %zu\n",key,idx);
#endif
  if(middle[idx] == NULL) {
    middle[idx] = element;
    return;
  }
  else {
    ciphered * next = middle[idx];
    while(next->next != NULL) next = next->next;
    next->next = element;
    return;
  };

}; 

void delete_table(ciphered ** middle, unsigned int table_size) {

  ciphered *next_element = NULL, *tmpPointer;
  
  for(size_t idx = 0; idx < table_size; idx++){
  
    if(middle[idx] != NULL) {
      next_element = middle[idx];
    
      while(next_element->next != NULL) {
        tmpPointer = next_element->next;
        free(next_element);
        next_element = tmpPointer;
      };
      
      free(next_element);
    };
  };

  free(middle);
};

int test_keys(unsigned char in[4][8],
    unsigned char step1[4][8], unsigned char out[4][8], unsigned char res[4][8],
    uint64_t *pskey1, uint64_t *pskey2,
    DES_key_schedule *pkeysch1, DES_key_schedule *pkeysch2){
#ifdef debug
  printf("test_keys part 1\n");
#endif

  DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
  DES_ecb_encrypt(&in[1], &step1[1], pkeysch1, 1);

  DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
  DES_ecb_encrypt(&step1[1], &out[1], pkeysch2, 1);

  if( 0!= memcmp(out[1], res[1], 8) ) return 0;

  DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
  DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
  DES_ecb_encrypt(&in[2], &step1[2], pkeysch1, 1);
  DES_ecb_encrypt(&in[3], &step1[3], pkeysch1, 1);
#ifdef debug
  printf("test_keys part 2\n");
#endif
  DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
  DES_ecb_encrypt(&step1[0], &out[0], pkeysch2, 1);
  DES_ecb_encrypt(&step1[2], &out[2], pkeysch2, 1);
  DES_ecb_encrypt(&step1[3], &out[3], pkeysch2, 1);

#ifdef debug
  printf("test_keys part 3\n");
#endif
  if( 0==memcmp(out[0], res[0], 8) && 
      0==memcmp(out[2], res[2], 8) &&
      0==memcmp(out[3], res[3], 8)){
    
#ifdef debug
    printf("test_keys part 4\n");
#endif    
    printf("Key 1: %016lx\n",bswap_64(*pskey1));
    printf("Key 2: %016lx\n",bswap_64(*pskey2));
    return 1;
  };
  return 0;
};

int test(ciphered ** middle, uint64_t idx, unsigned char in[4][8],
    unsigned char step1[4][8], unsigned char out[4][8], unsigned char res[4][8],
    uint64_t *pskey2, DES_key_schedule *pkeysch1, DES_key_schedule *pkeysch2){
#ifdef debug
  printf("test at index: %zu\n",idx);
#endif
  uint64_t skey1 = 0, *pskey1 = &skey1;
  ciphered * element = middle[idx];
  
  skey1 = __bswap_64(parity(element->key));
#ifdef debug
  printf("skey1 made\n");
#endif
  if(test_keys(in, step1, out, res, pskey1, pskey2, pkeysch1, pkeysch2)) 
    return 1;
#ifdef debug
  printf("First test passed\n");
#endif
  if(element->next == NULL) return 0;

  do{
#ifdef debug
    printf("Do while started\n");
#endif
    element = element->next;
#ifdef debug
    printf("Do while part 1\n");
#endif
    skey1 = __bswap_64(parity(element->key));
#ifdef debug
    printf("Do while part 2\n");
#endif
    if(test_keys(in, step1, out, res, pskey1, pskey2, pkeysch1, pkeysch2)) 
      return 1;

  } while(element->next != NULL);

  return 0;
};






