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
    printf("Hello from object %p\n", inputObject);
    //free(someClass->counter->Deallocate);
    free(someClass->counter);
    free(someClass);
    printf("Hello from object %p\n", inputObject);
}

int main(int argc, char *argv[])
{
    LSSomeClass *someClass = LSCreateSomeClass(5);

    someClass->counter->Deallocate = deallocateSomeClass;
    LSStack *myStack = LSStackCreate();
    LSPush(myStack, (LSBaseObject*)someClass);
    printf("Stack top: %d\n", (myStack->top->counter->retainCount));
    printf("Object: %d\n", someClass->counter->retainCount);
    LSRetain(myStack->top);
    printf("After Retain\n");
    printf("Stack top: %d\n", (myStack->top->counter->retainCount));

    //LSPush(myStack, (LSBaseObject*)LSCreateSomeClass(10));
    //LSPop(myStack);
    //LSPop(myStack);

    LSRelease(someClass);
    //LSRelease(someClass);
    printf("Stack top: %p\n", (myStack->top->value));
    printf("SomeClass retain count: %d\n", someClass->counter->retainCount);
    printf("SomeClass value: %d\n", someClass->value);

    return 0;
}
