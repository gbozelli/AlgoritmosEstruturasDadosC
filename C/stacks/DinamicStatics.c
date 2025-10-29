#include <stdio.h>
#include <stdlib.h>
//comment i
typedef struct stack{
    int data;
    int top;
    struct stack *next;
} stack;

typedef struct stack * stackP;

stackP createL(){
    return NULL;
}

stackP pop(stackP List){
    stackP current = malloc(sizeof(stack)), 
    aux = malloc(sizeof(stack));
    current = List;
        current = current->next;
        aux = current;
        free(List);
        List = aux;
    return List;
}

stackP push(stackP List, int data){
    stackP new = (stackP)malloc(sizeof(stack));
    new->data = data;
    new->next = List;
    return new;
}

void printL(stackP List){
    stackP current = malloc(sizeof(stack));
    printf("[");
    for(current = List;current!=NULL;current=current->next){
        printf("%d ", current->data);
    }
    printf("]\n");
}

int main(void){
  stackP head = createL();
  head = push(head,1);
  head = push(head,3);
  head = pop(head);
  printL(head);
}