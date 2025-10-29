#include <stdio.h>
#include <stdlib.h>

typedef struct node{  //definition of node
  struct node *left;  //each node have two childrens
  struct node *right;
  int key;
}node;

//we will use a pointer, because the list point to a node
typedef struct node * tree; 

tree create () {
  return NULL;  //just return NULL to create the node
}

void print (tree t) {
  printf("%d ",t->key); //print the content of a node
}

void preorder (tree t) { 
  if (t != NULL) {
    print(t); //first, we acess the node
    preorder(t->left);  //then we go to the left node, and do the same thing
    preorder(t->right); //finally, we go to the right node
  }
}

void inorder(tree t) {
  if (t != NULL) {
    inorder(t->left); //first, we go to the left node
    print(t); //then we print the key of the node
    inorder(t->right); //finally, we go to the right node
  }
}

tree insert (tree t, int key) {
  t = malloc(sizeof(node)); //firstly, we need to allocate the memory of the node
  t->left = NULL; //we need to adress NULL to children nodes
  t->right = NULL;
  t->key = key; //now, we can put the content in the node
  return t;
};

//insert a value inside the tree based on binary-search algorithm
tree insertion (tree t, int key) {
  if (t == NULL)
    return insert(t, key); 
  if (key < t->key)
    //we assign a pointer to a new insertion
    //this recreate the tree recursively
    t->left = insertion(t->left, key);
  else if (key > t->key)
    //same here
    t->right = insertion(t->right, key);
  return t;
}

//search a value inside the tree based on binary-search algorithm
tree search (tree t, int key) {
  if (t==NULL || t->key == key) 
    return t;
  if (key > t->key)
    //to find values, we dont need to recreate the tree
    //just find the node with the assigned key
    search (t->right,key);
  else 
    search (t->left, key);
  
};

//find the minimun value in a tree
tree min (tree t) {
  if (t==NULL || t->left==NULL)
    return t;
  return min(t->left);
};

//find the maximun value in a tree
tree max (tree t) {
  if (t==NULL || t->right==NULL)
    return t;
  return max(t->right);
};

//return the min value of right subtree 
tree sucess (tree t) {
  if (t->right != NULL)
    return min(t->right);
  else if (t->left != NULL)
    return t->left;
  else return NULL;
};

//return the max value of left subtree 
tree predecess (tree t) {
  if (t->left != NULL)
    return max(t->left);
  else if (t->right != NULL)
    return t->right;
  else return NULL;
};

// remove a node with the associated key value
//but only for nodes with 2 children
void r(tree t)
{
  tree min = t->left;
  tree parent = t;
  while (min->left != NULL)
  {
    parent = min;
    min = min->left;
  }
  if (parent->left == min)
    parent->left = min->right;
  else
    parent->left = min->left;
  t->key = min->key;
}

//remove a node with the associated key value
tree removeNode (tree t, int key) {
  if (t==NULL)
    return NULL;
  if (key > t->key)
    t->right = removeNode(t->right,key);
  else if (key < t-> key)
    t->left = removeNode(t->left,key);
  else if (t->left == NULL)
    return t->right;
  else if (t->right == NULL)
    return t->left;
  else 
    r(t);
  return t;
};

//ordenate a binary search tree
tree ordenationBinarySearchTree (tree t) {
  if (t != NULL)
  {
    tree current = min(t);
    print(current);
    t = removeNode(t, current->key);
    return ordenationBinarySearchTree(t);
  }
  return NULL;
}

int main() {
  tree t = create();
  t = insertion(t, 8);
  t = insertion(t, 4);
  t = insertion(t, 9);
  t = insertion(t, 3);
  t = insertion(t, 5);
  t = insertion(t, 11);
  t = insertion(t, 13);

  t = ordenationBinarySearchTree(t); 
  inorder(t);              

  return 0;
}
