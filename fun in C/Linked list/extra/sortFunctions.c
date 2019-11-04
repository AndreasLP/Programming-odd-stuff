#include "headerCommands.h"
#include "headerSort.h"


int listSorted(list_t *list){
  // Returns -2 if NULL pointer or invalid list, -1 if empty list, -2 if list is not sorted,
  // 1 if sorted backwards and 0 if sorted with smallest element first
  if(list==NULL || list->first==NULL || list->last==NULL){
    fprintf(stderr,"Passed NULL pointer\n");
    printFileFuncLine(stderr);
    return -2;
  }
  if(list->length==0){
    fprintf(stderr,"Passed list with length zero\n");
    printFileFuncLine(stderr);
    return -1;
  }
  if(list->length==1)
    return 0;

  listElement_t *current = list->first;
  if(current->val>=(current->next)->val){
    while (current->next!=NULL) {
      if(current->val<(current->next)->val)
        return -2;
      current = current->next;
    }
    return 1;
  }
  while (current->next!=NULL) {
    if(current->val>(current->next)->val)
      return -2;
    current = current->next;
  }


  return 0;
}
