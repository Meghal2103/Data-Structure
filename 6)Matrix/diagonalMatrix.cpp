#include <stdio.h>
#include <stdlib.h>

class diagonalArray
{
    private:
        int *a;
        int n;
    public:
        diagonalArray()
        {
            a = (int *)malloc(10*sizeof(int));
            n = 10;
        }

        diagonalArray(int size)
        {
            a = (int *)malloc(size*sizeof(int));
            n = size;
        }

        void setArray(int row, int coloumn, int value)
        {
            if(row==coloumn && row<=n)
            {
                a[row-1]=value;
            }
        }

        int getArray(int row, int coloumn)
        {
            if(row==coloumn && row<=n)
            {
                return a[row-1];
            }
            return 0;
        }

        void display()
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(i==j && i<n)
                    {
                        printf("%d ",a[i]);
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
    diagonalArray a = diagonalArray();
    a.setArray(1,1,8);
    a.setArray(2,2,8);
    a.setArray(3,3,8);
    a.setArray(4,4,8);
    a.setArray(5,5,8);
    a.display();
}
