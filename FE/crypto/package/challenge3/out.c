#include<stdio.h>

int main(void){
  unsigned int test = 1<<3;
  printf("%d\n",test);
  test = test>>2;

  printf("%d\n",test);

  printf("Test %d\n", test < 0 ? 0 : 1);
  return 0;
};
