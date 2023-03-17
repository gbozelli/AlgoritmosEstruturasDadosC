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

nodePointer deleteList(nodePointer List){
    nodePointer current = List, aux;
    while(current!=NULL){
        current->next;
        aux = current;
        List = aux;
    }
    return List;
};

nodePointer appendList(nodePointer List, int data){
    nodePointer new = (nodePointer)malloc(sizeof(node));
    new->data = data;
    new->next = List;
    return new;
};

int searchItem(nodePointer List, int item){
    nodePointer current;
    int i = 0;
    for(current = List;current!=NULL;current=current->next){
        if(current->data == item){
            return i;
        }
        i++;
    }
    return -1;
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
    List = deleteList(List);
    printList(List);
    return 0;
}