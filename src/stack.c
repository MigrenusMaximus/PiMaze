#include "stack.h"

/* Koristi se za malloc i free */
#include <stdlib.h>

void stackInit(Stack *stack, int size) {
    stack->maxSize = size;
    stack->top = -1;
    stack->stack = (int*) malloc(stack->maxSize * sizeof(int));
}

void stackDestroy(Stack *stack) {
    /* Oslobadjamo memoriju zauzetu stekom */
    free(stack->stack);
}

void push(Stack *stack, int element) {
    /* Pomjeramo pokazivac na vrh */
    stack->top += 1;
    
    /* Ako nam je stek pun, povecavamo ga */
    if (stack->top >= stack->maxSize) {
        int* temp = (int*) malloc(stack->maxSize * 1.5 * sizeof(int));
        
        for (int i = 0; i < stack->maxSize; i++)
            temp[i] = stack->stack[i];
            
        free(stack->stack);
        stack->stack = temp;
        stack->maxSize *= 1.5;
    }
    
    /* Na kraju dodajemo novi element na vrh steka */
    stack->stack[stack->top] = element;
}

int pop(Stack *stack) {
    /* Ako je stek prazan, vracamo -1 */
    if (stack->top < 0)
        return -1;
    /* Spustamo se za jedno mjesto nize */
    stack->top -= 1;
    /* Vracamo element s vrha */
    return stack->stack[stack->top + 1];
}

int peek(Stack *stack) {
    /* Ako je stek prazan, vracamo -1 */
    if (stack->top < 0)
        return -1;
    /* Vracamo element s vrha, ali ne umanjujemo SP */
    return stack->stack[stack->top];
}

BOOL isEmpty(Stack *stack) {
    if (stack->top == -1)
        return TRUE;
    
    return FALSE;
}