#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include <algorithm>
#include <functional>
using namespace std;

struct KEY_RES {
  long key;
  long result;
  bool operator<(const KEY_RES& rhs) const { return result < rhs.result; }
  bool operator>(const KEY_RES& rhs) const { return result > rhs.result; }
  bool operator==(const KEY_RES& rhs) const { return result == rhs.result; }
  bool operator>=(const KEY_RES& rhs) const { return result >= rhs.result; }
  bool operator<=(const KEY_RES& rhs) const { return result <= rhs.result; }
};

void sorted(KEY_RES* arr, int n) {
  printf("Test for sorted: ");
  for(int i = 1; i < n; i++) {
    if(arr[i].result < arr[i-1].result) {printf("Not sorted\n"); return;};
  };
  printf("Sorted\n");
  return;
};

long bin_search(KEY_RES* arr, long size, long element) {
  long a = 0, b = size - 1, c = (long)size/2;
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
long bin_search1(long* arr, long size, long element) {
  long a = 0, b = size - 1, c = (long)size/2;
  if(arr[a] == element) return a;
  if(arr[b] == element) return b;
  while(b-a > 2) {
    if(arr[c] == element) return c;
    if(arr[c] > element) {
      b = c;
    } else {
      a = c;
    };
    c = (a + b)/2;
  };
  if(arr[c] == element) return c;
  if(arr[a] == element) return a;
  if(arr[b] == element) return b;
  return -1;
};

int main(int argc, char ** argv) {
  KEY_RES * arr = NULL;
  int n = 10;
  /*
  if(argc == 2) {
    n = atoi(argv[1]);
    printf("n: %e\n",(double)n);
    arr = (KEY_RES *)malloc(sizeof(KEY_RES)*n);
    if(arr == NULL) return 1;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
      arr[i].key = (int)rand();
      arr[i].result = (int)rand();
    };
  } else {
    long arr2[] = {5,4,3,7,8,6,2,1,9,0};
    n = 10;
    arr = (KEY_RES *)malloc(sizeof(KEY_RES)*n);
    for(int i = 0; i < n; i++) {
      arr[i].key = arr2[i]; 
      arr[i].result = arr2[i]; 
    }; 
  };
  */
  long element = 11;
  if(argc >= 2) element = atoi(argv[1]);
  if(argc >= 3) n = atoi(argv[2]);
  arr = (KEY_RES *)malloc(sizeof(KEY_RES)*n);
  for(long i = 0; i < n; i++) {
    arr[i].key = i*3 + 2;
    arr[i].result = i*2 + 1;
    
  };
  if(n < 30) {
    
    printf("Key:    ");
    for(long i = 0; i < n; i++) printf("%3d ", arr[i].key);
    printf("\n");
    
    printf("Result: ");
    for(long i = 0; i < n; i++) printf("%3d ", arr[i].result);
    printf("\n");
    
    printf("Index:  ");
    for(long i = 0; i < n; i++) printf("%3d ", i);
    printf("\n");
  };
  printf("Element: %ld, Idx: %ld\n", element, bin_search(arr, n, element));

  //print_arr(arr, n);
  //printf("%p\n",arr);
  //sorted(arr, n);
  //clock_t start = clock();
  //qsort(arr, n, sizeof *arr, compare);
  //std::sort(arr, arr+n);
  //print_arr(arr, n);
  //printf("Time: %.3f\n", (double)(clock() - start)/CLOCKS_PER_SEC);
  //sorted(arr, n);
  
  free(arr);

  return 0;

};
