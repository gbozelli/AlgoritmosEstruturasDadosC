#include <stdio.h>
#include <stdlib.h>
#include "linkedLists.h"

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * list;

list createL(){
    return NULL;
}

list deleteL(list List){
    list current = malloc(sizeof(node)), 
    aux = malloc(sizeof(node));
    current = List;
    while(current!=NULL){
        current = current->next;
        aux = current;
        free(List);
        List = aux;
    }
    return List;
}

list appendL(list List, int data){
    list new = (list)malloc(sizeof(node));
    new->data = data;
    new->next = List;
    return new;
}

int searchL(list List, int item){
    list current = malloc(sizeof(node));
    int i = 0;
    for(current = List;current!=NULL;current=current->next){
        if(current->data == item){
            return i;
        }
        i++;
    }
    return -1;
}

list invertL(list List){
    list current = malloc(sizeof(node)), 
    Current = createL();
    int i = 0, a;
    for(current = List;current!=NULL;current=current->next){
        i++;
    }a=i;
    current = List;
    for(int k=a;k>0;k--){
        Current = appendL(Current,current->data);
        current = current->next;
    }
    return Current;
}

void pushL(list *List, int data){
    list new = malloc(sizeof(node));
    list sub = malloc(sizeof(node));
    sub->data = data;
    sub->next = NULL;
    new = *List;
    while(new->next!=NULL){
        new=new->next;
    }
    new->next = sub;
}

void printL(list List){
    list current = malloc(sizeof(node));
    printf("[");
    for(current = List;current!=NULL;current=current->next){
        printf("%d ", current->data);
    }
    printf("]\n");
}

void merge(list lis, int l, int m, int r) {
  int i = l, j = m + 1;
  list aux;
  while (i <= m && j <= r) {
    if (lis->data < aux->data) {
      aux = append(lis->data);
      i += 1;
    } else {
      aux = append(lis->data);
      j += 1;
    }
  } while (i <= m) {
      aux = append(lis->data);
      i += 1;
  } while (j <= r) {
      aux = append(lis->data);
      j += 1;
  } lis = aux;
}

void mergeSort (list list, int l, int r) {
  int m = (r+l)/2;
  if (l < r) {
    mergeSort(list,l,m);
    mergeSort(list,m+1,r);
    merge(list,l,m,r);
  }
}