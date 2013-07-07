#ifndef _node_h
#define _node_h

typedef struct
{
  void *value;
  void *next;
  
  void (*destroy)(void *self);
} Node;

void *new_node(size_t size, void *anything);
void destroy_node(void *self);

#endif
