#include<openssl/des.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<byteswap.h>
#include<endian.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<math.h>

#define timed

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b;} )
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

struct KEY_RES {
  uint64_t key;
  uint64_t result;
  bool operator<(const KEY_RES& rhs) const { return result < rhs.result; }
  bool operator>(const KEY_RES& rhs) const { return result > rhs.result; }
  bool operator==(const KEY_RES& rhs) const { return result == rhs.result; }
  bool operator>=(const KEY_RES& rhs) const { return result >= rhs.result; }
  bool operator<=(const KEY_RES& rhs) const { return result <= rhs.result; }
};

void sorted(KEY_RES* arr, int n);
long long bin_search(KEY_RES* arr, long size, long element);
long long COUNT_DEPTH;
long long bin_search_lin_inter(KEY_RES* arr, long size, long element);
long long fibMonaccianSearch(KEY_RES* arr, long x, long n);
long exponentialSearch(KEY_RES * arr, long n, long x);

int test_keys(uint64_t result);
int test_pair(void);
//int test_keys(uint64_t *pskey1, uint64_t *pskey2, 
//    DES_key_schedule *pkeysch1, DES_key_schedule *pkeysch2);

int test(uint64_t * middle, uint64_t * pl, uint64_t idx, 
    uint64_t* pskey2, DES_key_schedule *pkeysch2);

DES_key_schedule keysch1, keysch2;
DES_key_schedule *pkeysch1 = &keysch1, *pkeysch2 = &keysch2;
//DES_key_schedule *pkeysch1, DES_key_schedule pkeysch2;
unsigned char in[4][8], step1[4][8], out[4][8], res[4][8];
uint64_t longestprobe = 0, tmp_pl = 0, tmp_key = 0, 
         nonzero_pl = 0, indexer;

KEY_RES *middle;
long long table_size, idx_cand;

int main(int argc, char ** argv){
  long COUNTER = 0;
  clock_t start_t, end_t; double total_t;
  uint64_t l=0,key1 = 0, key2 = 0, skey1 = 0, skey2 = 0,
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
  
  fclose(f);

#ifdef debug
  printf("Limit: %llu\n",limit);
#endif


  uint64_t rounds = 1;
  if(limit < (1<<30)){
    table_size = limit;
    middle = (KEY_RES*)malloc( table_size * sizeof( KEY_RES ));
  }
  else{
    rounds = 1<<(l-29);
    table_size = 1<<29;
    middle = (KEY_RES*)malloc( table_size *sizeof( KEY_RES ));
  }
  printf("l: %2ld\tRounds: %ld\n", l, rounds);
  
  if(middle == NULL) {
    printf("Memory allocation failed\n");
    return 3;
  };

  indexer = table_size - 1;
  
  uint64_t *idx_step1 = (uint64_t *) step1[0],
           *idx_out   = (uint64_t *)   out[0];
#ifdef debug
  printf("Loop 1\n");
#endif

size_t i; uint64_t key1_limit;
for(long round = 1; round <= rounds; round++) {
#ifdef timed
  start_t = clock();
#endif
  
  key1_limit = round*table_size;
  for(i = 0; key1 < key1_limit; i++, key1++){
    skey1 = __bswap_64(parity(key1));

    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
    DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
    
    middle[i].key = skey1;
    middle[i].result = *idx_step1;
  
  };
  #ifdef timed
    end_t = clock();
    total_t = ( (double)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("Time key1: %5.3lf\nKeys tested: %lu\tKeys pr sec: %.3lf\n",
      total_t, table_size, (double)(table_size)/total_t);
  #endif

#ifdef debug
  for(int i = 0; i < table_size; i++) printf("%3d\t%6ld\t%6ld\n", i, 
      middle[i].key, middle[i].result);
#endif

#ifdef timed
start_t = clock();
#endif

  std::sort(middle, middle + table_size);

#ifdef timed
  end_t = clock();
  total_t = ((double)(end_t - start_t))/CLOCKS_PER_SEC;
  printf("Time sort: %5.3lf\n",
      total_t);
#endif

#ifdef timed
start_t = clock();
#endif

// Print middle array
//for(int i = 0; i < table_size; i++) printf("%zu ", middle[i].result);
//printf("\n\n");

for(key2 = 0; key2 <= limit; key2++){
    skey2 = __bswap_64(parity(key2));

    DES_set_key_unchecked((DES_cblock *)pskey2, pkeysch2);
    DES_ecb_encrypt(&res[0], &out[0], pkeysch2, 0);
    
    // idx_cand = bin_search(middle, table_size, *idx_out);
    idx_cand = bin_search_lin_inter(middle, table_size, *idx_out);
    // idx_cand = fibMonaccianSearch( middle, *idx_out, table_size);
    // idx_cand = exponentialSearch(middle, table_size, *idx_out);
    if( idx_cand >= 0) {
      COUNTER++;
      if(test_keys(*idx_out) == 1) {
        printf("Key 2: %016lx\n",bswap_64(*pskey2));
        goto CLEANUP;
      };
    };

  };
#ifdef timed
  end_t = clock();
  total_t = ((double)(end_t - start_t))/CLOCKS_PER_SEC;
  printf("Time key2: %5.3lf\nKeys tested: %zu\tKeys pr sec: %.3lf\n",
      total_t, limit, (double)(limit)/total_t);
#endif

};
  printf("Failed to find key\n");

  CLEANUP:
{
  printf("Counter: %ld\n", COUNTER);
#ifdef timed
  end_t = clock();
  total_t = ((double)(end_t - start_t))/CLOCKS_PER_SEC;
  printf("Time key2: %5.3lf\nKeys tested: %zu\tKeys pr sec: %.3lf\n",
      total_t, key2-1, (double)(key2-1)/total_t);
#endif

};


  
  free(middle);
  return 0;
};
int counter = 1;
int test_keys(uint64_t result) {
  // FUnction is untested
  long long first = idx_cand, last = idx_cand, MAX_IDX = table_size - 1;
  uint64_t skey1 = 0;
  uint64_t *pskey1 = &skey1;
  printf("Test %d\n", counter++);

  if( first > 0 ) 
    while(first > 0 && middle[first - 1].result == result) first--;
  
  if( last < MAX_IDX ) 
    while( last < MAX_IDX && middle[last + 1].result == result) last++;
  
  for( long long idx = first; idx <= last; idx++) {
    skey1 = middle[idx].key;
    DES_set_key_unchecked((DES_cblock *)pskey1, pkeysch1);
    if(test_pair() == 1) {

      printf("Key 1: %016lx\n",bswap_64(*pskey1));
      return 1;
    };

  };
  
  return 0;
}

int test_pair(void) {
  // Test the remaining three plaintext - ciphertest pairs
  // with the two key candidates
  // Return 0 if the keys are not the correct pair
  // Return 1 if the keys are the correct pair

  DES_ecb_encrypt(&in[1], &step1[1], pkeysch1, 1);
  DES_ecb_encrypt(&step1[1], &out[1], pkeysch2, 1);
  if( 0!= memcmp(out[1], res[1], 8) ) return 0;

  DES_ecb_encrypt(&in[2], &step1[2], pkeysch1, 1);
  DES_ecb_encrypt(&step1[2], &out[2], pkeysch2, 1);
  if( 0!= memcmp(out[2], res[2], 8) ) return 0;
  
  DES_ecb_encrypt(&in[3], &step1[3], pkeysch1, 1);
  DES_ecb_encrypt(&step1[3], &out[3], pkeysch2, 1);
  if( 0!= memcmp(out[3], res[3], 8) ) return 0;
  
  // The two keys give the same result for the first plaintext - ciphertext pair
  //DES_ecb_encrypt(&in[0], &step1[0], pkeysch1, 1);
  //DES_ecb_encrypt(&step1[0], &out[0], pkeysch2, 1);
  //if( 0!= memcmp(out[0], res[0], 8) ) return 0;
  
  // printf("Key 1: %016lx\n",bswap_64(*pskey1));
  // printf("Key 2: %016lx\n",bswap_64(*pskey2));
  return 1;

  // Old code. Does all encryption/decryption before comparing. 
  // Not believed to be faster
  /*
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
  */
};


void sorted(KEY_RES* arr, int n) {
  printf("Test for sorted: ");
  for(int i = 1; i < n; i++) {
    if(arr[i].result < arr[i-1].result) {printf("Not sorted\n"); return;};
  };
  printf("Sorted\n");
  return;
};

long long bin_search(KEY_RES* arr, long size, long element) {
  size_t a = 0, b = size - 1, c = (size_t)size/2;
  if(arr[a].result == element) return a;
  if(arr[b].result == element) return b;
  while(b-a > 2) {
    if(arr[c].result == element) return c;
    if(arr[c].result > element) {
      b = c;
    } else {
      a = c;
    };
    c = (a + b)/2;
  };
  if(arr[c].result == element) return c;
  if(arr[a].result == element) return a;
  if(arr[b].result == element) return b;
  return -1;
};
size_t a, b, c;
long long bin_search_lin_inter(KEY_RES* arr, long size, long element) {
  a = 0, b = size - 1; // = (size_t)size/2;
  // COUNT_DEPTH = 0;
  // if(arr[a].result == element) return a;
  // if(arr[b].result == element) return b;
  while((arr[b].result != arr[a].result) && (element >= arr[a].result) && (element <= arr[b].result)) {
    //if(arr[c].result == element) return c;
    c = a + ((b - a)*((double)(element - arr[a].result)) / (arr[b].result - arr[a].result));
    if(arr[c].result > element) {
      b = c-1;
    } else if (arr[c].result < element){
      a = c+1;
    } else
      return c;
  };
  if(arr[a].result == element) 
    return a;
  else 
    return -1;
};

// long min(long x, long y) { return (x<=y)? x : y; } 
  
// The following search algorithms uses the code from geeksforgeeks.com
/* Returns index of x if present,  else returns -1 */
long long fibMonaccianSearch(KEY_RES* arr, long x, long n) 
{ 
    /* Initialize fibonacci numbers */
    long fibMMm2 = 0;   // (m-2)'th Fibonacci No. 
    long fibMMm1 = 1;   // (m-1)'th Fibonacci No. 
    long fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci 
  
    /* fibM is going to store the smallest Fibonacci 
       Number greater than or equal to n */
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
  
    // Marks the eliminated range from front 
    long offset = -1; 
  
    /* while there are elements to be inspected. Note that 
       we compare arr[fibMm2] with x. When fibM becomes 1, 
       fibMm2 becomes 0 */
    while (fibM > 1) 
    { 
        // Check if fibMm2 is a valid location 
        long i = min(offset+fibMMm2, n-1); 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray array from offset to i */
        if (arr[i].result < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray after i+1  */
        else if (arr[i].result > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 
  
        /* element found. return index */
        else return i; 
    } 
  
    /* comparing the last element with x */
    if(fibMMm1 && arr[offset+1].result==x)return offset+1; 
  
    /*element not found. return -1 */
    return -1; 
};
long binarySearch(KEY_RES * arr, long l, long r, long x);
long exponentialSearch(KEY_RES * arr, long n, long x)
{
    // If x is present at firt location itself
    if (arr[0].result == x)
        return 0;

    // Find range for binary search by
    // repeated doubling
    long i = 1;
    while (i < n && arr[i].result <= x)
        i = i*2;

    //  Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n), x);
}

// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
long binarySearch(KEY_RES * arr, long l, long r, long x)
{
    if (r >= l)
    {
        long mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid].result == x)
            return mid;

        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid].result > x)
            return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
    }

    // We reach here when element is not present
    // in array
    return -1;
}
