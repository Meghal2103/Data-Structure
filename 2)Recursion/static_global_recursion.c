#include <stdio.h>

int fun(int n)
{
    static int x;
    if(n>0)
    {
        x++;
        int y = fun(n-1)+x;
        return y;
    }
    return 0;
}

int main()
{
    printf("%d",fun(3));
}