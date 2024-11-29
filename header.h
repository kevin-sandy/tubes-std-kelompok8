#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define Nil NULL
#include <iostream>

using namespace std;

// Stack
const int MAXSIZE = 10000;
struct infotypeStack {
    string action;
    infotypeList info;
};
typedef int index;
struct Stack {
    infotypeStack info[MAXSIZE];
    index top;
};

Stack createStack();

bool isEmpty(Stack S);

bool isFull(Stack S);

void push(Stack &S, infotypeStack i);

void pop(Stack &S, infotypeStack i);

infotypeStack peek(Stack S);

// DLL
typedef struct elmList *adr;
typedef char infotypeList;
struct elmList {
    infotypeList info;
    adr prev, next;
};
struct List {
    adr first, last;
};

List createList();

adr createElmList(infotype x);

void insertAfterCursor(List &L, adr cursor, adr &P);

void printText(List L);

#endif // HEADER_H_INCLUDED
