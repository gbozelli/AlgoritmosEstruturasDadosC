#include <stdio.h>
#include <stdlib.h>
#include "CircularLists.h"

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

nodePointer createC(){
    nodePointer head = malloc(sizeof(node));
    head = NULL;
    return head;
}

nodePointer appendC(nodePointer List,int data){
    nodePointer new = malloc(sizeof(node));
    new->data = data;
    if(List==NULL){
        new->next = new;
        List = new;
    }else{
        new->next = List->next;
        List->next = new;
    }
    return new;
};

void printC(nodePointer List){
    nodePointer current = malloc(sizeof(node));
    nodePointer last = malloc(sizeof(node)); last = List->next;
    for(current=last->next;current!=last;current=current->next){
        printf("%d, ", current->data);
    }
    printf("%d", last->data);
    printf("\n");
};

nodePointer removeC(nodePointer List, nodePointer node){
    nodePointer ant = malloc(sizeof(node));
    for(ant=List;ant->next!=node;ant=ant->next);
    ant->next = ant->next->next;
    if(List==node){
        List = ant;
    }free(node);
    return List;
};

nodePointer JosephusProblem(nodePointer List,int N,int M){
    nodePointer current = malloc(sizeof(node));
    nodePointer ant = malloc(sizeof(node));
    while(N!=1){
        current = List;
        for(int i=0;i<M;i+=1){
            current = current->next;
        }
        List = removeC(current,current->next);
        N -= 1;
        printC(List);
    }
    return List;
};