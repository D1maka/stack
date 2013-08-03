#include "retainCounter.h"

LSRetainCounter *LSCreateRetainCounter()
{ 
  LSRetainCounter *retainCounter = malloc(sizeof(RetainCounter));
  retainCounter->retainCount = 1;
  
  return retainCounter;
}

void LSRetain(LSBaseObject *ptr)
{  
  ptr->counter->retainCount++;
}

void LSRelease(LSBaseObject *ptr)
{  
  ptr->counter->retainCount--;
  
  if(ptr->counter->retainCount == 0)
  {
    if(!ptr->counter->Deallocate){
      ptr->counter->Deallocate(ptr);
    }
  }
}