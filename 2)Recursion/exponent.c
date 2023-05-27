#include <stdio.h>

int exponential(int base, int power)
{
    if(power == 0)
    {
        return 1;
    }
    if(power%2==1)
    {
        int a = exponential(base, power/2);
        return a*a*base;
    }
    else
    {
        int a = exponential(base, power/2);
        return a*a;
    }
}

int main()
{
    printf("%d",exponential(2,4));
}