#include <stdio.h>
#include <stdlib.h>

//the definition of the node is the same as linked list
typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

//just create a circular list
nodePointer createCircularLists(){
    nodePointer head = NULL;
    return head;
}

//append a node in the bottom of the list
nodePointer appendCircularLists(nodePointer List,int data){
    nodePointer new = malloc(sizeof(node));
    new->data = data;
    if(List==NULL){
        //if list is null
        //the first and last node is the same
        new->next = new;
        List = new;
    }else{
        new->next = List->next;
        List->next = new;
    }
    return new;
};

//print the cirucular list iteratively
void printCircularLists(nodePointer List){
    nodePointer current = malloc(sizeof(node));
    nodePointer last = malloc(sizeof(node)); last = List->next;
    for(current=last->next;current!=last;current=current->next){
        printf("%d, ", current->data);
    }
    printf("%d", last->data);
    printf("\n");
};

//remove a node from a list
nodePointer removeCircularNode(nodePointer list, int x) {
    if (list == NULL)
        return NULL;
    nodePointer current = list->next;
    nodePointer prev = list;
    //acess the node with correspondent data iteratively
    do{
        if (current->data == x)
            break;
        prev = current;
        current = current->next;
    } while (current != list->next);
    //data doesnt exist in this list
    if (current->data != x)
        return list;
    if (current == current->next){
        free(current);
        return NULL;
    }
    //jump the node
    prev->next = current->next;
    if (current == list)
        //assign the 'removed' list
        list = prev;
    free(current);
    return list;
}

// solve the Josephus Problem given a circular list
nodePointer JosephusProblem(nodePointer List, int N, int M){
    nodePointer current = List;
    // while there's more than one node in the circle
    while (N != 1){
        // move M steps forward
        for (int i = 0; i < M; i++){
            current = current->next;
        }
        // remove the node after current 
        List = removeCircularNode(List, current->next->data);
        N -= 1;
        printCircularLists(List);
    }
    // return the last remaining node
    return List;
}

int main()
{
    nodePointer circularList = createCircularLists();
    nodePointer new = malloc(sizeof(node));
    new->data = 5;
    circularList = appendCircularLists(circularList, 1);
    circularList = appendCircularLists(circularList, 2);
    circularList = appendCircularLists(circularList, 3);
    circularList = appendCircularLists(circularList, 4);
    circularList = appendCircularLists(circularList, 5);
    printCircularLists(circularList); 
    circularList = removeCircularNode(circularList, 5);
    printCircularLists(circularList);

    return 0;
}
