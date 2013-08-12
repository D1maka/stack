#include "SomeClass.h"

LSSomeClass *LSCreateSomeClass(int val)
{
    LSRetainCounter *retainCounter = LSCreateRetainCounter();
    LSSomeClass *someClass = malloc(sizeof(LSSomeClass));
    someClass->counter = retainCounter;
    someClass->value = val;

    return someClass;
}
