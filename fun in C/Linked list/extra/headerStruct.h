#ifndef headerStruct
#define headerStruct

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define printFileFuncLine(output) (fprintf((output),"\nFile: %s\nFunc: %s\nLine: %d\n",__FILE__,__func__,__LINE__));

typedef struct listElement_t listElement_t;
typedef struct list_t list_t;

struct listElement_t {
  double val;
  listElement_t* next;
  listElement_t* previous;
};

struct list_t {
  size_t length;
  listElement_t* first;
  listElement_t* last;
};
#endif
