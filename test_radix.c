#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
int findLargestNum(int * array, int size){
  
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }
  
  return largestNum;
}

// Radix Sort
void radixSort(int * array, int size){
  
  //printf("\n\nRunning Radix Sort on Unsorted List!\n\n");

  // Base 10 is used
  int i;
  int *semiSorted =(int *)malloc(sizeof(*array)*size);
  int significantDigit = 1;
  //printf("t1 %p\n", semiSorted);
  int largestNum = findLargestNum(array, size);
  //printf("%d,%d\n",largestNum,(int)ceil(log10(largestNum)));
  // Loop until we reach the largest significant digit
  for(int j = 0; j <= log10(largestNum); significantDigit *= 10, j++){
  //while (largestNum / significantDigit > 0){
    
    //printf("sig dig: %lld\n", significantDigit);
    //printf("\tSorting: %d's place ", significantDigit);
    //printArray(array, size);
    
    int bucket[10] = { 0 };
    
    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;
    
    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    // Use the bucket to fill a "semiSorted" array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];
    
    
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    
    // Move to next significant digit
    //significantDigit *= 10;
    
    //printf("\n\tBucket: ");
    //printArray(bucket, 10);
  };
  free(semiSorted);
};
void print_arr(int* arr, int n) {
  for(int i = 0; i < n; i++) {
    if(i % 10 == 0 && i != 0) printf("\n");
    printf("%d ", arr[i]);
  };
  printf("\n");
};

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
  radixSort(arr, n);
  //print_arr(arr, n);
  printf("Time: %.3f\n", (double)(clock() - start)/CLOCKS_PER_SEC);
  //sorted(arr, n);
  
  free(arr);

  return 0;

};
