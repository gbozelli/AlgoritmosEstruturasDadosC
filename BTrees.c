#include <stdio.h>
#include <stdlib.h>

#define T 100 // Minimum degree (defines the range for number of keys)

// Structure for a B-tree node
typedef struct BTreeNode {
  int n;                             // Current number of keys
  int keys[2 * T - 1];               // Keys in the node (max 2*T-1)
  struct BTreeNode *children[2 * T]; // Child pointers (max 2*T children)
  int leaf;                          // Is true when node is leaf. Otherwise false
} BTreeNode;

// Function to create a new B-tree node
BTreeNode *createNode(int leaf){
  BTreeNode *node = malloc(sizeof(BTreeNode));
  node->n = 0;
  node->leaf = leaf;
  for (int i = 0; i < 2 * T; i++){
    node->children[i] = NULL;
  }
  return node;
}

// Function to traverse and print the B-tree (inorder)
void traverse(BTreeNode *root){
  if (root != NULL)
  {
    int i;
    for (i = 0; i < root->n; i++){
      // If this is not leaf, before printing key[i], traverse the subtree children[i]
      if (!root->leaf)
        traverse(root->children[i]);
      printf("%d ", root->keys[i]);
    }
    // Print the subtree rooted with last child
    if (!root->leaf)
      traverse(root->children[i]);
  }
}

// Function to search a key in B-tree
BTreeNode *search(BTreeNode *root, int key, int *pos){
  int i = 0;
  // Find the first key greater than or equal to key
  while (i < root->n && key > root->keys[i])
    i++;
  // If found key equals to key, return this node and position
  if (i < root->n && root->keys[i] == key){
    if (pos)
      *pos = i;
    return root;
  }
  // If this is leaf node, key not found
  if (root->leaf)
    return NULL;
  // Go to the appropriate child
  return search(root->children[i], key, pos);
}

// Splits the child y of node x at index i
void splitChild(BTreeNode *x, int i, BTreeNode *y){
  // Create a new node z which will store T-1 keys of y
  BTreeNode *z = createNode(y->leaf);
  z->n = T - 1;
  // Copy last T-1 keys of y to z
  for (int j = 0; j < T - 1; j++){
    z->keys[j] = y->keys[j + T];
  }
  // Copy the last T children of y to z if y is not leaf
  if (!y->leaf){
    for (int j = 0; j < T; j++)
    {
      z->children[j] = y->children[j + T];
    }
  }
  // Reduce the number of keys in y
  y->n = T - 1;
  // Create space for new child in x
  for (int j = x->n; j >= i + 1; j--){
    x->children[j + 1] = x->children[j];
  }
  // Link new child to x
  x->children[i + 1] = z;
  // Move keys in x to create space for median key from y
  for (int j = x->n - 1; j >= i; j--){
    x->keys[j + 1] = x->keys[j];
  }
  // Copy the middle key of y to x
  x->keys[i] = y->keys[T - 1];
  // Increment count of keys in x
  x->n += 1;
}

// Insert a key into a non-full node
void insertNonFull(BTreeNode *x, int key){
  int i = x->n - 1;
  if (x->leaf){
    // Insert the new key into the correct position in the leaf node
    while (i >= 0 && x->keys[i] > key){
      x->keys[i + 1] = x->keys[i];
      i--;
    }
    x->keys[i + 1] = key;
    x->n += 1;
  }else{
    // Find the child which is going to have the new key
    while (i >= 0 && x->keys[i] > key){
      i--;
    }
    i++; // Child index to descend
    // If the child is full, split it
    if (x->children[i]->n == 2 * T - 1){
      splitChild(x, i, x->children[i]);
      // After split, the middle key moves up and x->keys[i] is the median
      if (key > x->keys[i])
      {
        i++;
      }
    }
    insertNonFull(x->children[i], key);
  }
}

// Main insert function
BTreeNode *insert(BTreeNode *root, int key){
  // If tree is empty, create root
  if (root == NULL){
    root = createNode(1);
    root->keys[0] = key;
    root->n = 1;
    return root;
  }
  // If root is full, then tree grows in height
  if (root->n == 2 * T - 1){
    BTreeNode *s = createNode(0); // New root is not leaf
    s->children[0] = root;        // Old root becomes child of new root
    splitChild(s, 0, root);       // Split old root and move median key up
    int i = 0;
    if (s->keys[0] < key){
      i++;
    }
    insertNonFull(s->children[i], key);
    return s; // New root
  }else{
    insertNonFull(root, key);
    return root;
  }
}

// Main function to demonstrate insertion and traversal
int main(){
  BTreeNode *root = NULL;

  // Insert keys
  int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
  int n = sizeof(keys) / sizeof(keys[0]);

  for (int i = 0; i < n; i++)
    root = insert(root, keys[i]);
  printf("Traversal of the constructed B-tree:\n");
  traverse(root);
  printf("\n");
  // Search for a key
  int key_to_search = 6;
  int pos;
  BTreeNode *found = search(root, key_to_search, &pos);
  if (found != NULL){
    printf("Key %d found in node at index %d.\n", key_to_search, pos);
  }else{
    printf("Key %d not found in the B-tree.\n", key_to_search);
  }
  return 0;
}
