#include<openssl/des.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<byteswap.h>
#include<endian.h>
#define BUFSIZE 8
#define KEYLEN 7

#define parity(n) (((0x00FE000000000000 & n)<<8) | \
  ((0x0001FC0000000000 & n)<<7) | \
  ((0x000003F800000000 & n)<<6) | \
  ((0x00000007F0000000 & n)<<5) | \
  ((0x000000000FE00000 & n)<<4) | \
  ((0x00000000001FC000 & n)<<3) | \
  ((0x0000000000003F80 & n)<<2) | \
  ((0x000000000000007F & n)<<1))


//#define parity(n) ((0x7F & n)<<1) 

int main(int argc, char ** argv){
  //printf("%d\n", (1<<2)+ (1<<5)); 
  
  unsigned int l=0;

  if(argc == 2) l = atoi(argv[1]);
  else {printf("Syntax: program {l}\n"); return 1;};
  unsigned long long limit = 1<<l;
  
  unsigned long long tmp_l = 0, plain = 0, cipher = 0, count = 0;
  unsigned char in[4][8], step1[4][8], out[4][8], res[4][8], tmp = 0;

  FILE * f = fopen("blocks.txt", "r");
  if(f==NULL){printf("blocks.txt not found\n"); return 1;};
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
  
  /*
  memcpy(in,&plain,8);
  memcpy(res,&cipher,8);
    for(int j = 0; j < 4; j++){
    tmp = in[j]; in[j] = in[7-j]; in[7-j] = tmp;
    tmp = res[j]; res[j] = res[7-j]; res[7-j] = tmp;
  };
  */
  uint64_t key1 = 1, key2 = 1, skey1, skey2;
  DES_key_schedule keysch1, keysch2;
  DES_key_schedule *pkeysch1 = &keysch1, *pkeysch2 = &keysch2;

  uint64_t * pskey1 = &skey1, *pskey2 = &skey2, test = 0x1234567812345678
    , test2 = 1, test3 = 1;
  test3 = test3<<32;
  unsigned int *test22 = (unsigned int *)&test2,
               *test23 = (unsigned int *)&test3;
  //printf("Test2: %u\nTest3: %u\n", *test22, *test23);
  // skey2 = bswap_64(key2);
  for(key1 = 0; key1 < limit; key1++){
    skey1 = __bswap_64(parity(key1));

    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
    DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
    for(key2 = 1; key2 < limit; key2++){
      skey2 = __bswap_64(parity(key2));
      DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
      DES_ecb_encrypt(&step1[0], &out[0], pkeysch2, 1);
      if(0==memcmp(out[0], res[0], 8)){
          
        DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
        
        DES_ecb_encrypt(&in[1], &step1[1], pkeysch1, 1);
        DES_ecb_encrypt(&in[2], &step1[2], pkeysch1, 1);
        DES_ecb_encrypt(&in[3], &step1[3], pkeysch1, 1);

        DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
        DES_ecb_encrypt(&step1[1], &out[1], pkeysch2, 1);
        DES_ecb_encrypt(&step1[2], &out[2], pkeysch2, 1);
        DES_ecb_encrypt(&step1[3], &out[3], pkeysch2, 1);

        if( 0!=memcmp(out[1], res[1], 8) || 
            0!=memcmp(out[2], res[2], 8) ||
            0!=memcmp(out[3], res[3], 8)) continue;
        
        printf("Key 1: %016lx\t%lu\n",bswap_64(skey1), key1);
        printf("Key 2: %016lx\t%lu\n",bswap_64(skey2), key2);
        printf("Keys tested: %llu\n",(key1)*(limit-1)+key2);
        return 0;
        // free(key1);free(key2);
        // return 0;
      };
    };
  };
  return 0;
};
