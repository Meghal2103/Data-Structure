#include <stdio.h>

void fib(int n, int a[])
{
    if(a[n-2]==-1)
    {
        fib(n-2,a);
        fib(n-1,a);
    }
    if(a[n-1]==-1)
    {
        fib(n-1,a);
    }
    a[n]=a[n-1]+a[n-2];
}

int fibonacci(int n)
{
    if(n<=1)
    {
        return n;
    }
    int x = fibonacci(n-2)+fibonacci(n-1);
    return x;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i] = -1;
    }
    a[0]=0;
    a[1]=1;
    fib(n-1,a);
    printf("%d\n",a[n-1]);
    int x = fibonacci(n-1);
    printf("%d",x);
}