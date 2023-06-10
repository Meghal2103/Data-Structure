#include <stdio.h>
#include <stdlib.h>

class bandMatrix
{
    private:
        int *a;              //array
        int n;               //dimension
        int band;            //no of band
        int space;           //lenght of array
        int e;               //ending index of diagonal

    public:
        bandMatrix()
        {
            a = (int *)malloc(10*sizeof(int));
            n = 3;
            band = 1;
            space = 3;
            e=2;
        }

        bandMatrix(int size, int noDiagonal)
        {
            space = size + (size*(noDiagonal-1)) - (((noDiagonal*noDiagonal)-1)/4);
            a = (int *)malloc(space*sizeof(int));
            n = size;
            band = noDiagonal;
            int sum = 0;
            for(int i=band/2; i>=0; i--)
            {
                sum = sum + n - i;
            }
            e = sum;
        }

        void setArray(int row, int coloumn, int value)
        {
            if(row>=coloumn)
            {
                int sum = 0;
                for(int i=band/2; i>row-coloumn; i--)
                {
                    sum = sum + n - i;
                }
                sum = sum + coloumn-1;
                a[sum]=value;
            }
            else
            {
                int sum = 0;
                for(int i=band/2; i>coloumn-row; i--)
                {
                    sum = sum + n - i;
                }
                sum = sum + coloumn-1;
                a[e+sum-1]=value;

            }
        }

        int getArray(int row, int coloumn)
        {
            if(row>=coloumn)
            {
                int sum = 0;
                for(int i=band/2; i>row-coloumn; i--)
                {
                    sum = sum + n - i;
                }
                sum = sum + coloumn-1;
                return a[sum];
            }
            else
            {
                int sum = 0;
                for(int i=band/2; i>coloumn-row; i--)
                {
                    sum = sum + n - i;
                }
                sum = sum + coloumn-1;
                return a[e+sum-1];
            }
        }

        void display()
        {
            for(int row=1; row<=n; row++)
            {
                for(int coloumn=1; coloumn<=n; coloumn++)
                {
                    if(row-coloumn<=band/2 && row-coloumn>=0)
                    {
                        int sum = 0;
                        for(int i=band/2; i>row-coloumn; i--)
                        {
                            sum = sum + n - i;
                        }
                        sum = sum + coloumn-1;
                        printf("%d ",a[sum]);
                    }
                    else if(coloumn-row<=band/2 && coloumn-row>=0)
                    {
                        int sum = 0;
                        for(int i=band/2; i>coloumn-row; i--)
                        {
                            sum = sum + n - i;
                        }
                        sum = sum + coloumn-1;
                        printf("%d ", a[e+sum-1]);
                    }
                    else
                    {
                        printf("%d ",0);
                    }
                }
                printf("\n");
            }
        }
};

int main()
{
    bandMatrix a = bandMatrix(4,3);
    a.setArray(1,1,1);
    a.setArray(1,2,1);

    a.setArray(2,1,1);
    a.setArray(2,2,1);
    a.setArray(2,3,1);

    a.setArray(3,2,1);
    a.setArray(3,3,1);
    a.setArray(3,4,1);

    a.setArray(4,3,1);
    a.setArray(4,4,1);

    a.display();
}