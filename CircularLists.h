typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

nodePointer createC(){};
nodePointer appendC(nodePointer List,int data){};
void printC(nodePointer List){};
nodePointer removeC(nodePointer List, nodePointer node){};
nodePointer JosephusProblem(nodePointer List,int N,int M){};