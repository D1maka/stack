#ifndef _stack_h
#define _sstack_h

#include "node.h"

typedef struct
{
  LSRetainCounter *counter;
  LSNode *top;
} LSStack;

void LSPush(LSStack *self, LSBaseObject *anything);
LSBaseObject *LSPop(LSStack *self);
LSBaseObject *LSPeek(LSStack *self);
int LSIsEmpty(LSStack *self);

LSStack *LSStackCreate();
#endif
