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

void deleteItem(nodePointer List){
    nodePointer newnode = malloc(sizeof(node));
    newnode = List->next;
    free(List);
    List = newnode;
};

void deleteList(nodePointer List){
    nodePointer current = List;
    while(current!=NULL){
        current = current->next;
        deleteItem(List);
        break;
    }
}

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

void removeItem(nodePointer List, int item){
    nodePointer current;
    for(current = List;current!=NULL;current=current->next){
        if(current->data == item){
            List=current;
            deleteItem(List);
            break;
        }
    }
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
    removeItem(List,9);
    printList(List);
    return 0;
}