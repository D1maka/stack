#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

LSNode *LSNodeCreate(LSBaseObject *anything)
{
  LSNode *node = malloc(sizeof(Node));
  LSRetainCounter *retainCounter = LSCreateRetainCounter();
  node->value = anything;
  LSBaseObject *base = (LSBaseObject*) node;
  base->counter = retainCounter;

  return node;
}

void LSDestroyNode(LSNode *self)
{
  LSNode *node = self;
  
  if(self) {
    free(self);
  }
}
