#include "object.h"

void *Alloc(size_t size)
{
  char *valuePtr;
  Object *obj = (Object *)calloc(sizeof(Object) + size, 1);
  obj->retainCount = 1;
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
    free(obj);
  }
}