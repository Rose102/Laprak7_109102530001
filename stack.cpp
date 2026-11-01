#include "stack.h"

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

address alokasi(int x) {
    address P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

/* tambah elemen pada TOP */
void push(Stack &S, int x) {
    address P = alokasi(x);
    P->next = S.Top;
    S.Top = P;
}

/* ambil nilai TOP dan lepas node; false jika kosong (stack tidak berubah) */
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    address P = S.Top;
    x = P->info;
    S.Top = P->next;
    P->next = nullptr;
    dealokasi(P);
    return true;
}

/* tampil mulai dari TOP */
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP:";
    address P = S.Top;
    while (P != nullptr) {
        cout << " " << P->info;
        P = P->next;
    }
    cout << endl;
}

/*
 * Sisip terurut: urutan menaik dari bawah ke TOP (terbesar di TOP).
 * Memakai satu stack bantu lewat push dan pop saja:
 *   1. selama TOP > x, pindahkan TOP ke stack bantu
 *   2. push x
 *   3. kembalikan semua elemen dari stack bantu ke stack utama
 * Duplikat disimpan sebagai elemen terpisah. Stack bantu kembali kosong.
 */
void pushAscending(Stack &S, int x) {
    Stack Bantu;
    createStack(Bantu);

    int tmp;
    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, tmp);
        push(Bantu, tmp);
    }

    push(S, x);

    while (!isEmpty(Bantu)) {
        pop(Bantu, tmp);
        push(S, tmp);
    }
}

/* lepas seluruh node, Top kembali nullptr */
void clearStack(Stack &S) {
    int tmp;
    while (pop(S, tmp)) {
        // terus pop sampai kosong
    }
    S.Top = nullptr;
}