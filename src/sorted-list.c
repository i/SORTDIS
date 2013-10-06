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
    free(ptr);
    ptr = t;
  }

  for (ptr = list->iters; ptr != NULL; ) {
    t = ptr->next;
    free(ptr);
    ptr = t;
  }

  free(list);
}

// FIXME: Need to do move and replace method
int SLInsert(SortedListPtr list, void *value) {
  int added = 0;
  //SortedListIteratorPtr iter;
  node new_node = create_node(value),
       ptr      = list->ll,
       prev     = NULL;

  // We're making the first node of the list
  if (list->ll == NULL) {
    list->ll = new_node;
  }

  else {
    for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
      // We're putting the rest of the list after this node
      if (list->cmp(value, ptr->val) >= 0) {

        // We're adding to the front of the list.
        if (prev == NULL) {
          new_node->next = list->ll;
          list->ll = new_node;
          added = 1;
        } else {
          new_node->next = ptr;
          prev->next = new_node;
          added = 1;
        }
        // Break because we added the node and don't need to check
        // any more nodes.
        break;
      } else {
        prev = ptr;
        continue;
      }
    }

    // If prev is null, it means it never got set.
    if (!added && prev != NULL)
      prev->next = new_node;
  }

  /* Everything from this point is for iterators */

  return 1;
}


int SLRemove(SortedListPtr list, void *newObj) {
  SortedListIteratorPtr iter;
  node ptr;
  node dummy;
  node prev = NULL;

  for (ptr = list->ll; ptr != NULL; ptr = ptr->next) {
    if (list->cmp(ptr->val, newObj) == 0) {
      if (prev == NULL) {
        list->ll = ptr->next;
        destroy_node(ptr);
      } else {
        prev->next = ptr->next;
        destroy_node(ptr);
      } break; } prev = ptr; } 

  /* gets each iterator node associated with the list */
  for (ptr = list->iters; ptr != NULL; ptr = ptr->next) {
    iter = (SortedListIteratorPtr)ptr->val;
    if (iter->curr->val == newObj) {
      dummy = create_node(NULL);
      dummy->next = iter->curr->next;
      iter->curr = dummy;
      break;
    }
    else if (iter->curr->next->val == newObj) {
      printf("whoooa\n");
      iter->curr = iter->curr->next;
      break;
    }
  }

  return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list) {
  node t;
  SortedListIteratorPtr slip;

  slip = malloc(sizeof(struct SortedListIterator));
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
  free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter) {
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
