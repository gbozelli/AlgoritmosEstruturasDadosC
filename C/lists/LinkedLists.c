#include <stdio.h>
#include <stdlib.h>
#include "linkedLists.h"

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

nodePointer createL(){
    return NULL;
}

nodePointer deleteL(nodePointer List){
    nodePointer current = malloc(sizeof(node)), 
    aux = malloc(sizeof(node));
    current = List;
    while(current!=NULL){
        current = current->next;
        aux = current;
        free(List);
        List = aux;
    }
    return List;
}

nodePointer appendL(nodePointer List, int data){
    nodePointer new = (nodePointer)malloc(sizeof(node));
    new->data = data;
    new->next = List;
    return new;
}

int searchL(nodePointer List, int item){
    nodePointer current = malloc(sizeof(node));
    int i = 0;
    for(current = List;current!=NULL;current=current->next){
        if(current->data == item){
            return i;
        }
        i++;
    }
    return -1;
}

nodePointer invertL(nodePointer List){
    nodePointer current = malloc(sizeof(node)), 
    Current = createL();
    int i = 0, a;
    for(current = List;current!=NULL;current=current->next){
        i++;
    }a=i;
    current = List;
    for(int k=a;k>0;k--){
        Current = appendL(Current,current->data);
        current = current->next;
    }
    return Current;
}

void pushL(nodePointer *List, int data){
    nodePointer new = malloc(sizeof(node));
    nodePointer sub = malloc(sizeof(node));
    sub->data = data;
    sub->next = NULL;
    new = *List;
    while(new->next!=NULL){
        new=new->next;
    }
    new->next = sub;
}

void printL(nodePointer List){
    nodePointer current = malloc(sizeof(node));
    printf("[");
    for(current = List;current!=NULL;current=current->next){
        printf("%d ", current->data);
    }
    printf("]\n");
}

