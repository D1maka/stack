#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "retainCounter.h"

LSBaseObject *LSCreateBaseObject()
{
    LSRetainCounter *retainCounter = LSCreateRetainCounter();
    LSBaseObject *newObject = malloc(sizeof(LSBaseObject));
    newObject->counter = retainCounter;

    return newObject;
}
