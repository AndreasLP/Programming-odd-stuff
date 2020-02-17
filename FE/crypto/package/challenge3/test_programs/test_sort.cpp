#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include <algorithm>
#include <functional>
using namespace std;


int compare(const void *p, const void * q) {
  int x = *(const int *)p;
  int y = *(const int *)q;
  
  if(x > y) return 1;
  else if(x < y) return -1;
  else return 0;
  
}; 

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

int main(int argc, char ** argv) {
  KEY_RES * arr = NULL;
  int n = 0;
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
  //print_arr(arr, n);
  //printf("%p\n",arr);
  sorted(arr, n);
  clock_t start = clock();
  //qsort(arr, n, sizeof *arr, compare);
  std::sort(arr, arr+n);
  //print_arr(arr, n);
  printf("Time: %.3f\n", (double)(clock() - start)/CLOCKS_PER_SEC);
  sorted(arr, n);
  
  free(arr);

  return 0;

};
