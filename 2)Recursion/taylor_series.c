#include <stdio.h>

float fact(float n)
{
    if(n==0)
    {
        return 1;
    }
    float s;
    s = n *  fact(n-1); // tail recursion
    return s;
}

float exponential(int base, int power)
{
    if(power == 0)
    {
        return 1;
    }
    if(power%2==1)
    {
        float a = exponential(base, power/2);
        return a*a*base;
    }
    else
    {
        float a = exponential(base, power/2);
        return a*a;
    }
};

float taylor(int x, int n)
{
    if(n==1)
    {
        return 1;
    }
    float t = exponential(x,n-1)/fact(n-1);
   
    return t + taylor(x,n-1);
}

double staticTaylor(int x, int n)
{
    static double f=1,p=1;
    double r;
    if(n==1)
    {
        return 1;
    }
    r = staticTaylor(x,n-1);
    p=p*x;
    f=f*(n-1);
    return r+(p/f);
}

double staticVarTaylor(int x, int n)
{
    static double f=1,p=1;
    if(n==1)
    {
        return 1;
    }
    double r=staticVarTaylor(x,n-1);
    p=p*x;
    f=f*(n-1);
    r=r+(p/f);
    return r;
}

double taylorIterative(float x,float n)
{
    float r=1;
    for(int i=n-1;i>0;i--)
    {
        float y=x/i;
        r = 1 + (y*r);
    }
    return r;
}

double taylorMulti(float x, float n)
{
    static double t;
    if(n==0)
    {
        return t;
    }
    double r = x/n;
    t = (1+ (r*t));
    return taylorMulti(x,n-1);

}

int main()
{
    float n;
    printf("Enter number of terms to be calculated: ");
    scanf("%f", &n);
    printf("Enter value of x: ");
    float x;
    scanf("%f", &x);
    // printf("%f\n", taylor(x,n));
    printf("%f\n", taylorMulti(x,n));
}