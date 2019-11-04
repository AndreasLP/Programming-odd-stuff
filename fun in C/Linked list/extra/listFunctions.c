#include "headerSort.h"
#include "headerCommands.h"

#define control if(list==NULL){printf("Error\n");return 5;};

list_t* listNew(void){
  list_t *new = (list_t*)malloc(sizeof(*new));
  if(new==NULL){
    printf("Failed to create new list\n");
    return NULL;
  }
  new->first=NULL;
  new->last=NULL;
  new->length=0;
  return new;
};

int listFree(list_t* list){
  control
  if(list->length==0){
    free(list);
    return 0;
  }
  else{
    listElement_t *current = list->first, *next=current->next;
    while (current!=NULL) {
      next = current->next;
      free(current);
      current = next;
    }
    free(list);
  }
  return 0;
};

listElement_t* listIthElementPointer(list_t* list, size_t i){
  if(list==NULL){printf("Error indexing list\n"); return NULL;}
  if(i<0 || i>list->length){printf("Error indexing list\n"); return NULL;};


  listElement_t *current = NULL;
  if(i<(int)(list->length)/2){
    current = list->first;
    for (size_t counter = 0; counter < i; counter++) {
      if(current->next==NULL){printf("Error occured while indexing\n");return NULL;}
      // printf("test1\n");
      current = current->next;
    };
  }
  else{
    current = list->last;
    for (size_t counter = list->length; counter > i+1; counter--) {
      if(current->previous==NULL){printf("Error occured while indexing\n");return NULL;}
      // printf("test. Value: %lf\n",current->val);
      current = current->previous;
    };
  };
  return current;
};

double listAccess(list_t* list, size_t i){
  if(list==NULL){printf("Error\n");return NAN;};
  if(i>list->length){
    printf("Asked for element after list range. Last element given");
    return list->last->val;
  }
  else if(i<0){
    printf("Asked for element before list range. First element given");
    return list->first->val;
  }

  listElement_t *current = listIthElementPointer(list, i);

  return current->val;
};

int listInsert(list_t* list,double value, size_t i){
  control
  if(list->length==0){
    listElement_t *new = (listElement_t*)malloc(sizeof(*new));
    if(new==NULL)
      return -1;
    new->val=value;
    new->next=NULL;
    new->previous=NULL;
    list->first=new;
    list->last=new;
    list->length++;
    return 0;
  }

  if(list->length<=i){
    // printf("malloc\n");
    listElement_t *new = (listElement_t*)malloc(sizeof(*new));
    if(new==NULL)
      return 1;
    (list->last)->next=new;
    new->val=value;
    new->next=NULL;
    new->previous=list->last;
    list->last=new;
    list->length++;
    return 0;
  }
  else{
    listElement_t *current = listIthElementPointer(list, i), *new = NULL;

    new = (listElement_t*)malloc(sizeof(*new));
    if(new==NULL)
      return 3;
    new->val = value;
    new->previous = current->previous;
    new->next = current;
    if(current->previous==NULL)
      list->first = new;
    else
      (current->previous)->next = new;

    current->previous = new;

    list->length++;
    return 0;
  }
};

int listDelete(list_t* list, size_t i){
  control
  listElement_t *tmp=NULL;
  if(i>=list->length){
    if(i>list->length)
      printf("Asked for element after list range. Last element deleted");
    ((list->last)->previous)->next = NULL;
    tmp = (list->last)->previous;
    free(list->last);
    list->length--;

    list->last = tmp;
    return 0;
  }
  else if(i<0){
    printf("Asked for element before list range. First element deleted");
    ((list->first)->next)->previous = NULL;
    tmp = (list->first)->next;
    free(list->first);
    list->length--;

    list->first = tmp;
    return 0;
  }

  tmp=listIthElementPointer(list, i);
  if(i>0)
    tmp->previous->next = tmp->next;
  else
    list->first = tmp->next;

  if(i < list->length-1)
    tmp->next->previous = tmp->previous;
  else
    list->last = tmp->previous;

  free(tmp);
  list->length--;
  return 0;
};

int listDeleteRange(list_t* list, size_t first, size_t last){
  // Excluding the last element
  control
  if(first<0 || last>list->length){
    printf("Range error");
    return -1;
  }

  for (size_t i = first; i < last; i++) {
    listDelete(list, first);
  }

  return 0;
};

list_t* listSplit(list_t* list, size_t count){
  // i'th element is the new last element in the original list. Count is elements kept in the first list

  if(list==NULL || count > list->length){printf("Error in split");return NULL;};


  list_t* new = (list_t*)malloc(sizeof(list_t*));

  if(count==0){
    memcpy(new,list,sizeof(list_t));

    list->first = NULL;
    list->last = NULL;
    list->length = 0;
  }
  else if(count>=list->length){
    new->first = NULL;
    new->last = NULL;
    new->length = 0;
  }
  else{
    size_t i = count - 1;
    listElement_t *tmp=listIthElementPointer(list, i);
    new->first = tmp->next;
    new->last = list->last;
    new->length = list->length - (i+1);
    list->last = tmp;
    list->length = i+1;

    (tmp->next)->previous = NULL;
    tmp->next = NULL;
  }

  return new;
};

int listConcat(list_t* list1, list_t* list2){
  if(list1 == NULL || list2 == NULL){printf("Error in concat\n");return -1;};

  if(list1->length == 0)
    memcpy(list1,list2,sizeof(list_t));
  else if(list2->length!=0){
    (list1->last)->next = list2->first;
    (list2->first)->previous = list1->last;
    list1->last = list2->last;
    list1->length += list2->length;

    free(list2);
  }

  return 0;
};

int listPrint(list_t* list){
  control
  if(list->length==0){
    printf("The list is empty.\n");
    return 0;
  };
  listElement_t *current = list->first;
  printf("Count %zu. Values in the list:\n",list->length);
  for (size_t i = 0; i < list->length; i++) {
    printf("%lf%s",current->val,i==list->length-1?"\n":" ");
    current = current->next;
  }
  return 0;
};
