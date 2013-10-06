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
  /* int i7,i5,i3,i4; */
  /* double d1, d2, d3, d4, d5; */
  char *s1, *s2, *s3, *s4, *s5;

  SortedListPtr sl;
  SortedListIteratorPtr slip;

  sl = SLCreate(compareInts);

  s1 = "Hello";
  s2 = "World";
  s3 = "Dawgs";
  s4 = "Tacos";
  s5 = "Zebra";

  SLInsert(sl, s1); // => ['HELLO']
  SLInsert(sl, s2); // => ['WORLD', 'HELLO']
  SLInsert(sl, s3); // => ['WORLD', 'HELLO', 'DOGS']
  SLInsert(sl, s5); // => ['ZZZ', 'WORLD', 'HELLO', 'DOGS']

  slip = SLCreateIterator(sl);

  printListString(sl);

  printf("%s\n", (char*)SLNextItem(slip));
  printf("%s\n", (char*)SLNextItem(slip));
  SLInsert(sl, s4);
  printf("%s\n", (char*)SLNextItem(slip));

  SLDestroyIterator(slip);
  SLDestroy(sl);

  return 0;
}
