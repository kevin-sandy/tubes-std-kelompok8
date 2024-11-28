#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define Nil NULL
#include <iostream>

using namespace std;

//array undo/redo
const int MAXSIZE = 1000;
typedef int index;

struct stack {
  index top;
  adr info[MAXSIZE]
};

//DLL text editor
typedef struct elmList *adr;
typedef string infotype;

struct elmList {
  infotype info;
  adr prev, next;
};
struct list {
  adr first, last;
};

#endif // HEADER_H_INCLUDED
