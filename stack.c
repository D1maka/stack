#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

LSStack *LSStackCreate()
{
  LSStack *newStack = malloc(sizeof(LSStack));
  LSRetainCounter *retainCounter = LSCreateRetainCounter();
  LSBaseObject *base = (LSBaseObject*) newStack;
  base->counter = retainCounter;

  return newStack;
}

int LSIsEmpty(LSStack *self)
{
  LSStack *currentStack = self;
  LSRetain(currentStack);
  if(!self) {
    LSRelease(currentStack);
    return 1;
  } else if(!currentStack->top) {
    LSRelease(currentStack);
    return 1;
  } else {
    LSRelease(currentStack);
    return 0;
  }
}

void LSPush(LSStack *self, LSBaseObject *anything)
{
  LSStack *currentStack = self;
  LSRetain(currentStack);

  LSNode *node = LSNodeCreate(anything);

  node->next = (LSBaseObject*) currentStack->top;

  currentStack->top = node;
  LSRelease(currentStack);
}

LSBaseObject *LSPop(LSStack *self)
{
  LSStack *currentStack = self;
  LSRetain(currentStack);
  LSNode *node = currentStack->top;
  LSRetain(node);

  currentStack->top =  (LSNode *) node->next;
  LSRelease(currentStack);
  LSRelease(node);

  return node->value;
}

LSBaseObject *LSPeek(LSStack *self)
{
  LSStack *currentStack = self;
  LSRetain(currentStack);
  LSNode *node = currentStack->top;
  LSRetain(node);

  LSRelease(currentStack);
  LSRelease(node);

  return node->value;
}
