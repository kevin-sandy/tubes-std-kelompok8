#include "header.h"

void deleteLast(list &L, adr &P) { //delete elemen L.first
  P = L.last;
  if (L.first == Nil) { //list kosong
    cout << "List kosong." << endl;
  } else if (L.first == L.last) { //list memiliki satu elemen
    L.first = Nil;
    L.last = Nil;
  } else { //list memiliki lebih dari satu elemen
    L.last = P->prev;
    L.last->next = Nil;
    P->prev = Nil;
  }
}

void deleteAfter(list &L, adr Pred, adr &P) { //delete elemen setelah Pred
  P = Pred->next
  if (P->next == Nil) { //tidak ada elemen setelah P
    L.last = Pred;
    P->prev = Nil;
    Pred->next = Nil;
  } else if (P->next != Nil) { //ada elemen setelah P
    Pred->next = P->next;
    P->next->prev = Pred;
    P->next = Nil;
    P->prev = Nil;
  } else if (P == Nil) {
    cout << "Tidak ada elemen setelah cursor" << endl;
  }
}
