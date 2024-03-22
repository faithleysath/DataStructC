#ifndef STACK_H
#define STACK_H
#define StackSize 100
typedef int DataType;
typedef struct {
    DataType data[StackSize];
    int top;
} SeqStack;

void InitStack(SeqStack *S);
int PushStack(SeqStack *S, DataType x);
int PopStack(SeqStack *S, DataType *x);
int GetTop(SeqStack *S, DataType *x);
int StackEmpty(SeqStack *S);
#endif