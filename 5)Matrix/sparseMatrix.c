#include <stdio.h>
#include <stdlib.h>

// class sparseMatrix{
//     private:
//         int *a;
//         int noRow;
//         int noColoumn;
//     public:
//         sparseMatrix(int no_on_zero_element, int n, int m)
//         {
//             a = (int *)malloc(n*3*sizeof(int));
//             noRow = n;
//             noColoumn = m;
//         }
//         void setArray(int i, int j, int value)
//         {
//             a[((i*noRow)+j)*sizeof(int)] = value;
//         }
// };

struct Element
{
    int i;
    int j;
    int value;
};

struct sparseMatrix
{
    int n;
    int m;
    int no_of_non_zero_elements;
    struct Element *arr;
};

void createSparseMatrix(struct sparseMatrix *s, int n, int m, int no_of_non_zero_e)
{
    s->n = n;
    s->m = m;
    s->no_of_non_zero_elements = no_of_non_zero_e;
    s->arr = (struct Element *)malloc(no_of_non_zero_e*sizeof(struct Element));
};

// void sumSparseMatrix(int a[][3], int b[][3], int c[][3])
// {
//     int i=1,j=1,k=1;
//     while(i<=a[0][0] || j<=b[0][0])
//     {
//         if(a.arr[i].i==b[j][0])
//         {
//             if(a[i][1]==b[j][1])
//             {
//                 c[k][0] = a.arr[i].i;
//                 c[k][1] = a[i][1];
//                 c[k][2] = a[i][2]+b[j][2];
//                 i++;
//                 j++;
//                 k++;
//             }
//             else if(a[i][1]<=b[j][1])
//             {
//                 c[k][0] = a.arr[i].i;
//                 c[k][1] = a[i][1];
//                 c[k][2] = a[i][2];
//                 i++;
//                 k++;
//             }
//             else
//             {
//                 c[k][0] = b[j][0];
//                 c[k][1] = b[j][1];
//                 c[k][2] = b[j][2];
//                 j++;
//                 k++;
//             }
//         }
//         else if(a.arr[i].i<b[j][0])
//         {
//             c[k][0] = a.arr[i].i;
//             c[k][1] = a[i][1];
//             c[k][2] = a[i][2];
//             i++;
//             k++;
//         }
//         else
//         {
//             c[k][0] = b[j][0];
//             c[k][1] = b[j][1];
//             c[k][2] = b[j][2];
//             j++;
//             k++;
//         }
//     }
//     c[0][2]=k;
// }

struct sparseMatrix * sumSparseMatrix(struct sparseMatrix *a, struct sparseMatrix *b)
{
    if(a->n==b->n && a->m==b->m)
    {
        struct sparseMatrix *c;
        c=(struct sparseMatrix *)malloc(sizeof(struct sparseMatrix));
        c->n = a->n;
        c->m = a->m;
        c->arr=(struct Element *)malloc((a->no_of_non_zero_elements+b->no_of_non_zero_elements)*sizeof(struct Element));
        int i=0,j=0,k=0;
        while(i<a->no_of_non_zero_elements || j<b->no_of_non_zero_elements)
        {
            if(a->arr[i].i==b->arr[j].i)
            {
                if(a->arr[i].j==b->arr[j].j)
                {
                    c->arr[k].i = a->arr[i].i;
                    c->arr[k].j = a->arr[i].j;
                    c->arr[k].value = a->arr[i].value+b->arr[j].value;
                    i++;
                    j++;
                    k++;
                }
                else if(a->arr[i].j<b->arr[j].j)
                {
                    c->arr[k].i = a->arr[i].i;
                    c->arr[k].j = a->arr[i].j;
                    c->arr[k].value = a->arr[i].value;
                    i++;
                    k++;
                }
                else
                {
                    c->arr[k].i = b->arr[j].i;
                    c->arr[k].j = b->arr[j].j;
                    c->arr[k].value = b->arr[j].value;
                    j++;
                    k++;
                }
            }
            else if(a->arr[i].i<b->arr[j].i)
            {
                c->arr[k].i = a->arr[i].i;
                c->arr[k].j = a->arr[i].j;
                c->arr[k].value = a->arr[i].value;
                i++;
                k++;
            }
            else
            {
                c->arr[k].i = b->arr[j].i;
                c->arr[k].j = b->arr[j].j;
                c->arr[k].value = b->arr[j].value;
                j++;
                k++;
            }
        }
        c->no_of_non_zero_elements=k;
        return c;
    }
    return NULL;
};

void displaySparseMatrix(struct sparseMatrix a)
{
    int k=0;
    for(int i=1; i<=a.n;i++)
    {
        for(int j=1; j<=a.m; j++)
        {
            if(a.arr[k].i==i && a.arr[k].j==j && k<=a.no_of_non_zero_elements)
            {
                printf("%d ",a.arr[k].value);
                k++;
            }
            else
            {
                printf("%d ",0);
            }
        }
        printf("\n");
    }
};

int main()
{
    struct sparseMatrix a;
    createSparseMatrix(&a,5,6,5);
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
    struct sparseMatrix b;
    createSparseMatrix(&b,5,6,6);
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
    struct sparseMatrix *c;
    c=sumSparseMatrix(&a,&b);
    displaySparseMatrix(*c);

}