#ifndef SEQLIST_H
#define SEQLIST_H
#define MaxSize 1000
typedef int DataType;
typedef struct SeqList {
    DataType data[MaxSize];
    int length;
} SeqList;
typedef struct SeqListOps {
    void (*InitList)(SeqList *L);
    int (*CreateList)(SeqList *L, DataType a[], int n);
    int (*Empty)(SeqList *L);
    int (*Length)(SeqList *L);
    void (*PrintList)(SeqList *L);
    int (*Locate)(SeqList *L, DataType x);
    int (*Get)(SeqList *L, int i, DataType *ptr);
    int (*Insert)(SeqList *L, int i, DataType x);
    int (*Delete)(SeqList *L, int i, DataType *ptr);
} SeqListOps;
#endif