#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void *stack_create()
{
  Stack *stack = malloc(sizeof(Stack));
  stack->push = stack_push;
  stack->pop = stack_pop;
  stack->peek = stack_peek;
  stack->is_empty = stack_is_empty;
  return stack;
}

int stack_is_empty(void *self)
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

void stack_push(void *self, size_t size, void *anything)
{
  Stack *stack = self;
  Node *node = new_node(size, anything);
  node->next = stack->top;
  stack->top = node;
}

void *stack_pop(void *self)
{
  Stack *stack = self;
  Node *node = stack->top;
  stack->top = node->next;
  return node->value;
}

void *stack_peek(void *self)
{
  Stack *stack = self;
  Node *node = stack->top;
  return node->value;
}
