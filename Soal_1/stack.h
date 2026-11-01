#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_STACK = 10;

struct Stack {
    int info[MAX_STACK + 1];
    int Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif