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
};

nodePointer copyList(nodePointer List){
    nodePointer copy;
    nodePointer current = malloc(sizeof(node));
    for(current=List;current!=NULL;current=current->next){
        copy = malloc(sizeof(node));
        copy->data = current->data;
        copy = copy->next;
    }
    return copy;
};

nodePointer appendList(nodePointer List, int data){
    nodePointer new = (nodePointer)malloc(sizeof(node));
    new->data = data;
    new->next = List;
    return new;
};

nodePointer pushList(nodePointer List, int data){
    nodePointer new = (nodePointer)malloc(sizeof(node)),
    sub = (nodePointer)malloc(sizeof(node));
    new = List;
    while(new!=NULL){
        new=new->next;
    }
    new = malloc(sizeof(node));
    new->next = malloc(sizeof(node));
    new->next->data = data;
    new->next->next = NULL;
    return List;
};

int searchItem(nodePointer List, int item){
    nodePointer current = malloc(sizeof(node));
    int i = 0;
    for(current = List;current!=NULL;current=current->next){
        if(current->data == item){
            return i;
        }
        i++;
    }
    return -1;
};

nodePointer invertList(nodePointer List){
    nodePointer current = malloc(sizeof(node)), 
    Current = createList();
    int i = 0; int a;
    for(current = List;current!=NULL;current=current->next){
        i++;
    }a=i;
    current = List;
    for(int k=a;k>0;k--){
        Current = appendList(Current, current->data);
        current = current->next;
    }
    return Current;
};

void printList(nodePointer List){
    nodePointer current = malloc(sizeof(node));
    printf("[");
    for(current = List;current!=NULL;current=current->next){
        printf("%d ", current->data);
    }
    printf("]\n");
};

int main(){
    nodePointer List = createList();
    for(int i = 0;i<9;i++){
        List = appendList(List, i);
    }
    List = invertList(List);
    printList(List);
    List = pushList(List,9);
    printList(List);
    return 0;
}