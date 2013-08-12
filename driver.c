#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "retainCounter.h"
#include "node.h"
#include "stack.h"
#include "baseObject.h"
#include "SomeClass.h"

void deallocateSomeClass(void *inputObject)
{
    LSSomeClass *someClass = (LSSomeClass*) inputObject;
    free(someClass->counter->Deallocate);
    free(someClass->counter);
    free(inputObject);
}

int main(int argc, char *argv[])
{
    LSSomeClass *someClass = LSCreateSomeClass(5);
    someClass->counter->Deallocate = deallocateSomeClass;
    LSStack *myStack = LSStackCreate();
    LSPush(myStack, (LSBaseObject*)someClass);
    printf("top: %d\n", (myStack->top->counter->retainCount));
    LSRetain((LSBaseObject*) myStack->top);
    printf("top: %d\n", (myStack->top->counter->retainCount));

    LSPush(myStack, (LSBaseObject*)LSCreateSomeClass(10));

    //scanf();
    return 0;
}
