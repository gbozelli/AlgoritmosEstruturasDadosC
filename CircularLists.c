#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

nodePointer NullCircular(){
    nodePointer head = malloc(sizeof(node)),
    new = malloc(sizeof(node));
    head->next = new;
    new->data = 0;
    new->next = new;
    return new;
}

nodePointer append(nodePointer List,int data){
    nodePointer new = malloc(sizeof(node));
    new->data = data;
    new->next = List;
    List->next = new;
    return List;
}

nodePointer remoove(nodePointer List,int data){
    nodePointer *first = malloc(sizeof(node));
    nodePointer *new = malloc(sizeof(node));
    first = List; new = List->next;
    while(new!=first){
        if((*new)->data==data){
            free(new)
            
        }
    }
}

int main(){
    nodePointer List = NullCircular();
    printf("%d",List->data);
    List = append(List,9);
    printf("%d",List->next->data);
    List = remoove(List,9);
    printf("%d",List->next->data);
    return 0;
}