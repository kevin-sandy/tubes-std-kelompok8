#include "header.h"

// Stack
Stack createStack() {
    Stack S;
    S.top = 0;

    return S;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAXSIZE;
}

void push(Stack &S, infotypeStack i) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top-1] = i;
    }
}

void pop(Stack &S, infotypeStack i) {
    if (!isEmpty(S)) {
        i = S.info[S.top-1];
        S.top--;
    }
}

infotypeStack peek(Stack S) {
    infotypeStack i;

    i.action = Nil;
    i.info = Nil;
    if (!isEmpty(S)) {
        i = S.info[S.top];
    }

    return i;
}

// DLL
List createList() {
    List L;
    L.first = createElmList('|');
    L.last = L.first;

    return L;
}

adr createElmList(infotype x) {
    adr P = new elmList;
    P->prev = Nil;
    P->next = Nil;
    P->info = x;

    return P;
}

void insertAfterCursor(List &L, adr cursor, adr &P) {
    if (cursor->next != Nil) { // setelah kursor ada elemen
        P->prev = cursor;
        P->next = cursor->next;
        cursor->next->prev = P;
        cursor->next = P;
    } else if (cursor->next == Nil) { // setelah kursor tidak ada elemen
        P->prev = cursor;
        cursor->next = P;
        L.last = P;
    }
    cout << "Karakter sudah ditambahkan." << endl;
}

void printText(List L) {
    adr P = L.first;
    while (P != Nil) {
        cout << P->info;
        P = P->next;
    }
    cout << endl;
}
