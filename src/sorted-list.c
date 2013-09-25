#include <stdlib.h>
#include <stdio.h>

#include "sorted-list.h"

node create_node(void *v) {
  node n = malloc(sizeof(struct node_));
  n->next = NULL;
  n->prev = NULL;
  n->val = v;

  return n;
}

SortedListPtr SLCreate(CompareFuncT cf) {
  SortedListPtr lp = malloc(sizeof(struct SortedList));

  lp->cmp = cf;
  lp->ll  = NULL;

  return lp;
}

void SLDestroy(SortedListPtr list) {
  free(list);
}


int SLInsert(SortedListPtr list, void *value) {
  node new_node = create_node(value),
       ptr      = list->ll,
       prev     = NULL;;

  printf("inserting %d\n", *(int*)value);

  if (list->ll == NULL) {
    printf("inserting %d into new list\n", *(int*)value);//
    list->ll = new_node;
  }
  else {
    for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
      if ( list->cmp(value, ptr->val) <= 0) {
        if (prev == NULL)
        {
          new_node->next = ptr;
          list->ll = new_node;
        } else {
          new_node->next = ptr;
          prev->next = new_node;
        }
        return 1;
      } else {
        prev = ptr;
        continue;
      }
    }
    prev->next = new_node;
  }

  return 1;
}


int SLRemove(SortedListPtr list, void *newObj) {

  return 0;
}


SortedListIteratorPtr SLCreateIterator(SortedListPtr list) {

  return NULL;
}


void SLDestroyIterator(SortedListIteratorPtr iter) {

}


void *SLNextItem(SortedListIteratorPtr iter) {

  return NULL;
}

void printList(SortedListPtr list) {
  node ptr;

  for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
    printf("%d\n", *(int*)ptr->val);
  }
}
