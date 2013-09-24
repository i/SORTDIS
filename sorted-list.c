#include <stdlib.h>

#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf) {
  SortedListPtr lp = malloc(sizeof(struct SortedList));
  lp->cmp = cf;

  return lp;
}

void SLDestroy(SortedListPtr list) {
  free(list);
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
