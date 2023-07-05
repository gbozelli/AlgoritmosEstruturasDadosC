#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int top;
  int *v;
}stacks;

typedef stacks * stack;

stack createStack (int size) {
  stack stack = malloc(sizeof(stack));
  stack->v = malloc(sizeof(int)*size);
  stack->top = 0;
  stack->size = size;
  return stack;
}

void print (stack stack) {
  printf("|");
  for(int i = 0; i < stack->top; i += 1)
    printf("%d|",stack->v[i]);
}

void push (stack stack, int value) {
  if (stack->top==stack->size-1) {
      printf("The stack is filled");
  } else {
    stack->v[stack->top] = value;
    stack->top += 1;
  }
}

void pop (stack stack) {
  if (stack->top==0) {
    printf("The stack is empty");
  } else {
    
  }
}

int main(){
  stack stack = createStack (5);
  push(stack,1);
  print(stack);
  return 0;
}

