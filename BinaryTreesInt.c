#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node *left;
  struct node *right;
  int n;
}node;

typedef struct node * tree;

void merge(int arr[], int left, int mid, int right){
    const int len = right-left;
    int i = left;int j = mid+1;int k=left;int arr_aux[len];
    for(int i=left;i<=right;i++){
        arr_aux[i] = arr[i];
    }i=left;
    while(i<=mid && j<=right){
        if(arr_aux[i]<=arr_aux[j]){
            arr[k] = arr_aux[i];
            i++;
        }else{
            arr[k] = arr_aux[j];
            j++;}
    k++;}
    while(i<=mid){arr[k]=arr_aux[i];i++; k++;}
    while(j<=right){arr[k]=arr_aux[j];j++; k++;}
}

void merge_sort(int arr[], int left, int right){
    if(right<=left){
        return;
    }else{
        int mid = (right+left)/2;
        merge_sort(arr,left,mid);
        merge_sort,(arr,mid+1,right);
        merge(arr,left,mid,right);}
}

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
  } if (t->n == a) {
    return 1;
  } else {
    check(t->left,a);
    check(t->right,a);
  }
}

void print (tree t) {
  printf("%c",t->n);
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
  t->n = p;
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

void fill (tree t, int v[], int i) { 
  if (t != NULL) {
    v[i] = t->n;
    preorder(t->left);
    preorder(t->right);
  }
}

int minmax (tree t) {
  int min, max;
  const int n = numberNodes(t);
  int v[n];
  fill (t,v,0);
  merge_sort(v,0,n);
  min = v[n];max = v[0];
  return min, max;
}

int main () {
  tree t = create();
  t = append(t,0);
  t->left = append(t->left,2);
  t->right = append(t->right,6);
  t->left->left = append(t->left->left,1);
  t->left->right = append(t->left->right,9);
  t->right->right = append(t->right->right,4);
  t->right->right->right = append(t->right->right->right,5);
  preorder(t);printf("\n");
  postorder(t);printf("\n");
  desorder(t);printf("\n");
  printf("%d nodes\n",numberNodes(t));
  printf("High = %d \n",high(t)+1);
  int min, max = minmax(t);
  printf("%d, %d", min, max);
  return 0;
}