#include <stdlib.h>

#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf) {
  SortedListPtr list = malloc(sizeof(SortedList));
  list->cmp = cf;


  return list;
}

void SLDestroy(SortedListPtr list) {
  free(list->list);

  return;
}


int SLInsert(SortedListPtr list, void *newObj) {

  return 0;
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
