typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

nodePointer createCircularLists() {};
nodePointer appendCircularLists(nodePointer List, int data) {};
void printCircularLists(nodePointer List) {};
nodePointer removeCircularNode(nodePointer List, nodePointer node){};
nodePointer JosephusProblem(nodePointer List,int N,int M){};