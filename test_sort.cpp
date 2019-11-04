#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include <algorithm>
#include <functional>
void sorted(int* arr, int n) {
  printf("Test for sorted: ");
  for(int i = 1; i < n; i++) {
    if(arr[i] < arr[i-1]) {printf("Not sorted\n"); return;};
  };
  printf("Sorted\n");
  return;
};


int compare(const void *p, const void * q) {
  int x = *(const int *)p;
  int y = *(const int *)q;
  
  if(x > y) return 1;
  else if(x < y) return -1;
  else return 0;
  
}; 

int main(int argc, char ** argv) {
  int * arr = NULL;
  int n = 0;
  if(argc == 2) {
    n = atoi(argv[1]);
    printf("n: %e\n",(double)n);
    arr = (int *)malloc(sizeof(int)*n);
    if(arr == NULL) return 1;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
      arr[i] = (int)rand();
    };
  } else {
    int arr2[] = {5,4,3,7,8,6,2,1,9,0};
    n = 10;
    arr = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) arr[i] = arr2[i]; 
  };
  //print_arr(arr, n);
  //printf("%p\n",arr);
  //sorted(arr, n);
  clock_t start = clock();
  //qsort(arr, n, sizeof *arr, compare);
  std::sort(arr, arr+n, std::less<int>());
  //print_arr(arr, n);
  printf("Time: %.3f\n", (double)(clock() - start)/CLOCKS_PER_SEC);
  //sorted(arr, n);
  
  free(arr);

  return 0;

};
