#include "SingleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

SLL SLL_InitList(){
    SLL list = (SLL)malloc(sizeof(SingleNode));
    list->next = NULL;
    return list;
}

int SLL_Empty(SLL list){
    return list->next == NULL;
}

void SLL_PrintList(SLL list){
    SingleNode *p = list->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int SLL_Length(SLL list){
    SingleNode *p = list->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

int SLL_Locate(SLL list, DataType x){
    SingleNode *p = list->next;
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

SingleNode * SLL_Get(SLL list, int i, DataType *x){
    if(i < 0){
        return NULL;
    }
    SingleNode *p = list;
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

SingleNode * SLL_Insert(SLL list, int i, DataType x){
    int num = SLL_Length(list);
    if(i < 1 || i > num + 1){
        return NULL;
    }
    SingleNode *p = SLL_Get(list, i - 1, NULL);
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
    return newNode;
}

SLL SLL_CreateList(DataType a[], int n){
    SLL list = SLL_InitList();
    SingleNode *p = list;
    for(int i = 0; i < n; i++){
        SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
        newNode->data = a[i];
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return list;
}

int SLL_Delete(SLL list, int i, DataType *x){
    SingleNode *p = SLL_Get(list, i - 1, NULL);
    if(!p){
        return -1;
    }
    SingleNode *q = p->next;
    if(x){
        *x = q->data;
    }
    p->next = q->next;
    free(q);
    return 0;
}

void SLL_DestroyList(SLL list){
    SingleNode *p = list;
    while(p){
        SingleNode *q = p;
        p = p->next;
        free(q);
    }
}

SllOps sllOps = {
    .InitList = SLL_InitList,
    .Empty = SLL_Empty,
    .PrintList = SLL_PrintList,
    .Length = SLL_Length,
    .Locate = SLL_Locate,
    .Get = SLL_Get,
    .Insert = SLL_Insert,
    .CreateList = SLL_CreateList,
    .Delete = SLL_Delete,
    .DestroyList = SLL_DestroyList
};