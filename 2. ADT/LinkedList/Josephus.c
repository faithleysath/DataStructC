// 约瑟夫环问题
#include "DoubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    DLL q = (DLL)malloc(sizeof(DoubleNode));
    q->data = 1;
    DLL p = q;
    for(int i = 2; i <= n; i++){
        q->next = (DLL)malloc(sizeof(DoubleNode));
        q->next->prev = q;
        q = q->next;
        q->data = i;
    }
    q->next = p;
    p->prev = q;
    while(p != p->next){
        for(int i = 1; i < m; i++)
            p = p->next;
        printf("%d ", p->data);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        DLL temp = p;
        p = p->next;
        free(temp);
    }
    printf("%d\n", p->data);
    return 0;
}