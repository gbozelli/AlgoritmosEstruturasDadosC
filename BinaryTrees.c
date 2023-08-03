#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node *left;
  struct node *right;
  char word;
}node;

typedef struct node * tree;

tree create () {
  return NULL;
}

void append (tree t,char a) {
  t = malloc(sizeof(node));
  t->word = a;
}

void print (tree t) {
  printf("&c",t->word);
}

void preorder (tree t) { 
  if (t!=NULL){
    print(t);
    preorder(t->left);
    preorder(t->right);
  }
}

void postorder(tree t){
  if (t!=NULL){
    preorder(t->left);
    preorder(t->right);
    print(t);
  }
}

void desorder(tree t){
  if (t!=NULL){
    preorder(t->left);
    print(t);
    preorder(t->right);
  }
}

int main(){
  tree t = create();
  t->word = 'a';
  preorder(t);
  return 0;
}