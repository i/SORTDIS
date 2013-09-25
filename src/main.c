/*
 *  * sorted-list.c
 *   */

#include <stdio.h>
#include <string.h>

#include "sorted-list.h"

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
  SortedListPtr list = SLCreate(compareInts);

  int a = 12;
  int b = 1;
  int c = 31;
  int d = 15;
  int e = 83;
  int f = -138;
  int g = 1;


  SLInsert(list, &a);
  SLInsert(list, &b);
  SLInsert(list, &c);
  SLInsert(list, &d);
  SLInsert(list, &e);
  SLInsert(list, &f);
  SLInsert(list, &g);

  printList(list);


  SLDestroy(list);

  return 0;
}

