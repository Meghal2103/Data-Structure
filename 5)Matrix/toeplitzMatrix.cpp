#include <stdio.h>
#include <stdlib.h>

class toeplitzMatrix
{
    private:
        int *a;              //array
        int n;               //dimension
    public:
        toeplitzMatrix()
        {
            a = (int *)malloc(5*sizeof(int));
            n = 3;
        }

        toeplitzMatrix(int size)
        {
            a = (int *)malloc(((2*size)-1)*sizeof(int));
            n = size;
        }

        void setArray(int row, int coloumn, int value)
        {
            if(coloumn-row>=0)
            {
                a[coloumn-row] = value;
            }
            else
            {
                a[n+row-coloumn-1] = value;
            }
        }

        int getArray(int row, int coloumn)
        {
            if(coloumn-row>=0)
            {
                return a[coloumn-row];
            }
            else
            {
                return a[n+row-coloumn-1];
            }
        }

        void display()
        {
            for(int row=1; row<=n; row++)
            {
                for(int coloumn=1; coloumn<=n; coloumn++)
                {
                    printf("%d ",getArray(row,coloumn));
                }
                printf("\n");
            }
        }
};

int main()
{
    toeplitzMatrix a = toeplitzMatrix(3);
    a.setArray(1,1,1);
    a.setArray(1,2,2);
    a.setArray(1,3,3);
    a.setArray(2,1,4);
    a.setArray(3,1,5);
    a.display();
}