#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

struct node {
    int value;
    struct node* next;
};

struct stack {
    Node* last;
    int size;
};

Stack* create() {
    Node* node = (Node*) malloc(sizeof(Node));
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    node->next = NULL;
    stack->last = node;
    stack->size = 0;

    return stack;
}

void push(Stack* stack, int value) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->value = value;
    new->next = stack->last;
    stack->last = new;
    stack->size++;
}

void pop(Stack* stack){
    if(stack->size == 0){
        printf("Stack is empty\n");
        return;
    }
    Node* current = stack->last;
    stack->last = current->next;
    free(current);
    stack->size--;
}

bool isEmpty(Stack* stack){
    bool empty;
    if(stack->size == 0){
        empty = true;
        printf("Stack is empty\n");
    } else {
        empty = false;
        printf("Stack is not empty\n");
    }
    return empty;
}

void freeStack(Stack* stack){
    while (stack->size > 0) {
        pop(stack);
    }
}

void printStack(Stack* stack){
    Node* last = stack->last;

    while(last->next != NULL){
        printf("%d\n", last->value);
        last = last->next;
    }
}

int main(){
    Stack* stack = create();
    isEmpty(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printStack(stack);
    pop(stack);
    printStack(stack);
    isEmpty(stack);
    freeStack(stack);
    isEmpty(stack);
}