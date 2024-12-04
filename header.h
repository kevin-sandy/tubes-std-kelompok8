#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define Nil NULL

#include <iostream>

using namespace std;

// Stack
const int MAXSIZE = 10000;
struct infoUndoRedo {
    string aksi;
    char karakter;
};
struct infotypeStack {
    string action;
    infoUndoRedo info;
};
typedef int index;
struct Stack {
    infoUndoRedo info[MAXSIZE];
    index top;
};

Stack createStack();

bool isEmpty(Stack S);

bool isFull(Stack S);

void push(Stack &S, infoUndoRedo i);

void pop(Stack &S, infoUndoRedo i);

infoUndoRedo peek(Stack S);

// DLL
typedef struct elmList *adr;
typedef char infotype;
struct elmList {
    infotype info;
    adr prev, next;
};
struct List {
    adr first, last;
};

void createList(List &L, adr &C);

adr createElmList(infotype value);

void insertFirst(List &L, adr &P);

void insertAfter(List &L, adr &P, adr prec);

void insertLast(List &L, adr &P);

void deleteFirst(List &L, adr &P);

void deleteAfter(List &L, adr &P, adr Prec);

void deleteBefore(List &L, adr &P, adr Pred);

void deleteLast(List &L, adr &P);

void printText(List L);

void printTextWithCursor(List L, adr C);

void addText(List &L, adr &C);

adr setCursor(List &L);

void moveCursorLeft(List &L, adr &C);

void moveCursorRight(List &L, adr &C);

void Backspace(List &L, adr &C);

void Delete(List &L, adr &C);

// Menu
void input_text(List &L, adr &C);

void print_text(List L);

void pindahkan_kursor(List L, adr &C);

void hapus_teks(List &L, adr &C);

void cari_kata(List L);

#endif // HEADER_H_INCLUDED
