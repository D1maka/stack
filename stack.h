#ifndef _stack_h
#define _sstack_h

#include "node.h"

typedef struct
{
  RetainCounter *counter;
  void *top;
} Stack;

void Push(void *self, size_t size, void *anything);
void Pop(void *self);
void Peek(void *self);
int IsEmpty(void *self);

void *StackCreate(Deallocate func);
#endif
