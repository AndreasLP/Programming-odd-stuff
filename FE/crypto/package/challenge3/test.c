#include <stdio.h>
#include <gcrypt.h>
//#include <des.h>
#define KEYLEN 7
#define BUFSIZE 8
int main(void) {
  long long l = 1, plain = 0x5871643160744f22, cipher = 0xd5d7727715b5d38e;
  unsigned char * in[BUFSIZE], step1[BUFSIZE], out[BUFSIZE];
  gcry_cipher_hd_t hd1, hd2; 
  gcry_cipher_open( &hd1, GCRY_CIPHER_DES, GCRY_CIPHER_MODE_ECB, 0);
  gcry_cipher_open( &hd2, GCRY_CIPHER_DES, GCRY_CIPHER_MODE_ECB, 0);
  unsigned char * counter = malloc(BUFSIZE*sizeof(char));
  memcpy(in, &plain, BUFSIZE);


  long long key_1, key_2;
  for(key_1 = 0; key_1 < 1<<l; key_1++){
    gcry_cipher_setkey(hd1, &key_1, KEYLEN);
    gcry_cipher_encrypt(hd1, step1, BUFSIZE, in, BUFSIZE);
    for( key_2 = 0; key_2 < 1<<l; key_2++){
      gcry_cipher_setkey(hd2, &key_2, KEYLEN);
      gcry_cipher_encrypt(hd2, out, BUFSIZE, step1, BUFSIZE);
      printf("%s\n",out);
    };
  };
  gcry_cipher_close(hd1);
  gcry_cipher_close(hd2);
  return 0;
};
