#include "header.h"

int main() {
    List Text;
    adr Cursor;
    int pilih;

    createList(Text, Cursor);

    printf("- Text Editor Kelompok 11 -\n");
    do {
        printf(" 1. Input Text             \n");
        printf(" 2. Print Text             \n");
        printf(" 3. Pindahkan Kursor       \n");
        printf(" 4. Hapus Teks             \n");
        printf(" 5. Cari Kata              \n");
        printf(" 6. Undo/Redo              \n");
        printf(" 0. Exit Program           \n");
        printf("---------------------------\n");

        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            input_text(Text, Cursor);
        } else if (pilih == 2) {
            print_text(Text);
        } else if (pilih == 3) {
            pindahkan_kursor(Text, Cursor);
        } else if (pilih == 4) {
            hapus_teks(Text, Cursor);
        } else if (pilih == 5) {
            cari_kata(Text);
        } else if (pilih == 6) {
            //undo_redo(Text, Cursor);
        }
    } while (pilih != 0);

    return 0;
}
