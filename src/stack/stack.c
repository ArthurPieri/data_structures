#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

/**
 * This is a simple implementation of a stack using a linked list.
 * The stack is a data structure that works with the LIFO (Last In First Out) principle.
**/

struct linkedList {
    int value;
    struct linkedList* next;
};

List* createList(){
    return NULL;
}

List* insertElement(List* list, int value){
    List* newElement = (List*)malloc(sizeof(list));
    newElement->value = value;
    newElement->next = list;

    return newElement;
}

bool isListEmpty(List* list){
    bool isEmpty;
    if(list == NULL){
        printf("The list is empty!\n");
        isEmpty = true;
    }else{
        printf("The list is not empty!\n");
        isEmpty = false;
    }
    
    return isEmpty;
}

void printList(List* list){
    bool isEmpty = isListEmpty(list);
    if(isEmpty){
        return;
    }
    
    List* element;
    

    for( element = list; element != NULL; element = element->next ){
        printf("%d\n", element->value);
    }
}

List* searchElement(List* list, int value){
    List* aux;
    for(aux = list; aux != NULL; aux = aux->next){
        if(aux->value == value){
            printf("The element %d was found!\n", value);
            return aux;
        }
    }

    printf("The element %d was not found!\n", value);
    return NULL;
}

List* deleteElement(List* list, int value){
    List* previous = NULL;
    List* current = list;

    while (current != NULL && current->value != value){
        previous = current;
        current = current->next;
    }

    if (current == NULL){
        return list;
    }

    if (previous == NULL){
        list = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    return list;
}

void freeList(List* list){
    List* current = list;
    while(current != NULL){
        List* next = current->next;
        current->next = NULL;
        free(current);
        current = next;
    }
    free(list);
    printf("The list has been freed!\n");
}

int main(){
    List* list = createList();
    
    isListEmpty(list);
    
    list = insertElement(list, 10);
    list = insertElement(list, 20);
    list = insertElement(list, 30);
    list = insertElement(list, 40);
    list = insertElement(list, 50);
    list = insertElement(list, 60);
    list = insertElement(list, 70);
    list = insertElement(list, 80);
    list = insertElement(list, 90);
    list = insertElement(list, 100);
    
    printList(list);
    
    isListEmpty(list);
    
    searchElement(list, 50);
    searchElement(list, 500);
    
    list = deleteElement(list, 50);
    printList(list);
    
    freeList(list);
    
    return 0;
}