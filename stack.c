#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

LSStack *LSStackCreate()
{
  LSStack *stack = malloc(sizeof(Stack));
  LSRetainCounter *retainCounter = LSCreateRetainCounter();
  LSBaseObject *base = (LSBaseObject*) stack;
  base->counter = retainCounter;
  
  return stack;
}

int LSIsEmpty(LSStack *self)
{
  LSStack *stack = self;
  LSRetain(stack);
  if(!self) {
    LSRelease(stack);
    return 1;
  } else if(!stack->top) {
    LSRelease(stack);
    return 1;
  } else {
    LSRelease(stack);
    return 0;
  }
}

void LSPush(LSStack *self, LSBaseObject *anything)
{
  LSStack *stack = self;
  LSRetain(stack);
  
  LSNode *node = LSNodeCreate(anything);
  
  node->next = stack->top;
  
  stack->top = node;
  LSRelease(stack);
}

LSBaseObject *LSPop(LSStack *self)
{
  LSStack *stack = self;
  LSRetain(stack);
  LSNode *node = stack->top;
  LSRetain(node);
  
  stack->top = node->next;
  LSRelease(stack);
  LSRelease(node);
  
  return node->value;
}

LSBaseObject *LSPeek(LSStack *self)
{
  LSStack *stack = self;
  LSRetain(stack);
  LSNode *node = stack->top;
  LSRetain(node);
  
  LSRelease(stack);
  LSRelease(node);

  return node->value;
}
