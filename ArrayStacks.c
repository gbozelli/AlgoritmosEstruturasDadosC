#include <stdio.h>
#include <stdlib.h>

typedef struct stacks *stack;

struct stacks
{
  int top;
  int *v;
};

void push(stack s, int v) {
  s->v[s->top] = v;
  s->top++;
}

int pop(stack s)
{
  s->top--;
  return s->v[s->top];
}