#include "header.h"

void pesanDelete(bool stat) { // tampilkan ke layar apakah terjadi delete atau tidak
  if (stat) { // terjadi delete
    cout << "Elemen berhasil dihapus." << endl;
  } else { // tidak terjadi delete
    cout << "Elemen tidak ada." << endl;
  }
}

void deleteLast(list &L, adr &P) { // delete elemen L.first
  bool statusDelete; // status apakah delete atau tidak
  P = L.last;
  if (L.first == Nil) { //list kosong
    statusDelete = false;
  } else if (L.first == L.last) { // list memiliki satu elemen
    L.first = Nil;
    L.last = Nil;
    statusDelete = true;
  } else { // list memiliki lebih dari satu elemen
    L.last = P->prev;
    L.last->next = Nil;
    P->prev = Nil;
    statusDelete = true;
  }

  // pesan apakah terjadi delete atau tidak
  pesanDelete(statusDelete);
}

void deleteAfter(list &L, adr Pred, adr &P) { // delete elemen setelah Pred
  bool statusDelete; // status apakah delete atau tidak
  P = Pred->next;
  if (P == Nil) {
    statusDelete = false;
  } else if (P->next == Nil) { // tidak ada elemen setelah P
    L.last = Pred;
    P->prev = Nil;
    Pred->next = Nil;
    statusDelete = true;
  } else if (P->next != Nil) { // ada elemen setelah P
    Pred->next = P->next;
    P->next->prev = Pred;
    P->next = Nil;
    P->prev = Nil;
    statusDelete = true;
  }

  // pesan apakah terjadi delete atau tidak
  pesanDelete(statusDelete);
}

