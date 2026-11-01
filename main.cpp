#include "stack.h"

int main() {
    Stack S;
    createStack(S);

    int pilihan, x;

    do {
        cout << "\n===== MENU STACK (POINTER) =====" << endl;
        cout << "1. Tambah Terurut" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihan)) {
            break;                  // input habis / tidak valid
        }

        switch (pilihan) {
        case 1:
            cout << "Masukkan bilangan: ";
            cin >> x;
            pushAscending(S, x);
            cout << x << " berhasil ditambahkan secara terurut." << endl;
            break;
        case 2:
            if (pop(S, x)) {
                cout << "Nilai yang di-pop: " << x << endl;
            } else {
                cout << "Stack kosong! Pop ditolak." << endl;
            }
            break;
        case 3:
            printInfo(S);
            break;
        case 4:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    clearStack(S);                  // bebaskan semua node sebelum berakhir
    return 0;
}