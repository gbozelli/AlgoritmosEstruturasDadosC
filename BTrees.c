#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
  int n;
  int page;
  int key[MAX];
  struct node *child[MAX+1];
} tree, *Btree;

void insert (Btree r, int key) {
  int t;
  if (r->n == 2*t-1) {
    Btree s = malloc(sizeof(tree));
    s->child[1] = r;
    split(s,1);
    insertNull(s,key);
  } else
    insertNull(r,key);
}

void insertNull (Btree r, int key) {
  int n = r->n;
  
}

void split (Btree x, int i) {
  Btree y = x->child[i];
  int m = y->n / 2;
  int new_key = y->key[m];
  x->key[x->n] = new_key;
}

void remoove () {

}

Btree search (Btree r, int key) {
  int i = 0;
  while (r->key[i] < key && i < r->n) {
    i += 1;
  } 
  if (i <= r->n && key == r->key) {
    r->page = i;
    return r;
  }
  else 
    search (r->child[i], key);
}

int main () {
  return 0;
}
 