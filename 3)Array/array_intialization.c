#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5];
    int b[5]={1,2};
    int c[5]={1,2,3,4,5};
    int d[5]={0};
    int e[]={1,2,3,4,5};
    int *f=(int *)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++)
    {
        *(f+i)=i;
    }
}