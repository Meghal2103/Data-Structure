#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *f=(int *)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++)
    {
        *(f+i)=i;
    }
    int *e=(int *)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++)
    {
        *(e+i)=*(f+i);
    }
    free(f);
    f=e;
    e=NULL;
}