#ifndef __STACK_H__
#define __STACK_H__

#include "definitions.h"

struct _Stack {
    int *stack;
    int top;
    int maxSize;
};

typedef struct _Stack Stack;

/* Sluzi za postavljanje steka na odgovarajucu velicinu */
void stackInit(Stack *stack, int size);

/* Prakticno destruktor, sluzi da oslobodimo memoriju nakon
   sto zavrsimo sa stekom */
void stackDestroy(Stack *stack);

/* Osnovne operacije sa stekom */
void push(Stack *stack, int element);

int pop(Stack *stack);

int peek(Stack *stack);

BOOL isEmpty(Stack *stack);

#endif