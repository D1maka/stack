#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

void *NodeCreate(size_t size, void *anything)
{
  Node *node = malloc(sizeof(Node));
  node->value = calloc(1, size);
  memcpy(node->value, anything, size);

  return node;
}

void DestroyNode(void *self)
{
  Node *node = self;
  
  if(self) {
    if(node->value) free(node->value);
    if(node->next) free(node->next);
    free(self);
  }
}
