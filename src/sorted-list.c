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

int SLInsert(SortedListPtr list, void *value) {
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
        } else {
          new_node->next = ptr;
          prev->next = new_node;
        }
        // Break because we added the node and don't need to check
        // any more nodes.
        break;
      } else {
        prev = ptr;
        continue;
      }
    }

    // If we've made it this far, we're adding new_node to the end of the list.
    // If prev is null, it means it never got set.
    if (prev != NULL)
      prev->next = new_node;
  }


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
  node head, t;
  SortedListIteratorPtr slip;

  slip = malloc(sizeof(struct SortedListIterator));
  head = create_node(NULL);

  head->next = list->ll;
  slip->head = head;
  slip->curr = head;

  // If list->iters is null, it means there are no iterators
  // associated with the list.
  if (list->iters == NULL) {
    list->iters = create_node(slip);
  } else {
    t = create_node(slip);
    t->next = list->iters;
  }

  return slip;
}


void SLDestroyIterator(SortedListIteratorPtr iter) {
  free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter) {
  node t = iter->curr;
  iter->curr = iter->curr->next;

  if (t->val == NULL) {
    free(t);
  }

  iter->last_val_returned = iter->curr->val;
  return iter->curr->val;
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
