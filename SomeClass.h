#ifndef SOMECLASS_H_INCLUDED
#define SOMECLASS_H_INCLUDED
#include "retainCounter.h"

typedef struct
{
    LSRetainCounter *counter;
    int value;
} LSSomeClass;

LSSomeClass *LSCreateSomeClass(int val);

#endif
