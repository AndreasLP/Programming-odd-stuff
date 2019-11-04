#include "headerStruct.h"

#ifndef headerCommands
#define headerCommands
double queuePop(list_t* queue);
int queuePush(list_t* queue, double value);

double stackPop(list_t* stack);
int stackPush(list_t* stack, double value);

listElement_t* listIthElementPointer(list_t* list, size_t i);
double listAccess(list_t* list, size_t i);
int listInsert(list_t* list, double value, size_t i);
int listDelete(list_t* list, size_t i);
int listDeleteRange(list_t* list, size_t first, size_t last);
list_t* listSplit(list_t* list, size_t i);

int listConcat(list_t* list1, list_t* list2);

int listPrint(list_t* list);
list_t* listNew(void);
int listFree(list_t* list);
#endif
