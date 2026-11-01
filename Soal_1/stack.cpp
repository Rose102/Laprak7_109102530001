#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAX_STACK;
}

/* gagal (false) jika stack penuh; Top dan isi tidak berubah */
bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

/* gagal (false) jika stack kosong; Top dan isi tidak berubah */
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

/* tampil mulai dari TOP ke bawah */
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP:";
    for (int i = S.Top; i >= 1; i--) {
        cout << " " << S.info[i];
    }
    cout << endl;
}

/*
 * Membalik isi stack dengan SATU stack bantu, hanya lewat push dan pop.
 * Setiap putaran, elemen TOP dari bagian yang belum tetap dipindah ke
 * dasar bagian tersebut:
 *   1. pop TOP ke variabel v
 *   2. pindahkan (m-1) elemen di bawahnya ke stack bantu
 *   3. push v (kini v berada di bawah)
 *   4. kembalikan elemen dari stack bantu ke S
 * Setelah n-1 putaran isi stack terbalik. Duplikat dan jumlah elemen tetap.
 */
void balikStack(Stack &S) {
    Stack Bantu;
    createStack(Bantu);

    int n = S.Top;
    int v, tmp;

    for (int tetap = 0; tetap < n - 1; tetap++) {
        int m = n - tetap;          // jumlah elemen yang belum tetap

        pop(S, v);                  // ambil elemen TOP
        for (int i = 0; i < m - 1; i++) {
            pop(S, tmp);
            push(Bantu, tmp);
        }
        push(S, v);                 // v menjadi dasar bagian ini
        while (!isEmpty(Bantu)) {
            pop(Bantu, tmp);
            push(S, tmp);
        }
    }
}