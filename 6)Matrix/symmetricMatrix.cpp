#include <stdio.h>
#include <stdlib.h>

class symmetricMatrix
{
    private:
        int *a;
        int n;
    public:
        symmetricMatrix()
        {
            a = (int *)malloc(6*sizeof(int));
            n = 3;
        }

        symmetricMatrix(int size)
        {
            a = (int *)malloc(size*(size+1)*0.5*sizeof(int));
            n = size;
        }

        void setArray(int row, int coloumn, int value)
        {
            if (row>=coloumn && row<=n)
            {
                int index = ((row*(row-1))/2)+coloumn-1;
                a[index] = value;
            }
            else
            {
                int index = ((coloumn*(coloumn-1))/2)+row-1;
                a[index] = value;
            }
        }

        int getArray(int row, int coloumn)
        {
            if(row>=coloumn && row<=n)
            {
                int index = ((row*(row-1))/2)+coloumn-1;
                return a[index];
            }
            else
            {
                int index = ((coloumn*(coloumn-1))/2)+row-1;
                return a[index];
            }
        }
        
        void display()
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(i>=j && i<=n)
                    {
                        int index = ((i*(i-1))/2)+j-1;
                        printf("%d ",a[index]);
                    }
                    else
                    {
                        int index = ((j*(j-1))/2)+i-1;
                        printf("%d ",a[index]);
                    }
                }
                printf("\n");
            }
        }
};

int main()
{
    symmetricMatrix a = symmetricMatrix(2);
    a.setArray(1,1,1);
    a.setArray(2,1,4);
    a.setArray(2,2,5);
    a.display();
}