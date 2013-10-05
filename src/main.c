/*
 *  * sorted-list.c
 *   */

#include <stdio.h>
#include <string.h>

#include "sorted-list.h"
#include "test.h"

int compareInts(void *p1, void *p2)
{
  int i1 = *(int*)p1;
  int i2 = *(int*)p2;

  return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
  double d1 = *(double*)p1;
  double d2 = *(double*)p2;

  return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
  char *s1 = p1;
  char *s2 = p2;

  return strcmp(s1, s2);
}

int main(int argc, char **argv) {
  int i1,i2,i3,i4;
  /* double d1, d2, d3, d4, d5; */
  /* char *s1, *s2, *s3, *s4; */

  SortedListPtr sl;
  SortedListIteratorPtr slip;

  sl = SLCreate(compareInts);

  i1 = 7;
  i2 = 5;
  i3 = 3;
  i4 = 7;

  SLInsert(sl, &i1);
  SLInsert(sl, &i2);
  SLInsert(sl, &i3);
  SLInsert(sl, &i4);
  slip = SLCreateIterator(sl);

  printf("%i\n", *(int*)SLNextItem(slip));
  printf("%i\n", *(int*)SLNextItem(slip));
  SLRemove(sl, &i2);
  printf("%i\n", *(int*)SLNextItem(slip));

  SLDestroyIterator(slip);
  SLDestroy(sl);

  return 0;
}
