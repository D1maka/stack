#ifndef _retainCounter_h
#define _retainCounter_h

typedef struct
{
  int retainCount;
  void (*Deallocate)(void *object);
} RetainCounter;

typedef void (*deallocate)(void *);

void *Create(size_t size, deallocate func);
void Retain(void *ptr);
void Release(void *ptr);

#endif
