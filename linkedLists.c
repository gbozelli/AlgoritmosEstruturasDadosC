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
    int i = 0, a;
    for(current = List;current!=NULL;current=current->next){
        i++;
    }a=i;
    current = List;
    for(int k=a;k>0;k--){
        Current = appendList(Current,current->data);
        current = current->next;
    }
    return Current;
};

nodePointer copyList(nodePointer List){
    nodePointer copy;
    if (List == NULL){
        return NULL;
    }
    copy = malloc(sizeof(node));
    copy->data = List->data;
    copy->next = copyList(List->next);
    return copy;
};

void pushList(nodePointer *List, int data){
    nodePointer new = malloc(sizeof(node));
    nodePointer sub = malloc(sizeof(node));
    sub->data = data;
    sub->next = NULL;
    new = *List;
    while(new->next!=NULL){
        new=new->next;
    }
    new->next = sub;
};

nodePointer unionLists(nodePointer List1, nodePointer List2){
    nodePointer copy;
    nodePointer current = malloc(sizeof(node));
    for(current=List1;current!=NULL;current=current->next){
        copy = malloc(sizeof(node));
        copy->data = current->data;
        copy = copy->next;
        if(current->next==NULL){
            copy = malloc(sizeof(node));
            copy = List2;
        }
    }
    return copy;
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
    nodePointer ListA = createList();
    nodePointer ListB = createList();
    for(int i = 0;i<9;i++){
        List = appendList(List, i);
    }
    List = invertList(List);
    printList(List);
    pushList(&List,9);
    printList(List);
    ListA = copyList(List);
    printList(ListA);
    pushList(&ListA,10);
    printList(List);
    return 0;
}