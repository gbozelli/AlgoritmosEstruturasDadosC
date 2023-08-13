#include <stdio.h>
#define MAX 100

void merge(int v[], int l, int m, int r) {
  int i = l, j = m + 1, k = 0;
  int aux[MAX];
  while (i <= m && j <= r) {
    if (v[i] < v[j]) {
      aux[k] =  v[i];
      i += 1;
    } else {
      aux[k] =  v[j];
      j += 1;
    }
    k += 1;
  } while (i <= m) {
      aux[k] =  v[i];
      i += 1;
      k += 1;
  } while (j <= r) {
      aux[k] =  v[j];
      j += 1;
      k += 1;
  } for (i = l, k = 0; i <= r; i++, k++)
      v[i] = aux[k];
}

void mergeSort (int v[], int l, int r) {
  int m = (r+l)/2;
  if (l < r) {
    mergeSort(v,l,m);
    mergeSort(v,m+1,r);
    merge(v,l,m,r);
  }
}

void quickSort () {

}

void partition () {
  
}

void print (int v[], int size) {
  for (int i = 0; i < size; i += 1)
    printf("%d ", v[i]);
}

int main () {
  int v[] = {1,7,5,3,9,8,2,4,6,0};
  int r = 9, l = 0;
  mergeSort(v,l,r);
  print(v,r-l);
  return 0;
}