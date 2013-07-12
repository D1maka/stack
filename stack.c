#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void *StackCreate()
{
  Stack *stack = malloc(sizeof(Stack));

  return stack;
}

int IsEmpty(void *self)
{
  Stack *stack = self;
  if(!self) {
    return 1;
  } else if(!stack->top) {
    return 1;
  } else {
    return 0;
  }
}

void Push(void *self, size_t size, void *anything)
{
  Stack *stack = self;
  Node *node = NodeCreate(size, anything);
  node->next = stack->top;
  stack->top = node;
}

void *Pop(void *self)
{
  Stack *stack = self;
  Node *node = stack->top;
  stack->top = node->next;
  DestroyNode(node);
  return node->value;
}

void *Peek(void *self)
{
  Stack *stack = self;
  Node *node = stack->top;
  return node->value;
}
