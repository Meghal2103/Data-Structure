#include <stdio.h>
#include <stdlib.h>

class Element
{
    public:
        int i;
        int j;
        int value;
};

class sparseMatrix
{
    public:
        int n;
        int m;
        int no_of_non_zero_values;
        Element * arr;
    public:
        sparseMatrix(int row, int coloumn, int no_of_non_zero_elements)
        {
            n=row;
            m=coloumn;
            no_of_non_zero_values = no_of_non_zero_elements;
            arr = (Element *)malloc(sizeof(Element)*no_of_non_zero_values);
        }
        void display()
        {
            int k=0;
            for(int i=1; i<=n;i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(arr[k].i==i && arr[k].j==j && k<=no_of_non_zero_values)
                    {
                        printf("%3d ",arr[k].value);
                        k++;
                    }
                    else
                    {
                        printf("%3d ",0);
                    }
                }
                printf("\n");
            }
        }
};

struct sparseMatrix * sumSparseMatrix(struct sparseMatrix a, struct sparseMatrix b)
{
    if(a.n==b.n && a.m==b.m)
    {
        struct sparseMatrix *c;
        c=(struct sparseMatrix *)malloc(sizeof(struct sparseMatrix));
        c->n = a.n;
        c->m = a.m;
        c->arr=(struct Element *)malloc((a.no_of_non_zero_values+b.no_of_non_zero_values)*sizeof(struct Element));
        int i=0,j=0,k=0;
        while(i<a.no_of_non_zero_values || j<b.no_of_non_zero_values)
        {
            if(a.arr[i].i==b.arr[j].i)
            {
                if(a.arr[i].j==b.arr[j].j)
                {
                    c->arr[k].i = a.arr[i].i;
                    c->arr[k].j = a.arr[i].j;
                    c->arr[k].value = a.arr[i].value+b.arr[j].value;
                    i++;
                    j++;
                    k++;
                }
                else if(a.arr[i].j<b.arr[j].j)
                {
                    c->arr[k].i = a.arr[i].i;
                    c->arr[k].j = a.arr[i].j;
                    c->arr[k].value = a.arr[i].value;
                    i++;
                    k++;
                }
                else
                {
                    c->arr[k].i = b.arr[j].i;
                    c->arr[k].j = b.arr[j].j;
                    c->arr[k].value = b.arr[j].value;
                    j++;
                    k++;
                }
            }
            else if(a.arr[i].i<b.arr[j].i)
            {
                c->arr[k].i = a.arr[i].i;
                c->arr[k].j = a.arr[i].j;
                c->arr[k].value = a.arr[i].value;
                i++;
                k++;
            }
            else
            {
                c->arr[k].i = b.arr[j].i;
                c->arr[k].j = b.arr[j].j;
                c->arr[k].value = b.arr[j].value;
                j++;
                k++;
            }
        }
        c->no_of_non_zero_values=k;
        return c;
    }
    return NULL;
};

int main()
{
    sparseMatrix a = sparseMatrix(5,6,5);
    a.arr[0].i=1;
    a.arr[0].j=4;
    a.arr[0].value=6;
    a.arr[1].i=2;
    a.arr[1].j=2;
    a.arr[1].value=7;
    a.arr[2].i=3;
    a.arr[2].j=2;
    a.arr[2].value=2;
    a.arr[3].i=3;
    a.arr[3].j=4;
    a.arr[3].value=5;
    a.arr[4].i=5;
    a.arr[4].j=1;
    a.arr[4].value=4;
    a.display();
    printf("\n");
    sparseMatrix b = sparseMatrix(5,6,6);
    b.arr[0].i=2;
    b.arr[0].j=2;
    b.arr[0].value=3;
    b.arr[1].i=2;
    b.arr[1].j=5;
    b.arr[1].value=5;
    b.arr[2].i=3;
    b.arr[2].j=3;
    b.arr[2].value=2;
    b.arr[3].i=3;
    b.arr[3].j=6;
    b.arr[3].value=7;
    b.arr[4].i=4;
    b.arr[4].j=4;
    b.arr[4].value=9;
    b.arr[5].i=5;
    b.arr[5].j=1;
    b.arr[5].value=8;
    b.display();
    printf("\n");
    sparseMatrix *c;
    c=sumSparseMatrix(a,b);
    (*c).display();
}

