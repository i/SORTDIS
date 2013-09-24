#include <stdlib.h>

#include "sorted-list.h"

node create_node(data v) {
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


int SLInsert(SortedListPtr list, void *newObj) {
  node ptr = list->ll;

  if (ptr == NULL) {
    list->ll = create_node(value);
  }
  else
  {
    for (; ptr != NULL; ptr = ptr->next) 
    {
//TODO
    }
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

