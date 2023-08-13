#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define left(i) 2*i+1
#define right(i) 2*i+2

typedef struct {
  char name[20];
  int key;
} item;

typedef struct {
  item *v;
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
void swap (item * a, item * b) {
  item t = *a;
  *a = *b;
  *b = t;
}

PriorityQueue create (int size) {
  PriorityQueue q = malloc(sizeof(pq));
  q->size = size;
  q->n = 0;
  q->v = malloc(sizeof(item)*size);
  return q;
}

item createItem (int key) {
  item i;
  i.key = key;
  return i;
}

item extractMax (PriorityQueue q) {
  int max = 0;
  for (int j = 1; j < q->n; j += 1) {
    if (q->v[max].key < q->v[j].key)
      max = j;
  } swap (&(q->v[max]),&(q->v[q->n-1]));
  q->n -= 1;
  return q->v[q->n];
}

void insert (PriorityQueue q, item i) {
  q->v[q->n] = i;
  q->n += 1;
}

void insertTree (PriorityQueue q, item i) {
  int n = q->n;
  q->v[q->n] = i;
  while (q->v[n].key > q->v[parent(n)].key) {
    swap (&(q->v[n]), &(q->v[parent(n)]));
    n = parent(n);
  }
  q->n += 1;
}

item maxTree (PriorityQueue q) {
  item i = q->v[0];
  swap(&q->v[0], &q->v[q->n - 1]);
  q->n--;
  downHeap(q, 0);
  return i;
}

void upHeap(PriorityQueue q, int k) {
  if (k > 0 && q->v[parent(k)].key < q->v[k].key) {
    troca(&q->v[k], &q->v[parent(k)]);
    upHeap(q, parent(k));
  }
}

void changePriority (PriorityQueue q, int key, int i) {
  if (q->v[i].key < key) {
    q->v[i].key = key;
    upHeap(q,i);
  } else {
    q->v[i].key = key;
    downHeap(q,i);
  }
}

int empty (PriorityQueue q) {

}

int full (PriorityQueue q) {

}

void print (PriorityQueue q) {
  for (int i = 0; i < q->n; i +=1) {
    printf("%d ", q->v[i].key);
  } printf("\n");
}

int main () {
  PriorityQueue q = create(6);
  insert(q,createItem(2));
  insert(q,createItem(5));
  insert(q,createItem(3));
  insert(q,createItem(7));
  insert(q,createItem(1));
  print(q); printf("\n");
  insertTree(q,createItem(9));
  print(q); printf("\n");
  maxTree(q);
  print(q);
  return 0;
}