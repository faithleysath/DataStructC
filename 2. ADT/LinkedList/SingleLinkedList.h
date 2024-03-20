#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
typedef int DataType;
typedef struct SingleNode {
    DataType data;
    struct SingleNode *next;
} SingleNode, *SLL;
typedef struct SllOps {
    SLL (*InitList)();
    int (*Empty)(SLL L);
    void (*PrintList)(SLL L);
    int (*Length)(SLL L);
    int (*Locate)(SLL L, DataType x);
    SingleNode * (*Get)(SLL L, int i, DataType *ptr);
    SingleNode * (*Insert)(SLL L, int i, DataType x);
    SLL (*CreateList)(DataType a[], int n);
    int (*Delete)(SLL L, int i, DataType *ptr);
    void (*DestroyList)(SLL L);
} SllOps;
#endif