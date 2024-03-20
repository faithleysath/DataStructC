#include "seqlist.h"
#include <stdio.h>

void SeqList_InitList(SeqList *L)
{
    L->length = 0;
}

int SeqList_CreateList(SeqList *L, DataType a[], int n)
{
    if (n > MaxSize)
        return 0;
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
    return 1;
}

int SeqList_Empty(SeqList *L)
{
    if (L->length == 0)
        return 1;
    else
        return 0;
}

int SeqList_Length(SeqList *L)
{
    return L->length;
}

void SeqList_PrintList(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

int SeqList_Locate(SeqList *L, DataType x)
{
    for (int i = 0; i < L->length; i++)
        if (L->data[i] == x)
            return i + 1;
    return 0;
}

int SeqList_Get(SeqList *L, int i, DataType *ptr)
{
    if (i < 1 || i > L->length)
        return 0;
    *ptr = L->data[i - 1];
    return 1;
}

int SeqList_Insert(SeqList *L, int i, DataType x)
{
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length == MaxSize)
        return 0;
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = x;
    L->length++;
    return 1;
}

int SeqList_Delete(SeqList *L, int i, DataType *ptr)
{
    if (i < 1 || i > L->length)
        return 0;
    *ptr = L->data[i - 1];
    for (int j = i; j < L->length; j++)
        L->data[j - 1] = L->data[j];
    L->length--;
    return 1;
}

SeqListOps seqListOps = {
    .InitList = SeqList_InitList,
    .CreateList = SeqList_CreateList,
    .Empty = SeqList_Empty,
    .Length = SeqList_Length,
    .PrintList = SeqList_PrintList,
    .Locate = SeqList_Locate,
    .Get = SeqList_Get,
    .Insert = SeqList_Insert,
    .Delete = SeqList_Delete,
};