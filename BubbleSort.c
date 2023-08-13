#include <stdio.h>
#include <stdlib.h>

void swap (int * a, int * b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort (int v[], int size) {
  for (int i = 0; i < size; i += 1) 
    for (int j = size-1; j > i; j -= 1) 
      if (v[j] < v[i]) 
        swap(&v[i],&v[j]);
}

void print (int v[], int size) {
  for (int i = 0; i < size; i += 1)
    printf("%d ", v[i]);
}

int main () {
  int v[] = {1,7,5,3,9,8,2,4,6,0};
  bubbleSort(v,10);
  print(v,10);
}