#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int start;
  int end;
  int size;
  int *v;
}queues;

typedef queues * queue;

queue createQueue (int size){
  queue queue = malloc(sizeof(queues));
  queue->size = size;
  queue->v = malloc(sizeof(int)*size);
  queue->start = 0;
  queue->v[queue->start] = 0;
  queue->end = 0;
  return queue;
}

void empty () {

}

void enqueue (queue queue, int value) {
  queue->end = (queue->end+1)%queue->size;
  queue->v[queue->end] = value;
}

void dequeue (queue q) {
  q->start = (q->start+1)%q->size;
}

void peek () {

}

void printQueue (queue q) {
  printf("|");
  for(int i = q->start; i <= q->end; i += 1)
    printf("%d|",q->v[i]);
  printf("\n");
}

int main () {
  queue q = createQueue(4);
  enqueue(q,9);
  printQueue(q);
  enqueue(q,9);
  printQueue(q);
  enqueue(q,9);
  printQueue(q);
}