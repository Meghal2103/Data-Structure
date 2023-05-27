#include <stdio.h>

int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    int s;
    s = n + sum(n-1); // tail recursion
    return s;
}

int loopSum(int n)
{
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    printf("%d\n",sum(10));
    printf("%d\n",loopSum(10));
}