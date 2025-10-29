#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define left(i) 2*i+1
#define right(i) 2*i+2

typedef struct {
  int *v;
  int n;
  int size;
} pq;

typedef pq * PriorityQueue;

int parent(int i) {
  if (i > 2)
    return (i+1)/2;
  else
    return 0;
}
void swap (int * a, int * b) {
  int t = *a;
  *a = *b;
  *b = t;
}

PriorityQueue create (int size) {
  PriorityQueue q = malloc(sizeof(pq));
  q->size = size;
  q->n = 0;
  q->v = malloc(sizeof(int)*size);
  return q;
}

int extractMax (PriorityQueue q) {
  int max = 0;
  for (int j = 1; j < q->n; j += 1) {
    if (q->v[max] < q->v[j])
      max = j;
  } swap (&(q->v[max]),&(q->v[q->n-1]));
  q->n -= 1;
  return q->v[q->n];
}

void insert (PriorityQueue q, int i) {
  q->v[q->n] = i;
  q->n += 1;
}

void queueSort (int v[], int size) {
  PriorityQueue q = create(size);
  for (int i = 0; i < size; i += 1)
    insert(q,v[i]);
  for (int i = size-1; i >= 0; i -= 1)
    v[i] = extractMax(q);
}

void print (int v[], int size) {
  for (int i = 0; i < size; i += 1)
    printf("%d ", v[i]);
}

int main () {
  int v[] = {1,7,5,3,9,8,2,4,6,0};
  queueSort(v,10);
  print(v,10);
}