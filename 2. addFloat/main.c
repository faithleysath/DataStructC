// 高精度浮点数加法
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链表结构，带头指针的双向循环链表
typedef struct Node {
    char data; // 只存储0~9
    struct Node *next, *prev;
} Node, *Num;

// 定义高精度浮点数结构
typedef struct LargeFloat {
    bool sign; // 符号位
    int exp; // 指数
    Num num; // 数值
} LargeFloat;

/* 函数原型 */
Num initNum(); // 初始化链表
void freeNum(Num num); // 释放链表
void freeLargeFloat(LargeFloat* lf); // 释放LargeFloat
Node* insert(Node *p, char data); // 在Node *p 之后插入一个新节点，值为data
void cleanLargeFloat(LargeFloat *lf); // 清洗LargeFloat，去掉前导0和后导0
LargeFloat* inputLargeFloat(); // 输入LargeFloat
void outputLargeFloat(LargeFloat *lf); // 输出LargeFloat
LargeFloat* addLargeFloat(LargeFloat a, LargeFloat b); // 定义加法函数

int main() {
    LargeFloat *a = inputLargeFloat();
    LargeFloat *b = inputLargeFloat();
    LargeFloat *c = addLargeFloat(*a, *b);
    outputLargeFloat(c);
    return 0;
}

// 定义加法函数
LargeFloat* addLargeFloat(LargeFloat a, LargeFloat b) {
    LargeFloat *c = (LargeFloat*)malloc(sizeof(LargeFloat));
    c->sign = 0;
    c->num = initNum();
    // 先把a和b的小数点对齐，就是往exp小的那个数的最前端插入exp的差值个0
    if (a.exp != b.exp) {
        LargeFloat *A, *B;
        A = a.exp > b.exp ? &a : &b;
        B = a.exp > b.exp ? &b : &a;
        int diff = A->exp - B->exp;
        for (int i = 0; i < diff; i++) insert(B->num, '0');
        B->exp = A->exp;
    }
    c->exp = a.exp;
    // 将num对齐，就是往短的那个最后插0
    Node *pa = a.num->next, *pb = b.num->next;
    while (true) {
        if (pa->next == a.num && pb->next == b.num) break;
        if (pa->next == a.num) {
            pa = insert(pa, '0');
            pb = pb->next;
        } else if (pb->next == b.num) {
            pb = insert(pb, '0');
            pa = pa->next;
        } else {
            pa = pa->next;
            pb = pb->next;
        }
    }
    // 从最低位开始逐位相加
    pa = a.num->prev;
    pb = b.num->prev;
    char carry = 0;
    while (pa != a.num || pb != b.num) {
        char sum = pa->data + pb->data + carry;
        carry = sum / 10;
        insert(c->num, sum % 10 + '0');
        pa = pa->prev;
        pb = pb->prev;
    }
    if (carry) insert(c->num, carry + '0');
    cleanLargeFloat(c); // 清洗LargeFloat
    return c;
}

// 输入LargeFloat
LargeFloat* inputLargeFloat() {
    LargeFloat *lf = (LargeFloat*)malloc(sizeof(LargeFloat));
    lf->sign = lf->exp = 0;
    lf->num = initNum();
    Node *p = lf->num;
    char c;
    scanf("%c", &c);
    if (c == '-') lf->sign = 1;
    else {p = insert(p, c);lf->exp++;}
    // 读入整数部分
    while (scanf("%c", &c) == 1 && c != '.') {
        p = insert(p, c);
        lf->exp++;
    }
    // 读入小数部分
    while (scanf("%c", &c) == 1 && c != '\n') {
        p = insert(p, c);
    }
    cleanLargeFloat(lf); // 清洗LargeFloat
    return lf;
}

// 输出LargeFloat
void outputLargeFloat(LargeFloat *lf) {
    if (lf->sign) putchar('-');
    Node *p = lf->num->next;
    if (lf->exp == 0) putchar('0');
    for (int i = 0; i < lf->exp; i++) {
        putchar(p->data + '0');
        p = p->next;
    }
    if (p != lf->num) putchar('.');
    while (p != lf->num) {
        putchar(p->data + '0');
        p = p->next;
    }
    putchar('\n');
}

// 清洗LargeFloat，去掉前导0和后导0
void cleanLargeFloat(LargeFloat *lf) {
    Node *p = lf->num->next;
    Node *q = lf->num->prev;
    while (p != lf->num && p->data == 0 && lf->exp > 0) {
        Node *t = p->next;
        free(p);
        p = t;
        lf->exp--;
    }
    lf->num->next = p;
    p->prev = lf->num;
    while (q != lf->num && q->data == 0) {
        Node *t = q->prev;
        free(q);
        q = t;
    }
    lf->num->prev = q;
    q->next = lf->num;
}

// 初始化链表
Num initNum() {
    Num num = (Num)malloc(sizeof(Node));
    num->data = '\n';
    num->next = num->prev = num;
    return num;
}

// 释放链表
void freeNum(Num num) {
    Node *p = num->next, *q;
    while (p != num) {
        q = p->next;
        free(p);
        p = q;
    }
    free(num);
}

// 释放LargeFloat
void freeLargeFloat(LargeFloat* lf) {
    freeNum(lf->num);
    free(lf);
}

// 在Node *p 之后插入一个新节点，值为data
Node* insert(Node *p, char data) {
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = data - '0';
    q->next = p->next;
    q->prev = p;
    p->next->prev = q;
    p->next = q;
    return q;
}