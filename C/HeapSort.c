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

typedef pq * Heap;

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

void downHeap(int v[], int size, int k) {
  int current;
  if (left(k) < size) {
    current = left(k);
    if (right(k) < size && v[left(k)] < v[right(k)])
      current = right(k);
    if (v[k] < v[current]) {
      swap(&v[k], &v[current]);
      downHeap(v, size, current);
    }
  }
}

void heapSort (int v[], int size) {
  for (int k = size/2; k >= 0; k -= 1)
    downHeap(v,size,k);
  while (size>1) {
    swap(&v[size-1], &v[0]);
    size -= 1;
    downHeap(v,size,0);
  }
}

void print (int v[], int size) {
  for (int i = 0; i < size; i += 1)
    printf("%d ", v[i]);
}

void upHeap (int v[], int n) {
  while (v[n] > v[parent(n)]) {
    swap (&(v[n]), &(v[parent(n)]));
    n = parent(n);
  }
}

int main () {
  int v[] = {1,7,5,3,9,8,2,4,6,0};
  heapSort(v,10);
  print(v,10);
}