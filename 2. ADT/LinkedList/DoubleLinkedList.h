#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
typedef int DataType;
typedef struct DoubleNode
{
    DataType data;
    struct DoubleNode *prev;
    struct DoubleNode *next;
} DoubleNode, *DLL;
typedef struct DllOps {
    DLL (*InitList)();
    int (*Empty)(DLL L);
    void (*PrintList)(DLL L);
    int (*Length)(DLL L);
    int (*Locate)(DLL L, DataType x);
    DoubleNode * (*Get)(DLL L, int i, DataType *ptr);
    DoubleNode * (*Insert)(DLL L, int i, DataType x);
    DLL (*CreateList)(DataType a[], int n);
    int (*Delete)(DLL L, int i, DataType *ptr);
    void (*DestroyList)(DLL L);
} DllOps;
#endif