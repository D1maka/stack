#ifndef _baseObject_h
#define _baseObject_h
#include "retainCounter.h"
typedef struct
{
  LSRetainCounter *counter;
} LSBaseObject;

LSBaseObject *LSCreateBaseObject();
#endif
