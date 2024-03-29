// C program for array implementation of stack taken from https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
 
// A structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
//Returns the top of the stack
int getTop(struct Stack* stack){
    return stack->array[stack->top];
}

//Returns the second highest element of the stack
int getSubTop(struct Stack* stack){
    return stack->array[(stack->top)-1];
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
        
    return stack->array[stack->top--];
}
