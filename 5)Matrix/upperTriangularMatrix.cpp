#include <stdio.h>
#include <stdlib.h>

class upperTriangularMatrix
{
    private:
        int *a;
        int n;
    public:
        upperTriangularMatrix()
        {
            a = (int *)malloc(6*sizeof(int));
            n = 3;
        }
        upperTriangularMatrix(int size)
        {
            a = (int *)malloc(size*(size+1)*0.5*sizeof(int));
            n = size;
        }
        void setArray(int row, int coloumn, int value)
        {
            if (coloumn>=row && coloumn<=n)
            {
                int index = ((coloumn*(coloumn-1))/2)+row-1;
                a[index] = value;
            }
        }
        int getArray(int row, int coloumn)
        {
            if(coloumn>=row && coloumn<=n)
            {
                int index = ((coloumn*(coloumn-1))/2)+row-1;
                return a[index];
            }
            return 0;
        }
        void display()
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(j>=i && i<=n)
                    {
                        int index = ((i*(i-1))/2)+j-1;
                        printf("%d ",a[index]);
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
    upperTriangularMatrix a = upperTriangularMatrix(2);
    a.setArray(1,1,1);
    a.setArray(1,2,4);
    a.setArray(2,2,5);
    a.display();
}