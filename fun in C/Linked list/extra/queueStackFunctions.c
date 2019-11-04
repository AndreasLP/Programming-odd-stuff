#include "headerCommands.h"
// The element last going out is in the end of the list
double queuePop(list_t* queue){
  double value = listAccess(queue, 0);
  listDelete(queue, 0);
  return value;
};
int queuePush(list_t* queue, double value){
  return listInsert(queue, value, queue->length);
};

double stackPop(list_t* stack){
  return queuePop(stack);
};
int stackPush(list_t* stack, double value){
  return listInsert(stack, value, 0);
};
