#ifndef _retainCounter_h
#define _retainCounter_h

typedef struct
{
  int retainCount;
  void (*Deallocate)(void *object);
} LSRetainCounter;

typedef void (*deallocate)(void *);

LSRetainCounter *LSCreateRetainCounter(void);
void LSRetain(void *ptr);
void LSRelease(void *ptr);

#endif
