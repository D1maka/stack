#ifndef _node_h
#define _node_h
#include "baseObject.h"

typedef struct
{
  LSRetainCounter *counter;
  LSBaseObject *value;
  LSBaseObject *next;
} LSNode;

LSNode *LSNodeCreate(LSBaseObject *anything);
void LSDestroyNode(LSNode *self);

#endif
