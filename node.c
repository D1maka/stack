#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

void *NodeCreate(size_t size, void *anything, deallocate func)
{
  Node *node = malloc(sizeof(Node));
  RetainCounter *retainCounter = malloc(sizeof(RetainCounter));
  retainCounter->retainCount = 1;
  retainCounter->Deallocate = func;
  node->value = calloc(1, size);
  memcpy(node->value, anything, size);
  BaseObject *base = (BaseObject*) node;
  base->counter = retainCounter;
  Retain(node->value);

  return node;
}

void DestroyNode(void *self)
{
  Node *node = self;
  
  if(self) {
    if(node->value){ 
      Release(node->value);
    } 
    if(node->next){
      Release(node->next);
    }
    Release(self);
  }
}
