#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

nodePointer createList(){
    return NULL;
};

void deleteList(nodePointer List){
    while(List!=NULL){
        free(List);
        List = List->next;
    }
};

nodePointer appendList(nodePointer List, int data){
    nodePointer new = (nodePointer)malloc(sizeof(node));
    new->data = data;
    new->next = List;
    return new;
};

void printList(nodePointer List){
    nodePointer current;
    for(current = List;current!=NULL;current=current->next){
        printf("%d, ", current->data);
    }
};

int main(){
    nodePointer List = createList();
    List = appendList(List,9);
    printList(List);
    deleteList(List);
    return 0;
}