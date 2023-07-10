#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node *left;
  struct node *right;
  char word;
}node;

typedef struct node * tree;

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
  return 0;
}