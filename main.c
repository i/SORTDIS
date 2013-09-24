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
  char *buff = malloc(200);
  FILE *f = fopen(argv[1], "r");

  SortedListPtr list = SLCreate(compareInts);

  free(list);

  fread(buff, 1, 200, f);
  printf("%s\n", buff);
  fclose(f);



  return 0;
}
