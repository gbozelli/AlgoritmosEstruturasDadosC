#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
//{} []

typedef struct {
  char string[10];
  int data;
  node * next;
} node;

typedef node * list;

typedef struct {
  list v[MAX];
} Hash;

typedef Hash * hash;

int hashing (char * string) {
  int i, n;
  for (int i = 0; i <= strlen(string);i += 1) {
    n = (256 * n + string[i]) % MAX;
  }
  return n;
} 

void copyString (hash h, char * string) {
  int n = hashing(string);
  for (int i = 0; i <= strlen(string); i += 1)
    h->v[i]->string[i] = string[n];
}

void insert (hash h, int data, char * string) {
  int n = hashing(string);
  h->v[n]->data = data;
  copyString(h,string);
}

void remoove (hash h, char * string) {
  int n = hashing(string);
  free(h->v[n]);
  h->v[n] = NULL;
}

int main () {
  
  return 0;
}