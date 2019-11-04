#include<openssl/des.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<byteswap.h>
#include<endian.h>
#define BUFSIZE 8
#define KEYLEN 7

#define parity(n) ((0x007F000000000000 & n)<<1) + \
  ((0x00007F0000000000 & n)<<1) + \
  ((0x0000007F00000000 & n)<<1) + \
  ((0x000000007F000000 & n)<<1) + \
  ((0x00000000007F0000 & n)<<1) + \
  ((0x0000000000007F00 & n)<<1) + \
  ((0x000000000000007F & n)<<1)


//#define parity(n) ((0x7F & n)<<1) 

int main(int argc, char ** argv){
  printf("%d\n", (1<<2)+ (1<<5)); 
  
  size_t plain = 6372985110940372770, cipher = 0xd5d7727715b5d38e;
  unsigned char in[8], step1[8], out[8], res[8], tmp = 0x00;
  
  memcpy(in,&plain,8);
  memcpy(res,&cipher,8);
  
  for(int j = 0; j < 4; j++){
    tmp = in[j]; in[j] = in[7-j]; in[7-j] = tmp;
    tmp = res[j]; res[j] = res[7-j]; res[7-j] = tmp;
  };
  
  uint64_t key1 = 1, key2 = 1, skey1, skey2;
  DES_key_schedule keysch1, keysch2;
  DES_key_schedule *pkeysch1 = &keysch1, *pkeysch2 = &keysch2;


  unsigned int i,l;
  if(argc == 2) l = atoi(argv[1]);
  else {printf("Syntax: program {l}\n"); return 1;};
  unsigned long long limit = 1<<l;
  
  uint64_t * pskey1 = &skey1, *pskey2 = &skey2;

  // skey2 = bswap_64(key2);
  for(key1 = 0; key1 < limit; key1++){
    //DES_set_key((DES_cblock *)*key1, &keysch1);
    //skey1 = bswap_64(key1);
    skey1 = htobe64(parity(key1));
    //skey1 = parity(skey1);

    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
    DES_ecb_encrypt(&in, &step1, pkeysch1, 1);
    for(key2 = 1; key2 < limit; key2++){
      printf("Key 1: %lu   Key 2: %lu\n",key1,key2);
      skey2 = htobe64(parity(key2));
      DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
      //printf("%x\n",&keysch2);
      //DES_set_key((DES_cblock *)&key12, &keysch2);
      DES_ecb_encrypt(&step1, &out, pkeysch2, 1);
      if(0==memcmp(out, res, 8)){
        for(i = 0; i < 8; i++) 
          printf("%x",(unsigned long long)out[i]); 
        printf("\n");
        // free(key1);free(key2);
        // return 0;
      };
    };
  };
  return 0;
};
