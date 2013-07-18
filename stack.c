#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void *StackCreate(Deallocate func)
{
  Stack *stack = malloc(sizeof(Stack));
  RetainCounter *retainCounter = malloc(sizeof(RetainCounter));
  retainCounter->retainCount = 1;
  retainCounter->Deallocate = func;
  BaseObject *base = (BaseObject*) stack;
  base->counter = retainCounter;
  
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

void Push(void *self, size_t size, void *anything, deallocate func)
{
  Stack *stack = self;
  Node *node = NodeCreate(size, anything, func);
  Release(stack->top);
  node->next = stack->top;
  Retain(node->next);
  stack->top = node;
}

void *Pop(void *self)
{
  Stack *stack = self;
  Node *node = stack->top;
  Release(stack->top);
  stack->top = node->next;
  Retain(node->next);
  Release(node);
  
  return node->value;
}

void *Peek(void *self)
{
  Stack *stack = self;
  Node *node = stack->top;

  return node->value;
}
