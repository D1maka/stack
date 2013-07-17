#include "retainCounter.h"

/*void *Create(size_t size, deallocate func)
{ 
  RetainCounter *retainCounter = malloc(sizeof(RetainCounter));
  retainCounter->retainCount = 1;
  retainCounter->Deallocate = func;
  void *valuePtr = calloc(1, size);
  BaseObject *base = (BaseObject *) valuePtr;
  base->counter = retainCounter;

  return valuePtr;
}*/

void Retain(void *ptr)
{  
  BaseObject *base = (BaseObject *) ptr;
  bace->counter->retainCount++;
}

void Release(void *ptr)
{  
  BaseObject *base = (BaseObject *) ptr;
  bace->counter->retainCount--;
  
  if(base->counter->retainCount == 0)
  {
    if(!base->counter->Deallocate){
      base->counter->Deallocate(ptr);
    }
    //free();
  }
}