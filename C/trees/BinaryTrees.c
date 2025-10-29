#include <stdio.h>
#include <stdlib.h>

typedef struct node{ // definition of node
  struct node *left; // each node have two childrens
  struct node *right;
  char word;
} node;

// we will use a pointer, because the list point to a node
typedef struct node *tree;

// just return NULL to create the node
tree create () {
  return NULL;
}

//return the size of a tree
//calculated recursively
int size (tree t) {
  if(t==NULL){
    return 0;
  } else {
    return 1 + size(t->left) + size(t->right);
  }
}

//check if a tree have the char
//recursively again
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

//just print the char of a node
void print (tree t) {
  printf("%c",t->word);
}

void preorder(tree t) {
  if (t != NULL)
  {
    print(t);           // first, we acess the node
    preorder(t->left);  // then we go to the left node, and do the same thing
    preorder(t->right); // finally, we go to the right node
  }
}

void inorder(tree t) {
  if (t != NULL)
  {
    inorder(t->left);  // first, we go to the left node
    print(t);          // then we print the key of the node
    inorder(t->right); // finally, we go to the right node
  }
}

void postorder (tree t) {
  if (t!=NULL){
    postorder(t->left);  //first, we go to the left node
    postorder(t->right); //we go to the right node
    print(t);           //finally, we print the content
  }
}

//assign a char to a tree
tree assign (tree t,char p) {
  t = malloc(sizeof(node));
  t->left = NULL;
  t->right = NULL;
  t->word = p;
  return t;
}

//very similar to function 'size'
int numberNodes (tree t) {
  if (t!=NULL) {
    return 1 + numberNodes(t->left) + numberNodes(t->right);
  }
}

//calculate how high a tree is
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

//mirror a tree recursively
tree mirror (tree t) {
  if (t!=NULL) {
    tree sub = create();
    sub = assign(sub,t->word);
    sub->left = mirror(t->right);
    sub->right = mirror(t->left);
    return sub;
  }
}

//just copy a tree
tree copy (tree t) {
  if (t!=NULL) {
    tree sub = create();
    sub = assign(sub,t->word);
    sub->left = copy(t->left);
    sub->right = copy(t->right);
    return sub;
  }
}

//calculate the number of leaves in a tree
int numberLeaves (tree t) {
  if (t==NULL) return 0;
  else if (t->left == NULL && t->right == NULL){
    return 1;
  } else {
    return numberLeaves (t->left) + numberLeaves (t->right);
  }
}

//check if two trees is equal
int equal (tree t, tree s) { 
  if (t != NULL && s != NULL && t->word==s->word)
    return 1 + equal(t->left,s->left) + equal(t->right,s->right);
  else return 0;
} 

int main () {
  tree t = create();
  t = assign(t,'a');
  t->left = assign(t->left,'b');
  t->right = assign(t->right,'c');
  t->left->left = assign(t->left->left,'d');
  t->left->right = assign(t->left->right,'e');
  t->right->right = assign(t->right->right,'f');
  t->right->right->right = assign(t->right->right->right,'g');
  preorder(t);printf("\n");
  postorder(t);printf("\n");
  inorder(t);printf("\n");
  printf("%d nodes\n",numberNodes(t));
  printf("High = %d \n",high(t)+1);
  printf("%d leaves\n",numberLeaves(t));
  tree m = copy(t);
  preorder(m);printf("\n");
  printf("%d leaves\n",equal(t,m));
  return 0;
}