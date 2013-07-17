#ifndef _node_h
#define _node_h
#include "retainCounter.h"

typedef struct
{
  RetainCounter *counter;
  void *value;
  void *next; 
} Node;

void *NodeCreate(size_t size, void *anything, deallocate func);
void DestroyNode(void *self);

#endif
