#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
  int t = 2;
  if(argc > 1) t = atoi(argv[1]);

  if(t == 0) printf("t: 0\n", t);
  else if(t == 1) printf("t: 1\n", t);
  else if(t == 2) printf("t: 2\n", t);
  else printf("t: other\n", t);

  switch (t) {
  case 0:
    printf("0\n");
    break;
  
  case 1:
    printf("1\n");
    break;
  
  case 2:
    printf("2\n");
    break;
  
  default:
    printf("other\n");
  }

  return 0;
};
