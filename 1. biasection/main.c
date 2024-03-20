/*二分法求函数零点*/
#include <stdio.h>
#include <math.h>
#define EPS 1e-6
double f(double x)
{
    return x*x*x-5*x*x+16*x-80;
}
double bisection(double a,double b, double (*f)(double))
{
    double mid;
    while(b-a>EPS)
    {
        mid=(a+b)/2;
        if(f(mid)*f(a)<0)
            b=mid;
        else
            a=mid;
    }
    return mid;
}
int main()
{
    double a,b;
    printf("请输入区间a,b：");
    scanf("%lf%lf",&a,&b);
    printf("零点是：%lf\n",bisection(a,b,f));
    return 0;
}