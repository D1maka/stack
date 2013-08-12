#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "retainCounter.h"
#include "baseObject.h"

LSRetainCounter *LSCreateRetainCounter()
{
  LSRetainCounter *retainCounter = malloc(sizeof(LSRetainCounter));
  retainCounter->retainCount = 1;

  return retainCounter;
}

void LSRetain(void *ptr)
{
  LSBaseObject *object = (LSBaseObject*) ptr;
  object->counter->retainCount++;
}

void LSRelease(void *ptr)
{
  LSBaseObject *object = (LSBaseObject*) ptr;
  object->counter->retainCount--;

  if(object->counter->retainCount == 0)
  {
      printf("\nHello from release, object has 0 counts\n\n");
    if(object->counter->Deallocate){
      object->counter->Deallocate(ptr);
    }
  }
}
