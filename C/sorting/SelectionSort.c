#include <stdio.h>
#include <stdlib.h>

void swap (int * a, int * b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int maximum (int v[], int size) {
  int j = 0; 
  int max = size-1;
  for (j = size-1; j >= 0; j -= 1)
    if (v[j] > v[max])
      max = j;
  return max;
}

int minimum (int v[], int size) {
  int j, min;
  for (j = size+1; j < size; j += 1)
    if (v[j] < v[min])
      min = j;
  return min;
}

void selectionSort (int v[], int size) {
  int i, j, min;
  for (i = 0; i < size; i += 1) {
    min = i;
    for (j = i+1; j < size; j += 1)
      if (v[j] < v[min])
        min = j;
    swap(&v[i], &v[min]);
  }
}

void selectionSort2 (int v[], int size) {
  int i, j, max;
  for (i = size-1; i > 0; i -= 1) {
    max = i;
    for (j = i-1; j >= 0; j -= 1)
      if (v[j] > v[max])
        max = j;
    swap(&v[i], &v[max]);
  }
}

void selectionSort3 (int v[], int size) {
  int i, j, max;
  for (i = size-1; i > 0; i -= 1) {
    max = maximum(v,i);
    swap(&v[i], &v[max]);
  }
}

void selectionSort4 (int v[], int size) {
  int i, j, min;
  for (i = 0; i < size; i += 1) {
    min = minimum(v,i);
    swap(&v[i], &v[min]);
  }
}

void print (int v[], int size) {
  for (int i = 0; i < size; i += 1)
    printf("%d ", v[i]);
}

int main () {
  int v[] = {1,7,5,3,9,8,2,4,6,0};
  selectionSort(v,10);
  print(v,10);
}