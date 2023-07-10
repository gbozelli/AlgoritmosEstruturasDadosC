#include <stdio.h>
#include <stdlib.h>

typedef struct queues{
    int data;
    int top;
    struct queues *next;
} queues;

typedef struct queues * queuesP;

queuesP createQueue(){
    return NULL;
}

queuesP dequeue(queuesP List){
    queuesP current = malloc(sizeof(queues)), 
    aux = malloc(sizeof(queues));
    current = List;
    current = current->next;
    aux = current;
    List = aux;
    return List;
}

queuesP enqueue(queuesP List, int data){
    queuesP new = (queuesP)malloc(sizeof(queues));
    new->data = data;
    new->next = List;
    return new;
}

void printQueue(queuesP List){
    queuesP current = malloc(sizeof(queues));
    printf("[");
    for(current = List;current!=NULL;current=current->next){
        printf("%d ", current->data);
    }
    printf("]\n");
}

int main(void){
  queuesP q = createQueue(4);
  q=enqueue(q,9);
  printQueue(q);
  q=enqueue(q,8);
  printQueue(q);
  q=enqueue(q,7);
  printQueue(q);
  q=dequeue(q);
  printQueue(q);

}