#ifndef _node_h
#define _node_h

typedef struct
{
  void *value;
  void *next; 
} Node;

void *NodeCreate(size_t size, void *anything);
void DestroyNode(void *self);

#endif
