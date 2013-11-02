#include <stdlib.h>
#include <stdio.h>

#include "sorted-list.h"

node create_node(void *v) {
  node n = malloc(sizeof(struct node_));
  n->next = NULL;
  n->val = v;

  return n;
}

void destroy_node(node n) {
  free(n);
}

SortedListPtr SLCreate(CompareFuncT cf) {
  SortedListPtr lp = malloc(sizeof(struct SortedList));

  lp->cmp = cf;
  lp->ll  = NULL;
  lp->iters = NULL;

  return lp;
}

void SLDestroy(SortedListPtr list) {
  node ptr, t;

  for (ptr = list->ll; ptr != NULL; ) {
    t = ptr->next;
    destroy_node(ptr);
    ptr = t;
  }

  for (ptr = list->iters; ptr != NULL; ) {
    SLDestroyIterator(ptr->val);
  }

  free(list);
}

int SLInsert(SortedListPtr list, void *value) {
  node new_node = create_node(NULL);
  node ptr;

  // If list doesn't exist, return 0.
  if (list == NULL || value == NULL) {
    return 0;
  }

  // If the list is empty, this is the first node
  if (list->ll == NULL) {
    new_node->val = value;
    list->ll = new_node;
    return 1;
  }
  else {
    // Loop through the list
    for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
      // We have found what item it goes before
      if (list->cmp(value, ptr->val) >= 0) {
        new_node->next = ptr->next;
        new_node->val = ptr->val;
        ptr->val = value;
        ptr->next = new_node;
        return 1;
      }
      // Item goes at the end of the list
      if (ptr->next == NULL) {
        new_node->val = value;
        ptr->next = new_node;
        return 1;
      }
    }
  }
  return 0;
}


int SLRemove(SortedListPtr list, void *newObj) {
  /* SortedListIteratorPtr iter; */
  node ptr, iterptr, prev = NULL;
  SortedListIteratorPtr iter;

  if (list == NULL || newObj == NULL) {
    return 0;
  }

  // Go through the list to find item to delete
  for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
    // We have found the item to remove if we are
    if (list->cmp(newObj, ptr->val) == 0) {

      // Go through iters to see if anything is
      // pointing to this
      for (iterptr = list->iters; iterptr != NULL; iterptr = iterptr->next) {
        iter = iterptr->val;
        if (iter->curr == ptr) {
          iter->curr = ptr->next;
        }
      }

      // Deleteing first note
      if (prev == NULL) {
        list->ll = ptr->next;
        destroy_node(ptr);
        return 1;
      } else {
        prev->next = ptr->next;
        destroy_node(ptr);
        return 1;
      }
    }
    // Set previous to this node
    prev = ptr;
  }

  return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list) {
  node t;
  SortedListIteratorPtr slip;

  slip = malloc(sizeof(struct SortedListIterator));
  slip->sl = list;
  slip->curr = list->ll;

  // If list->iters is null, it means there are no iterators
  // associated with the list.
  if (list->iters == NULL) {
    list->iters = create_node(slip);
  } else {
    t = create_node(slip);
    t->next = list->iters;
    list->iters = t;
  }

  return slip;
}


void SLDestroyIterator(SortedListIteratorPtr iter) {
  node ptr, prev = NULL;
  SortedListIteratorPtr slip;
  SortedListPtr list = iter->sl;

  for (ptr = list->iters; ptr != NULL; ptr = ptr->next) {
    slip = ptr->val;

    //DELETE IT
    if (slip == iter) {
      if (prev == NULL) {
        list->iters = list->iters->next;
      } else {
        prev->next = ptr->next;
      }
    }
    prev = ptr;
  }

  free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter) {
  if (iter->curr == NULL)
    return NULL;

  void *return_me = iter->curr->val;
  iter->curr = iter->curr->next;
  iter->last_val_returned = return_me;

  return return_me;
}


void printList(SortedListPtr list) {
  node ptr;

  for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
    printf("%d, ", *(int*)ptr->val);
  }
  printf("\n");
}

void printListString(SortedListPtr list) {
  node ptr;

  for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
    printf("%s, ", (char*)ptr->val);
  }
  printf("\n");
}
