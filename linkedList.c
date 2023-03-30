#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;
    nodePointer createList() {
    return NULL;
}

void destroyList(nodePointer list) {
    if (list != NULL) {
    destroyList(list->next);
    free(list);
    list = NULL;
    }
}

nodePointer addElement(nodePointer list, int x) {
    nodePointer newNode;
    newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->next = list;
    return newNode;
}

void print(nodePointer list) {
    nodePointer atual;
    for (atual = list; atual != NULL; atual = atual->next)
    printf("%d\n", atual->data);
}

int main(){
    nodePointer list;
    list = createList();
    list = addElement(list, 9);
    print(list);
    destroyList(list);
    print(list);
}