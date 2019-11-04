#include "extra/headerCommands.h"

int main(void) {
  list_t* list = listNew();
  for (size_t i = 0; i < 5; i++) {
    if((queuePush(list, (double) i))==-1) return 10;
  }
  listPrint(list);
  for (size_t i = 0; i < 5; i++) {
    printf("Pop: %lf\n",queuePop(list));
  }
  listPrint(list);
  // for (size_t i = (size_t)list->length/2; i < list->length; i++) {
  //   printf("%zu. element: %lf\n", i, listAccess(list, i));
  // }
  //
  // // listDeleteRange(list, 3, 7);
  // list_t* list2 = listSplit(list, 3);
  // listPrint(list);
  // listPrint(list2);
  // listConcat(list2, list);
  // list = NULL;
  // listPrint(list2);
  //

  listFree(list);
  return 0;
}
