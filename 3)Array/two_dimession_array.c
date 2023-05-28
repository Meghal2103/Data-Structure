#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][3];
    int *b[3];
    b[0]=(int*)malloc(sizeof(int)*3);
    b[1]=(int*)malloc(sizeof(int)*3);
    b[2]=(int*)malloc(sizeof(int)*3);
    int **c=(int **)malloc(sizeof(int*)*3);
    c[0]=(int*)malloc(sizeof(int)*3);
    c[1]=(int*)malloc(sizeof(int)*3);
    c[2]=(int*)malloc(sizeof(int)*3);
    int k=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            a[i][j] = k;
            b[i][j] = k;
            c[i][j] = k;
            k++;
        }
    }

}