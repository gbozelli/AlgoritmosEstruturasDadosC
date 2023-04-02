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
    printList(List);
    printf("%d\n", searchItem(List, 5));
    nodePointer inverse = createList();
    inverse = invertList(List);
    printList(inverse);
    nodePointer c1 = createList();
    c1 = copyList(List);
    c1 = invertList(List);
    printList(c1);
    return 0;
}