#include <stdio.h>
#include <stdlib.h>

void swap (int * a, int * b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void insertionSort (int v[], int size) {
  for (int i = 1; i < size; i += 1)
    for (int j = i; j > 0; j -= 1)
      if (v[j] < v[j-1])
        swap(&v[j],&v[j-1]);
}

void insertionSort2 (int v[], int size) {
  int i, j, t;
  for (int i = 1; i < size; i += 1){
    t = v[i];
    for (int j = i; j > 0 && t < v[j-1]; j -= 1)
      v[j] = v[j-1];
    v[j] = t;
  }
}

void print (int v[], int size) {
  for (int i = 0; i < size; i += 1)
    printf("%d ", v[i]);
}

int main () {
  int v[] = {1,7,5,3,9,8,2,4,6,0};
  insertionSort(v,10);
  print(v,10);
}