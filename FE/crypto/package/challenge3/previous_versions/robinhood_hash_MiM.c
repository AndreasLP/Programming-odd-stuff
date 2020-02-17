#include<openssl/des.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<byteswap.h>
#include<endian.h>
#include<time.h>
#include<math.h>

#define timed

//#define debug
//#define hash(key) ((((key+3))*(key+1))*19) & indexer
#define hash(key) ( ( (key)*1140071481932319 )&indexer )

#define clear_table_middle\
  for( idx = 0; idx < table_size; idx++) middle[idx] = 0
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b;} )
#define parity(n) (((0x00FE000000000000 & n)<<8) | \
  ((0x0001FC0000000000 & n)<<7) | \
  ((0x000003F800000000 & n)<<6) | \
  ((0x00000007F0000000 & n)<<5) | \
  ((0x000000000FE00000 & n)<<4) | \
  ((0x00000000001FC000 & n)<<3) | \
  ((0x0000000000003F80 & n)<<2) | \
  ((0x000000000000007F & n)<<1))

#define INDEX 0x00000000FFFFFFFF

static inline uint64_t hash_with_probe(uint64_t key, int probe);

void statistics(uint64_t * middle, int64_t * pl, uint64_t limit);

void insert(uint64_t * middle, uint64_t * pl, uint64_t idx, uint64_t skey);

int test_keys(uint64_t *pskey1, uint64_t *pskey2, 
    DES_key_schedule *pkeysch1, DES_key_schedule *pkeysch2);

int test(uint64_t * middle, uint64_t * pl, uint64_t idx, 
    uint64_t* pskey2, DES_key_schedule *pkeysch2);

//uint64_t *middle, *pl;

DES_key_schedule keysch1, keysch2;
DES_key_schedule *pkeysch1 = &keysch1, *pkeysch2 = &keysch2;
//DES_key_schedule *pkeysch1, DES_key_schedule pkeysch2;
unsigned char in[4][8], step1[4][8], out[4][8], res[4][8];
uint64_t longestprobe = 0, tmp_pl = 0, tmp_key = 0, 
         nonzero_pl = 0, indexer, table_size;

int main(int argc, char ** argv){


  time_t start_t, end_t, total_t;

  uint64_t l=0,key1 = 1, key2 = 1, skey1 = 0, skey2 = 0,
           idx = 0,*pskey1 = &skey1, *pskey2 = &skey2;

  if(argc == 2)
    l = atoi(argv[1]);
  else{
    printf("Syntax: program {l}\n"); return 1;
  };
  
  unsigned long long limit = 1<<l, tmp_l = 0, plain = 0, cipher = 0, count = 0;
  unsigned char tmp = 0;

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

  uint64_t *middle, *pl;

  uint64_t loop_type = 0;
  if(limit < (1<<28)){
    loop_type = 1;
    table_size = limit<<1;
    middle = (uint64_t*)malloc((table_size)*sizeof(uint64_t));
    pl = (uint64_t*)malloc((table_size)*sizeof(int64_t));
  }
  else{
    loop_type = 2;
    table_size = 1<<29;
    middle = (uint64_t*)malloc((1<<29)*sizeof(uint64_t));
    pl = (uint64_t*)malloc((1<<29)*sizeof(int64_t));
  }
  
  if(middle == NULL || pl == NULL) {
    printf("Memory allocation failed\n");
    return 3;
  };

  for( idx = 0; idx < table_size; idx++) {
    pl[idx] = -1;
    middle[idx] = 0;
  };
  //clear_table_middle;

  indexer = table_size - 1;
  
  uint64_t *idx_step1 = (uint64_t *) step1[0],
           *idx_out   = (uint64_t *)   out[0];
#ifdef debug
  printf("Loop 1\n");
#endif
#ifdef timed
start_t = time(0);
#endif



  for(key1 = 1; key1 < limit; key1++){
    skey1 = __bswap_64(parity(key1));

    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
    DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
    
    insert(middle, pl, hash(*idx_step1), skey1);
    
  
#ifdef debug
    printf("Inserted at: %d\n", *idx_step1 & indexer);
#endif

  };
  #ifdef timed
    end_t = time(0);
    total_t = (end_t - start_t);
    printf("Time key1: %d\nKeys tested: %lu\nKeys pr sec: %.3lf\n\n",
      total_t, key1-1, (double)(key1-1)/total_t);
  #endif

  //statistics(middle, pl, limit);
 
  /*
  for(idx = 0; idx < table_size; idx++) {
    if(idx%15==0) printf("\n");
    printf("%4x ",__bswap_64(middle[idx]));
  };
  printf("\n");
  for(idx = 0; idx < table_size; idx++) {
    if(idx%15==0) printf("\n");
    printf("%4ld ",pl[idx]);
  };
  printf("\n");
*/

  //for(idx = 0; idx < table_size; idx++) if(pl[idx]!=-1) 
    //printf("Skey: %x at %lu\n", __bswap_64(middle[idx]), idx );
  //goto CLEANUP;
  

#ifdef timed
start_t = time(0);
#endif
  
for(key2 = 0; key2 < limit; key2++){
    skey2 = __bswap_64(parity(key2));

    DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
    DES_ecb_encrypt(&res[0], &out[0], pkeysch2, 0);
    
//      if(__bswap_64(skey2) == 0x2d4) {printf("! %lu\n", hash(*idx_out));
//      for(size_t i = 0;i<8;i++) printf("%02x",out[0][i]); printf("\n");
//      };
    if((pl[hash(*idx_out)]) != -1) {
      //if(__bswap_64(skey2) == 0x2d4) printf("!\n");
      if(test(middle, pl, hash(*idx_out), pskey2, pkeysch2) == 1) goto CLEANUP;

    };

  };
  
printf("Failed to find key\n");

  CLEANUP:{printf("Cleanup started\n\n");};

#ifdef timed
end_t = time(0);
total_t = (end_t - start_t);
printf("Time key2: %d\nKeys tested: %zu\nKeys pr sec: %.3lf\n\
    Non zero pl test: %lu\n",
    total_t, key2-1, (double)(key2-1)/total_t, nonzero_pl);
#endif
  
  //delete_table(middle, table_size);
  free(middle);
  free(pl);
  return 0;
};

void statistics(uint64_t * middle, int64_t * pl, uint64_t limit){
  printf("Longest probe length: %lu\n",longestprobe);
  uint64_t keys = 0, zero_pl = 0;
  double mean_pl = 0, var_pl = 0;
  for(uint64_t idx = 0; idx < table_size; idx++) {
    if(pl[idx] != -1) {
      keys++;
      mean_pl += pl[idx];
      if(pl[idx]==0) zero_pl++;
    };
  };
  mean_pl /= keys;
  for(uint64_t idx = 0; idx < table_size; idx++) 
    if(pl[idx] != -1 ) var_pl += (pl[idx]-mean_pl)*(pl[idx]-mean_pl);
  var_pl /= keys;

  printf("Used keys: %lu\nPrediction: %lu\n\n",keys,limit-1);
  printf("Zero probe length: %d\n\
      Mean probe length: %.3lf\nVar probe length: %.3lf\n\n", 
  zero_pl, mean_pl,var_pl);

};

void insert(uint64_t * middle, uint64_t * pl, uint64_t idx, uint64_t skey){
  uint64_t cpl = 0, tmp_key = 0, tmp_pl = 0, IDX = idx + 1;
  IDX--;
#ifdef debug
  printf("Key inserted %lx at %zu\n", skey, idx);
#endif

  if(pl[idx] == -1) { 
    middle[idx] = (skey); 
    pl[idx] = 0;
    return; 
  } 
  
  else{

    do{
      cpl++;
      idx = hash_with_probe(idx, cpl);
      
      //printf("idx: %lu cpl: %lu\n",idx,cpl);
      if(pl[idx] == -1) { 
        middle[idx] = (skey); 
        pl[idx] = 0;
        //printf("1 ");
        break; 
      } 
      
      if(pl[idx] > cpl) continue;
      
      tmp_key = middle[idx]; 
      middle[idx] = skey; 
      skey = tmp_key;
          
      longestprobe = max(longestprobe, (uint64_t)cpl);

      tmp_pl = pl[idx]; 
      pl[idx] = cpl;
      cpl = tmp_pl;
      
    } while(1==1);
    longestprobe = max(longestprobe, (uint64_t)cpl);
  };
 return; 
}; 


int test_keys(uint64_t *pskey1, uint64_t *pskey2, 
    DES_key_schedule *pkeysch1, DES_key_schedule *pkeysch2){
#ifdef debug
  printf("test_keys part 1\n");
#endif

  DES_ecb_encrypt(&in[1], &step1[1], pkeysch1, 1);
  DES_ecb_encrypt(&step1[1], &out[1], pkeysch2, 1);
  if( 0!= memcmp(out[1], res[1], 8) ) return 0;

  DES_ecb_encrypt(&in[2], &step1[2], pkeysch1, 1);
  DES_ecb_encrypt(&step1[2], &out[2], pkeysch2, 1);
  if( 0!= memcmp(out[2], res[2], 8) ) return 0;
  
  DES_ecb_encrypt(&in[3], &step1[3], pkeysch1, 1);
  DES_ecb_encrypt(&step1[3], &out[3], pkeysch2, 1);
  if( 0!= memcmp(out[3], res[3], 8) ) return 0;
  
  DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
  DES_ecb_encrypt(&step1[0], &out[0], pkeysch2, 1);
  if( 0!= memcmp(out[0], res[0], 8) ) return 0;
  
  printf("Key 1: %016lx\n",bswap_64(*pskey1));
  printf("Key 2: %016lx\n",bswap_64(*pskey2));
  return 1;

  DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
  DES_ecb_encrypt(&in[2], &step1[2], pkeysch1, 1);
  DES_ecb_encrypt(&in[3], &step1[3], pkeysch1, 1);
#ifdef debug
  printf("test_keys part 2\n");
#endif
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

int test(uint64_t * middle, uint64_t * pl, uint64_t idx, 
    uint64_t *pskey2, DES_key_schedule *pkeysch2){

  uint64_t skey1 = 0, *pskey1;
  pskey1 = &skey1;
  

  //if(__bswap_64(*pskey2) == 0x2d4) printf("T1 %lu\n",idx);
  if(pl[idx] == 0){ ;
    skey1 = ((middle[idx]));
    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
  
    if(test_keys(pskey1, pskey2, pkeysch1, pkeysch2) ) 
      return 1;
    return 0;
  };

  //if(__bswap_64(*pskey2) == 4) printf("T2\n");
  for(uint64_t offset = 1; offset <= longestprobe; offset++){
      //offset <= longestprobe && offset <= pl[idx+offset]; offset++){
    skey1 = ((middle[hash_with_probe(idx, offset)]));
    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
    //if(__bswap_64(*pskey2) == 4) printf("skey1: %lu\n", __bswap_64(skey1));
    if(test_keys(pskey1, pskey2, pkeysch1, pkeysch2) ) 
      return 1;
  };
  
  //if(__bswap_64(*pskey2) == 4) printf("T3\n");
  skey1 = ((middle[idx]));
  DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
  //if(__bswap_64(*pskey2) == 4) printf("skey1: %lu\n", __bswap_64(skey1));
  
  if(test_keys(pskey1, pskey2, pkeysch1, pkeysch2)) 
      return 1;
  
  return 0;

};


static inline uint64_t hash_with_probe(uint64_t key, int probe){
  uint64_t probed_hash = key + probe * (probe+1);
  return (probed_hash & indexer);
};





