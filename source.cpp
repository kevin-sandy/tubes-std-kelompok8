#include "header.h"

// Stack
Stack createStack() {
// Mengembalikan stack yang berisi S.top = 0
    Stack S;
    S.top = 0;

    return S;
}

bool isEmpty(Stack S) {
// Mengembalikan nilai true jika nilai S.top == 0, dan false jika S.top != 0
    return S.top == 0;
}

bool isFull(Stack S) {
// Mengembalikan nilai true jika nilai S.top == MAXSIZE, dan false jika S.top != MAXSIZE
    return S.top == MAXSIZE;
}

void push(Stack &S, infoUndoRedo i) {
/*
I.S: Stack S berisi nilai untuk operasi undo/redo (bisa tidak berisi), dan infoUndoRedo i yang berisi nilai untuk dimasukkan ke Stack S
F.S: Stack S berisi nilai baru
*/
    if (!isFull(S)) {
        S.top++;
        S.info[S.top-1] = i;
    }
}

void pop(Stack &S, infoUndoRedo i) {
/*
I.S: Stack S berisi nilai untuk operasi undo/redo (bisa tidak berisi), dan infoUndoRedo i yang akan diisi nilai dari Stack S
F.S: infoUndoRedo i berisi nilai dari Stack S
*/
    if (!isEmpty(S)) {
        i = S.info[S.top-1];
        S.top--;
    }
}

infoUndoRedo peek(Stack S) {
// Mengembalikan nilai infoUndoRedo i dari S.top Stack S
    infoUndoRedo i;

    if (!isEmpty(S)) {
        i.aksi = S.info[S.top].aksi;
        i.karakter = S.info[S.top].karakter;
    }

    return i;
}

// DLL
void createList(List &L, adr &Cursor) {
/*


*/
    L.first = Nil;
    L.last = Nil;
    Cursor = L.first;
}

adr createElmList(infotype value) {
    adr P = new elmList;
    P->prev = Nil;
    P->next = Nil;
    P->info = value;

    return P;
}

void insertFirst(List &L, adr &P){
    if (L.first == Nil) { // list kosong
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(List &L, adr &P, adr Prec){
    if (Prec == Nil) {
        insertFirst(L, P);
    } else if (Prec == L.last) {
        P->prev = Prec;
        Prec->next = P;
        L.last = P;
    } else { // 2 elemen setelah Prec
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

void insertBefore(List &L, adr &P, adr Pred){
    if (Pred == Nil) { // tidak ada elemen sebelum Pred
        insertFirst(L, P);
    } else if (Pred == L.first) {
        P->next = Pred;
        Pred->prev = P;
        L.first = P;
    } else { // 2 elemen sebelum Pred
        P->prev = Pred->prev;
        P->next = Pred;
        Pred->prev->next = P;
        Pred->prev = P;
    }
}

void insertLast(List &L, adr &P){
    if (L.last == Nil) { // list kosong
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirst(List &L, adr &P) {
    P = L.first;
    if (L.first == L.last) { // hanya 1 elemen
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteAfter(List &L, adr &P, adr Pred){
    P = Pred->next;
    if (Pred->next == L.last) {
        deleteLast(L, P);
    } else if (Pred->next->next != Nil) { // 2 elemen setelah Pred
        P = Pred->next;
        Pred->next = P->next;
        (P->next)->prev = Pred;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteBefore(List &L, adr &P, adr Pred) {
    P = Pred->prev;
    if (Pred->prev == L.first) {
        deleteFirst(L, P);
    } else if (Pred->prev->prev != Nil) { // 2 elemen setelah Pred
        P = Pred->prev;
        Pred->prev = P->prev;
        P->prev->next = Pred;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteLast(List &L, adr &P) { // hanya 1 elemen
    P = L.last;
    if (L.first == L.last){
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = P->prev;
        P->prev = Nil;
        L.last->next = Nil;
    }
}

void printText(List L) {
    adr P = L.first;
    while (P != Nil) {
        if (P->info == '_') {
            cout << " ";
        } else {
            cout << P->info;
        }
        P = P->next;
    }
    cout << endl;
}

void printTextWithCursor(List L, adr C) {
    adr P = L.first;
    while (P != Nil) {
        if (P == C) {
            cout << "[" << P->info << "]"; // Penanda kursor
        } else if (P->info == '_') {
            cout << " ";
        } else {
            cout << P->info;
        }
        P = P->next;
    }
    cout << endl;
}

void addText(List &L, adr &C) {
    adr P;
    infotype v;
    do {
        cin >> v;
        if (v != ';') {
            P = createElmList(v);
            insertAfter(L, P, C);
            C = P;
        }
    } while (v != ';');
}

void moveCursorLeft(List &L, adr &C) {
    if (C != L.first) { // kursor tidak di first
        C = C->prev;
    }
}

void moveCursorRight(List &L, adr &C) {
    if (C != L.last) { // kursor tidak di last
        C = C->next;
    }
}

void Backspace(List &L, adr &C) {
    adr P;
    if (C != L.first) {
        deleteBefore(L, P, C);
        delete P;
    }
}

void Delete(List &L, adr &C){
    adr P;
    if (C != L.last) {
        deleteAfter(L, P, C);
        delete P;
    }
}

// Menu
void input_text(List &L, adr &C) {
    cout << "Text: " << endl; printTextWithCursor(L, C);
    cout << "Ketik text yang ingin dimasukkan: " << endl;
    addText(L, C);

    cout << "Text: " << endl; printText(L); cout << endl;
}

void print_text(List L) {
    if (L.first == Nil) {
        cout << "Text tidak tersedia." << endl;
    } else {
        cout << "Text: " << endl; printText(L); cout << endl;
    }
}

void pindahkan_kursor(List L, adr &C) {
    int pilih;

    if (L.first != Nil) {
        do {
            printTextWithCursor(L, C);
            cout << "(1)Kiri (2)Kanan (0)Keluar" << endl;
            cin >> pilih;

            if (pilih == 1) {
                moveCursorLeft(L, C);
            } else if (pilih == 2) {
                moveCursorRight(L, C);
            }
        } while (pilih != 0);
    } else {
        cout << "Teks tidak tersedia." << endl;
    }
}

void hapus_teks(List &L, adr &C) {
    int pilih;

    if (L.first != Nil) {
        do {
            printTextWithCursor(L, C);
            cout << "(1)Kiri (2)Kanan (3)Delete (4)Backspace (0)Keluar" << endl;
            cin >> pilih;

            if (pilih == 1) {
                moveCursorLeft(L, C);
            } else if (pilih == 2) {
                moveCursorRight(L, C);
            } else if (pilih == 3) {
                Delete(L, C);
            } else if (pilih == 4) {
                Backspace(L, C);
            }
        } while (pilih != 0);
    } else {
        cout << "Teks tidak tersedia." << endl;
    }
}

void cari_kata(List L) {
    bool status = false;
    adr first = Nil, last = Nil;
    adr P;
    string X, kata;

    if (L.first != Nil) {
        cout << "Kata yang ingin dicari: ";
        cin >> X;

        P = L.first;
        while (P != Nil && !status) {
            kata = "";
            first = P;
            while (P != Nil && P->info != '_') {
                kata += P->info;
                last = P;
                P = P->next;
            }
            status = kata == X;

            if (!status && P != Nil) {
                P = P->next; // Lanjutkan pencarian setelah karakter '_'
            }
        }

        if (status) {
            cout << "Kata ditemukan: " << endl;
            adr R = L.first;
            while (R != Nil) {
                if (R == first) {
                    cout << "[" << R->info;
                } else if (R == last) {
                    cout << R->info << "]";
                } else if (R->info == '_') {
                    cout << " ";
                } else {
                    cout << R->info;
                }
                R = R->next;
            }
            cout << endl;
        } else {
            cout << "Kata tidak ditemukan." << endl;
        }
    } else {
        cout << "Teks tidak tersedia." << endl;
    }
}
