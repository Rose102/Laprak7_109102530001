#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

/* Stack berbasis singly linked list; kosong jika Top = nullptr */
struct Node {
    int info;
    Node *next;
};

typedef Node *address;

struct Stack {
    address Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
address alokasi(int x);
void dealokasi(address &P);
void push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif