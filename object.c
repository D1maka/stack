#include "object.h"

void *Alloc(size_t size, deallocate func)
{
  char *valuePtr;
  Object *obj = (Object *)calloc(sizeof(Object) + size, 1);
  obj->retainCount = 1;
  obj->Deallocate = func;
  valuePtr = (char *) obj;
  valuePtr += sizeof(Object);
  obj->value = valuePtr;

  return valuePtr;
}

void Retain(void *ptr)
{
  char *valuePtr = (char *) ptr;
  valuePtr -= sizeof(Object);
  Object *obj = (Object *)valuePtr;
  obj->retainCount++;
}

void Release(void *ptr)
{
  char *valuePtr = (char *) ptr;
  valuePtr -= sizeof(Object);
  Object *obj = (Object *)valuePtr;
  obj->retainCount--;
  
  if(obj->retainCount == 0)
  {
    if(!obj->Deallocate){
      obj->Deallocate(obj->value);
    }
    free(obj);
  }
}