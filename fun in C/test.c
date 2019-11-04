#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char **argv){
  float i = 100.0;
  if(argc==2) i = atof(argv[1]);
  printf("%f\n",ceil(log10(i)));
};
