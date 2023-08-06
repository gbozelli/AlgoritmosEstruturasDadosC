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

tree mirror (tree t) {
  if (t!=NULL) {
    tree sub = create();
    sub = append(sub,t->word);
    sub->left = mirror(t->right);
    sub->right = mirror(t->left);
    return sub;
  }
}

tree copy (tree t) {
  if (t!=NULL) {
    tree sub = create();
    sub = append(sub,t->word);
    sub->left = mirror(t->left);
    sub->right = mirror(t->right);
    return sub;
  }
}

int numberLeaves (tree t) {
  if (t==NULL) return 0;
  else if (t->left == NULL && t->right == NULL){
    return 1;
  } else {
    return numberLeaves (t->left) + numberLeaves (t->right);
  }
}

int equal (tree t, tree s) { 
  if (t != NULL && s != NULL && t->word==s->word)
    return 1 + equal(t->left,s->left) + equal(t->right,s->right);
  else return 0;
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
  printf("%d leaves\n",numberLeaves(t));
  tree m = copy(t);
  preorder(m);printf("\n");
  printf("%d leaves\n",equal(t,m));
  return 0;
}