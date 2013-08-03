#ifndef _node_h
#define _node_h
#include "retainCounter.h"

typedef struct
{
  RetainCounter *counter;
  LSBaseObject *value;
  LSBaseObject *next; 
} LSNode;

LSNode *LSNodeCreate(LSBaseObject *anything);
void LSDestroyNode(LSNode *self);

#endif
