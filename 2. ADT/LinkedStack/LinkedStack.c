#include "../LinkedList/SingleLinkedList.c"
typedef SLL Stack;
Stack InitStack()
{
    return sllOps.InitList();
}
void DestroyStack(Stack S)
{
    sllOps.DestroyList(S);
}
void PushStack(Stack S, DataType x)
{
    Stack r = (Stack)malloc(sizeof(SingleNode));
    r->data = x;
    r->next = S->next;
    S->next = r;
}
int EmptyStack(Stack S)
{
    return sllOps.Empty(S);
}
int PopStack(Stack S, DataType *x)
{
    if(EmptyStack(S))
        return 0;
    Stack p = S->next;
    *x = p->data;
    S->next = p->next;
    free(p);
    return 1;
}
int GetTop(Stack S, DataType *x)
{
    if(EmptyStack(S))
        return 0;
    *x = S->next->data;
    return 1;
}