#include "header.h"

void deleteLast(list &L, adr &P) {
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

void deleteAfter(list &L, adr Pred, adr &P) {

}
