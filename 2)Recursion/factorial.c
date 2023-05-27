#include <stdio.h>

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    int s;
    s = n *  fact(n-1); // tail recursion
    return s;
}

int loopFact(int n)
{
    int sum=1;
    for(int i=1; i<=n; i++)
    {
        sum = sum * i;
    }
    return sum;
}

int main()
{
    printf("%d\n",fact(5));
    printf("%d\n",loopFact(0));
}