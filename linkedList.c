#include <stdio.h>
#include <stdlib.h>
 
//a node have data and a pointer to another node
typedef struct node {
    int data;
    struct node *next;
} node;

//just define a pointer to the first node of a list
//so we can call it as a 'list'
typedef struct node * nodePointer;
    
//to create a list, we return a NULL nodePointer
nodePointer createList() {
    return NULL;
}

//destroy a list recursively. Used to free memory
void destroyList(nodePointer *list) {
    if (*list != NULL) {
    destroyList(&(*list)->next);
    free(*list);
    *list = NULL;
    }
}

//just add a element in the top of the list
nodePointer prepend(nodePointer list, int x) {
    nodePointer newNode;
    newNode = malloc(sizeof(node)); //allocate the memory
    newNode->data = x; 
    newNode->next = list;
    return newNode;
}

//just add a element in the end of the list
nodePointer append(nodePointer list, int x) {
    //recursion here. We just always return a node
    if(list == NULL) {
      nodePointer newNode;
      newNode = malloc(sizeof(node)); // allocate the memory
      newNode->data = x;
      newNode->next = NULL;
      return newNode;
    }
    else {
      //we dont return a node here. Instead, we assign
      //the next element to the function, because, eventually,
      //a value will be returned to this node
      list->next = append(list->next, x);
      return list;
    }
}

//just remove a element 
nodePointer removeNode(nodePointer list, int x) {
    if (list == NULL)
      return NULL;
    if (list->data == x) {
      //we return the next node, jumping the actual node
      nodePointer newNode;
      newNode = malloc(sizeof(node));
      newNode = list->next;
      free(list);
      return newNode;
    }
    else {
        list->next = removeNode(list->next, x);
        return list;
    }
}

//print the list recursively
void print(nodePointer list) {
    if (list == NULL) {
        printf("end");
    } else {
        printf("%d ", list->data);
        print(list->next);
    }
}

int main(){
    nodePointer list;
    list = createList();
    list = append(list, 9);
    list = append(list, 8);
    list = append(list, 7);
    list = append(list, 6);
    list = append(list, 5);
    list = removeNode(list, 5);
    print(list);
    destroyList(&list);

}