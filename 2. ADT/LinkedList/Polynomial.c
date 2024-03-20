// 一元多项式求和
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coef;
    int exp;
    struct PolyNode *next;
} *Polynomial, PolyNode;

Polynomial ReadPoly();
void PrintPoly(Polynomial P);
Polynomial AddPoly(Polynomial A, Polynomial B);

int main(){
    Polynomial A = ReadPoly();
    Polynomial B = ReadPoly();
    Polynomial C = AddPoly(A, B);
    PrintPoly(C);
    return 0;
}

Polynomial ReadPoly(){
    printf("请输入多项式的项数和系数（0结尾）：\n");
    Polynomial P, r, t;
    P = (Polynomial)malloc(sizeof(PolyNode));
    int coef, exp;
    r = (Polynomial)malloc(sizeof(PolyNode));
    P -> next = r;
    scanf("%d%d", &coef, &exp);
    while(coef != 0){
        r -> coef = coef;
        r -> exp = exp;
        r -> next = (Polynomial)malloc(sizeof(PolyNode));
        t = r;
        r = r -> next;
        scanf("%d%d", &coef, &exp);
    }
    t -> next = NULL;
    return P;
}

void PrintPoly(Polynomial P){
    Polynomial r = P -> next;
    printf("多项式为：%d * X^%d", r -> coef, r -> exp);
    r = r -> next;
    while(r){
        printf(" + %d * X^%d", r -> coef, r -> exp);
        r = r -> next;
    }
}

Polynomial AddPoly(Polynomial A, Polynomial B){
    PolyNode *p = A -> next, *q = B -> next, *r, *t;
    Polynomial C = (Polynomial)malloc(sizeof(PolyNode));
    C -> next = NULL;
    r = C;
    while(p || q){
        r -> next = (PolyNode *)malloc(sizeof(PolyNode));
        t = r;
        r = r -> next;
        r -> next = NULL;
        if(p && (!q || p -> exp < q -> exp)){
            r -> coef = p -> coef;
            r -> exp = p -> exp;
            p = p -> next;
        } else if(!p || p -> exp > q -> exp){
            r -> coef = q -> coef;
            r -> exp = q -> exp;
            q = q -> next;
        } else {
            r -> coef = p -> coef + q -> coef;
            r -> exp = p -> exp;
            if(r -> coef == 0){
                free(r);
                r = t;
                r -> next = NULL;
            }
            p = p -> next;
            q = q -> next;
        }
    }
    return C;
}