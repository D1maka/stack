#ifndef _object_h 
#define _object_h

typedef struct
{
  int retainCount;
  void (*Deallocate)(void *object);
  void *value;
} Object;

typedef void (*deallocate)(void *);

void *Alloc(size_t size, deallocate func);
void Retain(void *ptr);
void Release(void *ptr);

#endif