#include "extra/headerSort.h"
#include "extra/headerCommands.h"
#define tests 10

int main(int argc, char const *argv[]) {
  // fprintf(stdout,"Hello World\n");
  list_t *list = listNew();
  for (size_t i = 0; i < tests; i++) {
    listInsert(list, (double)i, i);
  }

  listPrint(list);
  fprintf(stdout,"Sorted: %d\n",listSorted(list));

  listFree(list);
  return 0;
}
