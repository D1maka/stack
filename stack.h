#ifndef _stack_h
#define _sstack_h

#include "node.h"

typedef struct
{
  void *top;
  
  void (*push)(void *self,  size_t size, void *anything);
  void *(*pop)(void *self);
  void *(*peek)(void *self);
  int (*is_empty)(void *self);
} Stack;

void stack_push(void *self, size_t size, void *anything);
void *stack_pop(void *self);
void *stack_peek(void *self);
int stack_is_empty(void *self);

void *stack_create();
#endif
