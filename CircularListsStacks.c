//CircularListStacks.c

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct node *nodePointer;

typedef struct stacks *stack;

struct stacks
{
  nodePointer top;
};

void push(stack s, int v)
{
  nodePointer new = malloc(sizeof(node));
  new->data = v;
  if (s->top == NULL) {
    new->next = s->top;
    s->top = new;
  }
  else{
    new->next = s->top;
    s->top = new;
  }
}

int pop(stack s)
{
  int v = s->top->data;
  s->top = s->top->next;
  return v;
}