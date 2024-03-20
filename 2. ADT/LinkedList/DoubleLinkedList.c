#include "DoubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

DLL DLL_InitList(){
    DLL list = (DLL)malloc(sizeof(DoubleNode));
    list->next = NULL;
    list->prev = NULL;
    return list;
}

int DLL_Empty(DLL list){
    return list->next == NULL;
}

void DLL_PrintList(DLL list){
    DoubleNode *p = list->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int DLL_Length(DLL list){
    DoubleNode *p = list->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

int DLL_Locate(DLL list, DataType x){
    DoubleNode *p = list->next;
    int pos = 1;
    while(p){
        if(p->data == x){
            return pos;
        }
        pos++;
        p = p->next;
    }
    return -1;
}
DoubleNode * DLL_Get(DLL list, int i, DataType *x){
    if(i < 0){
        return NULL;
    }
    DoubleNode *p = list;
    int pos = 0;
    while(p && pos < i){
        pos++;
        p = p->next;
    }
    if(!p){
        return NULL;
    }
    if(x){
        *x = p->data;
    }
    return p;
}

DoubleNode * DLL_Insert(DLL list, int i, DataType x){
    int num = DLL_Length(list);
    if(i < 1 || i > num + 1){
        return NULL;
    }
    DoubleNode *p = DLL_Get(list, i - 1, NULL);
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode->data = x;
    newNode->next = p->next;
    if(p->next){
        p->next->prev = newNode;
    }
    newNode->prev = p;
    p->next = newNode;
}

DLL DLL_CreateList(DataType a[], int n){
    DLL list = DLL_InitList();
    DoubleNode *p = list;
    for(int i = 0; i < n; i++){
        DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
        newNode->data = a[i];
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return list;
}

int DLL_Delete(DLL list, int i, DataType *x){
    DoubleNode *p = DLL_Get(list, i - 1, NULL);
    if(!p){
        return -1;
    }
    DoubleNode *q = p->next;
    if(x){
        *x = q->data;
    }
    p->next = q->next;
    if(q->next){
        q->next->prev = p;
    }
    free(q);
    return 0;
}

void DLL_DestroyList(DLL list){
    DoubleNode *p = list;
    while(p){
        DoubleNode *q = p;
        p = p->next;
        free(q);
    }
}

DllOps dllOps = {
    .InitList = DLL_InitList,
    .Empty = DLL_Empty,
    .PrintList = DLL_PrintList,
    .Length = DLL_Length,
    .Locate = DLL_Locate,
    .Get = DLL_Get,
    .Insert = DLL_Insert,
    .CreateList = DLL_CreateList,
    .Delete = DLL_Delete,
    .DestroyList = DLL_DestroyList
};