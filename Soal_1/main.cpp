#include "stack.h"

int main() {
    Stack S;
    createStack(S);

    int pilihan, x;

    do {
        cout << "\n===== MENU STACK (ARRAY) =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihan)) {
            break;                  // input habis / tidak valid
        }

        switch (pilihan) {
        case 1:
            cout << "Masukkan bilangan: ";
            cin >> x;
            if (push(S, x)) {
                cout << x << " berhasil di-push." << endl;
            } else {
                cout << "Stack penuh! Push " << x << " ditolak." << endl;
            }
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
            if (isEmpty(S)) {
                cout << "Stack kosong, tidak ada yang dibalik." << endl;
            } else {
                balikStack(S);
                cout << "Stack berhasil dibalik." << endl;
                printInfo(S);
            }
            break;
        case 5:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}