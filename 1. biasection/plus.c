/*二分法求函数零点plus*/
#include <stdio.h>
#include <math.h>
#define EPS 1e-6
#define FEPS 1e-8
#define true 1
double f(double x)
{
    return x*x*x-5*x*x+16*x-80;
}
double f1(double x)
{
    return 10000000000*x;
}
double f2(double x)
{
    return 0.000000001*x;
}
double bisection(double a,double b, double (*f)(double))
{
    double mid, fmid;
    while(true)
    {
        if(f(a)*f(b) == 0)
            return (f(a) == 0) ? a : b; // 有一个端点是零点
        mid=(a+b)/2;
        fmid = f(mid);
        printf("a=%lf, b=%lf, mid=%lf, fmid=%lf\n", a, b, mid, fmid);
        if(fabs(fmid) < FEPS && fabs(b-a) < EPS) // 要求函数值小于1e-8，且区间长度小于1e-6
            return mid; // 找到零点
        else if(a == b)
            return -114514; // 撞到边界
        else if(fmid*f(a)<0)
            b=mid;
        else
            a=mid;
    }
}
int main()
{
    double a,b;
    printf("请输入区间端点(顺序任意)：");
    scanf("%lf%lf",&a,&b);
    double root = bisection(a,b,f2);
    if (root == -114514)
        printf("找不到零点\n");
    else
        printf("零点是：%lf\n", root);
    return 0;
}