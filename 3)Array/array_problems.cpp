#include <stdio.h>
#include <stdlib.h>

class intArray
{
    private:
        int *a;
        int size;
        int last;
        void swap(int *a, int *b)
        {
            int temp;
            temp = *a;
            *a = *b;
            *b = temp;
        };
    public:
        intArray()
        {
            a = (int *)malloc(10*sizeof(int));
            size = size;
            last = -1;
        }

        intArray(int size)
        {
            a = (int *)malloc(size*sizeof(int));
            size = size;
            last = -1;
        }

        void displayArray()
        {
            for(int i=0; i<=last; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
        }

        void insertArray(int index, int x)
        {
            if(index>=0 && index<=last)
            {
                for(int i=last;i>=index;i--)
                {
                    a[i+1] = a[i];
                }
            }
            a[index] = x;
            last++;
        }

        void AppendArray(int x)
        {
            if(last<size)
            {
                if(last==-1)
                {
                    last=0;
                    a[last] = x;
                }
                else
                {
                    last++;
                    a[last] = x;
                }
            }
        }

        int deleteArray(int index)
        {
            if(index>=0 && index<=last)
            {
                int x = a[index];
                for(int i=index;i<=last;i++)
                {
                    a[i] = a[i+1];
                }
                last--;
                return x;
            }
            return -1;
        }

        int getArray(int index)
        {
            if(index>=0 && index<(last+1))
            {
                return a[index];
            }
            return -1;
        }

        void setArray(int index, int value)
        {
            if(index>=0 && index<(last+1))
            {
                a[index] = value;
            }
        }

        int maxArray()
        {
            int max = a[0];
            for(int i=1; i<=last; i++)
            {
                if(max<a[i])
                {
                    max = a[i];
                }
            }
            return max;
        }

        int minArray()
        {
            int min = a[0];
            for(int i=1; i<=last; i++)
            {
                if(min>a[i])
                {
                    min = a[i];
                }
            }
            return min;
        }

        int sumArray()
        {
            int sum=0;
            for(int i=0; i<=last; i++)
            {
                sum = sum + a[i];
            }
            return sum;
        }

        float avgArray()
        {
            float avg = (float)sumArray()/(last+1);
            return avg;
        }

        int binarySearchloop(int value,int start, int end)
        {
            int x;
            while(start<=end)
            {
                x = (start+end)/2;
                if(a[x]==value)
                {
                    return x;
                }
                else if(a[x]<value)
                {
                    start=x+1;
                }
                else
                {
                    end=x-1;
                }
            }
            return -1;
        }

        void reverseArray()
        {
            for(int i=0; i<=(last)/2; i++)
            {
                swap(&(a[i]), &(a[last -i]));
            }
        }

        void leftShiftArray()
        {
            for(int i = 0; i < last; i++)
            {
                a[i] = a[i+1];
            }
            a[last] = 0;
        }

        void rightShiftArray()
        {
            for(int i = last; i>0; i--)
            {
                a[i] = a[i-1];
            }
            a[0] = 0;
        }

        void leftRotateArray()
        {
            int x = a[0];
            for(int i = 0; i < last; i++)
            {
                a[i] = a[i+1];
            }
            a[last] = x;
        }

        void rightRotateArray()
        {
            int x = a[last];
            for(int i = last; i>0 ; i--)
            {
                a[i] = a[i-1];
            }
            a[0] = x;
        }

        int isSorted()
        {
            for(int i = 0; i < last; i++)
            {
                if(a[i] > a[i+1])
                {
                    return 0;
                }
            }
            return 1;
        }

        void insertSortedArray(int value)
        {
            int i=-1,j=0;
            if(isSorted())
            {
                while(i==-1)
                {
                    if(a[j] > value)
                    {
                        i=j;
                        insertArray(i,value);
                    }
                    j++;
                }
            }
        }

        // int oneMissingElement()
        // {
        //     int sum1 = ((a[last]*a[last])-a[last])/2;
        //     int sum2 = ((a[0]*a[0])-a[0])/2;
        //     int x = sum1-sum2;
        //     int sum=0;
        //     for(int i = 0; i <last; i++) 
        //     {
        //         sum = sum +a[i];
        //     }
        //     return x-sum;
        // }

        // void multipleMissingElementSortedArray()
        // {
        //     int diff = a[0];
        //     for(int i = 0; i < last; i++)
        //     {
        //         if(a[i]!=diff)
        //         {
        //             while(diff<a[i]-i)
        //             {
        //                 printf("%d\n",diff+i);
        //                 diff++;
        //             }
        //         }
        //     }
        // }

        void multipleMissingElementArray()
        {
            int max = maxArray();
            int min = minArray();
            int c[max-min+1]={0};
            for(int i=0;i<max-min-1;++i)
            {
                c[a[i]]++;
            }
            for(int i=0;i<max-min-1;++i)
            {
                if(c[i]==0)
                {
                    printf("%d ",i+min);
                }
            }
        }

        void findDuplicateElementSortedArray()
        {
            for(int i=0;i<last;++i)
            {
                if(a[i]==a[i+1])
                {
                    int j=i+1;
                    while(a[i]==a[j])
                    {
                        j++;
                    }
                    printf("%d %d\n", a[i],j-i);
                    i=j-1;
                }
            }
        }

        void findDuplicateElementHash()
        {
            int max = maxArray();
            int min = minArray();
            int c[max-min+1]={0};
            for(int i=0;i<=last;++i)
            {
                c[a[i]]++;
            }

            for(int i=0;i<max-min+1;i++)
            {
                if(c[i]!=0)
                {
                    printf("%d %d\n",i,c[i]);
                }
            }
        }

        void findpairArray(int x)
        {
            int max = maxArray();
            int min = minArray();
            int c[max-min+1]={0};
            for(int i=0;i<=last;++i)
            {
                c[a[i]]++;
            }
            for(int i=0;i<last;++i)
            {
                if(c[x-a[i]+min]!=0 && (x-a[i]+min)<max-min+1)
                {
                    printf("%d %d\n",x-a[i]+min,a[i]);
                }
            }
        }

        void findpairSortedArray(int x)
        {
            if(isSorted())
            {
                int i = 0;
                int j = last;
                while(i<=j)
                {
                    if(a[i]+a[j] > x)
                    {
                        j--;
                    }
                    else if(a[i]+a[j] < x)
                    {
                        i++;
                    }
                    else
                    {
                        printf("%d %d\n",a[i],a[j]);
                        i++;
                        j--;
                    }
                }
            }
        }

        ~intArray()
        {
            free(a);
        }
};

int main()
{
    intArray a=intArray(8);
    a.AppendArray(0);
    a.AppendArray(1);
    a.AppendArray(2);
    a.AppendArray(3);
    a.AppendArray(7);
    a.AppendArray(8);
    a.AppendArray(9);
    // a.displayArray();
    // printf("%d",a.oneMissingElement());
    a.findpairSortedArray(10);
}