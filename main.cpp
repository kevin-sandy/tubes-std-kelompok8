#include "header.h"

int main() {
    bool stop;
    int pilih;
    List TextList = createList();
    Stack Undo
    Stack Redo

    for !stop {
        printf("------- Text Editor -------")
        printf(" 1. Input Text             ")
        printf(" 2. Print Text             ")
        printf(" 3. <-Kursor               ")
        printf(" 4. Kursor->               ")
        printf(" 5. Backspace              ")
        printf(" 6. Delete                 ")
        printf(" 7. Cari Kata              ")
        printf(" 8. Ubah Huruf             ")
        printf(" 9. Undo/Redo              ")
        printf(" 0. Exit Program           ")
        printf("---------------------------")

        cout << "Pilih menu yang diinginkan: ";
        cin >> pilih;

        if (pilih == 1) {
            input_text();
        } else if (pilih == 2) {
            print_text();
        } else if (pilih == 3) {
            kursor_kiri();
        } else if (pilih == 4) {
            kursor_kanan();
        } else if (pilih == 5) {
            hapus_backspace();
        } else if (pilih == 6) {
            hapus_delete();
        } else if (pilih == 7) {
            cari_kata();
        } else if (pilih == 8) {
            ubah_huruf();
        } else if (pilih == 9) {
            undo_redo();
        }

        stop = pilih == 0 // pilih 0, maka exit program
    }
    printText(TextList);
}
