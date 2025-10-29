#include <stdio.h>
#define MAX 100
//{} []

void swap (int * a, int * b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void quickSort (int v[], int l, int r) {
  if (l >= r) return;
  int i = partition(v,l,r);
  quickSort(v,l,i-1);
  quickSort(v,i+1,r);
}

int partition (int v[], int l, int r) {
  int pivot = v[l];
  int position = r + 1;
  for (int i = r; i >= l; i -= 1) {
    if (v[i] >= pivot) {
      swap(&v[i], &v[position]);
      position -= 1;
    } 
  }
  return position;
}

int main () {

}