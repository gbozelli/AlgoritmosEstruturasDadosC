
typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node * nodePointer;

nodePointer createL(){};
nodePointer deleteL(nodePointer List){};
nodePointer appendL(nodePointer List, int data){};
int searchL(nodePointer List, int item){};
nodePointer invertL(nodePointer List){};
void pushL(nodePointer *List, int data){};
void printL(nodePointer List){};

