#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node *left;
  struct node *right;
  struct node *parent;
  char word;
}node;

typedef struct node * tree;

tree create () {
  return NULL;
}

int size (tree t) {
  if(t==NULL){
    return 0;
  } else {
    return 1 + size(t->left) + size(t->right);
  }
}

int check (tree t, char a) {
  if (t==NULL) {
    return 0;
  } if (t->word == a) {
    return 1;
  } else {
    check(t->left,a);
    check(t->right,a);
  }
}

void print (tree t) {
  printf("%c",t->word);
}

void preorder (tree t) { 
  if (t != NULL) {
    print(t);
    preorder(t->left);
    preorder(t->right);
  }
}

void postorder (tree t) {
  if (t!=NULL){
    preorder(t->left);
    preorder(t->right);
    print(t);
  }
}

void desorder (tree t) {
  if (t!=NULL) {
    preorder(t->left);
    print(t);
    preorder(t->right);
  }
}

tree append (tree t,char p) {
  t = malloc(sizeof(node));
  t->left = NULL;
  t->right = NULL;
  t->word = p;
  return t;
}

int numberNodes (tree t) {
  if (t!=NULL) {
    return 1 + numberNodes(t->left) + numberNodes(t->right);
  }
}

int high (tree t) {
  int hl, hr;
  if (t==NULL) {
    return -1;
  }
  hl = high(t->left);
  hr = high(t->right);
  if (hl > hr) {
    return hl+1;
  } else {
    return hr+1;
  }
}

void parents (tree t) {
  if (t->left != NULL) {
    t->left->parent = t;
    parents(t->left);
  } if (t->right != NULL) {
    t->right->parent = t;
    parents(t->right);
  }
}

int main () {
  tree t = create();
  t = append(t,'a');
  t->left = append(t->left,'b');
  t->right = append(t->right,'c');
  t->left->left = append(t->left->left,'d');
  t->left->right = append(t->left->right,'e');
  t->right->right = append(t->right->right,'f');
  t->right->right->right = append(t->right->right->right,'g');
  preorder(t);printf("\n");
  postorder(t);printf("\n");
  desorder(t);printf("\n");
  printf("%d nodes\n",numberNodes(t));
  printf("High = %d \n",high(t)+1);
  parents(t);
  return 0;
}