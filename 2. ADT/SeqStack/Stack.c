#include "Stack.h"
#include <stdio.h>

void InitStack(SeqStack *S)
{
    S->top = -1;
}
int PushStack(SeqStack *S, DataType x)
{
    if (S->top == StackSize - 1)
    {
        printf("栈满");
        return 0;
    }
    S->top++;
    S->data[S->top] = x;
    return 1;
}
int PopStack(SeqStack *S, DataType *x)
{
    if (S->top == -1)
    {
        printf("栈空");
        return 0;
    }
    *x = S->data[S->top];
    S->top--;
    return 1;
}
int GetTop(SeqStack *S, DataType *x)
{
    if (S->top == -1)
    {
        printf("栈空");
        return 0;
    }
    *x = S->data[S->top];
    return 1;
}
int StackEmpty(SeqStack *S)
{
    return (S->top == -1);
}