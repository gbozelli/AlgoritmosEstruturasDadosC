#include <stdio.h>
#include <stdlib.h>

enum color {red,black};

typedef enum color color;

typedef struct node{
  color color;
  struct node *left;
  struct node *right;
  int key;
}node;

typedef struct node * tree;

int red (tree t) {
  if (t == NULL){
    return 0;
  }
  return t->color = red;
}

int black (tree t) {
  if (t == NULL){
    return 1;
  }
  return t->color = black;
}

tree rotationToLeft (tree t) {
  tree x = t->right;
  t->right = t->left;
  x->left = t;
  x->color = t->color;
  t->color = red;
}

tree rotationToRight (tree t) {
  tree x = t->left;
  t->left = t->right;
  x->right = t;
  x->color = t->color;
  t->color = red;
}

void upRed (tree t) {
  t->color = red;
  t->left->color, t->right->color = black; 
}

tree insert (tree t, int key) {
  tree new;
  if (t==NULL) {
    new = malloc(sizeof(node));
    new->key = key;
    new->color = red;
    new->left = new->right = NULL;
  } if (key > t->key) {
    new->right = insert(t->right,key);
  } else {
    new->left = insert(t->left,key);
  } if (t->color == red && t->left->color == red) {
    t = rotationToRight(t);
  } if (t->left->color == red && t->right->color == red) {
    upRed(t);
  } if (t->left->color == black && t->right->color == red) {
    t = rotationToLeft(t);
  }
  return t;
}

tree append (tree t, int key) {
  t = insert(t,key);
  t->color = black;
  return t;
}

int main () {

  return 0;
}