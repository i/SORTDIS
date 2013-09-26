#include <stdlib.h>

#include "sorted-list.h"
#include "test.h"

int intTest1() {
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


  printf("\n\nremoving %d\n", d);
  SLRemove(list, &d);
  printList(list);
  printf("removing %d\n", e);
  SLRemove(list, &e);
  printList(list);
  printf("removing %d\n", b);
  SLRemove(list, &b);
  printList(list);
  printf("removing %d\n", b);
  SLRemove(list, &b);
  printList(list);
  printf("removing %d\n", b);
  SLRemove(list, &b);
  printList(list);

  SLDestroy(list);

}

int intTest2() {

  return 1;
}

int intTest3() {

  return 1;
}

int strTest1() {

  return 1;
}

int strTest2() {

  return 1;
}

int strTest3() {

  return 1;
}
