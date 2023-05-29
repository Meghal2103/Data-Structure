#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *a;
    int size;
    int last;
};

void createArray(struct Array *a, int size)
{
    a->a = (int *)malloc(size*sizeof(int));
    a->size = size;
    a->last = -1;
}

void displayArray(struct Array a)
{
    for(int i=0; i<=a.last; i++)
    {
        printf("%d ", a.a[i]);
    }
    printf("\n");
}

void insertArray(struct Array *a, int index, int x)
{
    if(index>=0 && index<=a->last)
    {
        for(int i=a->last;i>=index;i--)
        {
            a->a[i+1] = a->a[i];
        }
    }
    a->a[index] = x;
    a->last++;
}

void AppendArray(struct Array *a, int x)
{
    if(a->last<a->size)
    {
        if(a->last==-1)
        {
            a->last=0;
            a->a[a->last] = x;
        }
        else
        {
            a->last++;
            a->a[a->last] = x;
        }
    }
}

int deleteArray(struct Array *a, int index)
{
    if(index>=0 && index<=a->last)
    {
        int x = a->a[index];
        for(int i=index;i<=a->last;i++)
        {
            a->a[i] = a->a[i+1];
        }
        a->last--;
        return x;
    }
}

int linearSearch(struct Array *a, int value)
{
    for(int i=0;i<a->last;i++)
    {
        if(a->a[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int gettArray(struct Array *a, int index)
{
    if(index>=0 && index<(a->last+1))
    {
        return a->a[index];
    }
}

void setArray(struct Array *a, int index, int value)
{
    if(index>=0 && index<(a->last+1))
    {
        a->a[index] = value;
    }
}

int maxArray(struct Array a)
{
    int max = a.a[0];
    for(int i=1; i<=a.last; i++)
    {
        if(max<a.a[i])
        {
            max = a.a[i];
        }
    }
    return max;
}

int minArray(struct Array a)
{
    int min = a.a[0];
    for(int i=1; i<=a.last; i++)
    {
        if(min>a.a[i])
        {
            min = a.a[i];
        }
    }
    return min;
}

int sumArray(struct Array a)
{
    int sum=0;
    for(int i=0; i<=a.last; i++)
    {
        sum = sum + a.a[i];
    }
    return sum;
}

float avgArray(struct Array a)
{
    float avg = (float)sumArray(a)/(a.last+1);
    return avg;
}

int binarySearch(struct Array *a, int value, int start, int end)
{
    // check if sorted
    if(end<start)
    {
        return -1;
    }
    int x = (start + end)/2;
    if(a->a[x]==value)
    {
        return x;
    }
    else if(a->a[x]<value)
    {
        return binarySearch(a, value,x+1,end);
    }
    return binarySearch(a, value,start,x-1);
}

int binarySearchloop(struct Array *a,int value,int start, int end)
{
    int x;
    while(start<=end)
    {
        x = (start+end)/2;
        if(a->a[x]==value)
        {
            return x;
        }
        else if(a->a[x]<value)
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

void reverseArrray(struct Array *a)
{
    int *b = (int*)malloc(sizeof(int)*a->size);
    for(int i=0; i<=a->last; i++)
    {
        b[i] = a->a[a->last-i];
    }
    free(a->a);
    a->a = b;
    b=NULL;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArraySwap(struct Array *a)
{
    for(int i=0; i<=(a->last)/2; i++)
    {
        swap(&(a->a[i]), &(a->a[a->last -i]));
    }
}

void leftShiftArray(struct Array *a)
{
    for(int i = 0; i < a->last; i++)
    {
        a->a[i] = a->a[i+1];
    }
    a->a[a->last] = 0;
}

void rightShiftArray(struct Array *a)
{
    for(int i = a->last; i>0; i--)
    {
        a->a[i] = a->a[i-1];
    }
    a->a[0] = 0;
}

void leftRotateArray(struct Array *a)
{
    int x = a->a[0];
    for(int i = 0; i < a->last; i++)
    {
        a->a[i] = a->a[i+1];
    }
    a->a[a->last] = x;
}

void rightRotateArray(struct Array *a)
{
    int x = a->a[a->last];
    for(int i = a->last; i>0 ; i--)
    {
        a->a[i] = a->a[i-1];
    }
    a->a[0] = x;
}

int isSorted(struct Array a)
{
    for(int i = 0; i < a.last; i++)
    {
        if(a.a[i] > a.a[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void insertSortedArray(struct Array *a, int value)
{
    int i=-1,j=0;
    if(isSorted(*a))
    {
        while(i==-1)
        {
            if(a->a[j] > value)
            {
                i=j;
                insertArray(a,i,value);
            }
            j++;
        }
    }
}

void rearrangeArrayPN(struct Array *a)
{
    int i=0,j=a->last;
    for(int k=0;k<a->last/2;k++)
    {
        while(a->a[i]<0)
        {
            i++;
        }
        while(a->a[j]>0)
        {
            j--;
        }
        swap(&(a->a[j]),&(a->a[i]));
    }
}

void merge(struct Array a,struct Array b, struct Array *c)
{
    createArray(c,(a.size+b.size));
    int i=0,j=0,k=0;
    while(k<=a.last+b.last+1) 
    {
        if((a.a[i]<b.a[j] && i<=a.last) || j>b.last)
        {
            c->a[k]=a.a[i];
            k++;
            i++;
        }
        else 
        {
            c->a[k]=b.a[j];
            k++;
            j++;
        }
    }
}

int main()
{
    struct Array a;
    struct Array b;
    struct Array c;
    createArray(&a,8);
    createArray(&b,4);
    AppendArray(&a,1);
    AppendArray(&a,3);
    AppendArray(&a,5);
    AppendArray(&a,7);
    // rearrangeArrayPN(&a);
    AppendArray(&b,2);
    AppendArray(&b,4);
    AppendArray(&b,6);
    AppendArray(&b,8);
    merge(a,b,&c);
    // insertArray(&a,1,1);
    // deleteArray(&a,1);
    // displayArray(a);
    // printf("%d ",binarySearch(&a,1,0,a.last));
    // printf("%d \n",maxArray(a));
    // printf("%d \n",minArray(a));
    // printf("%d \n",sumArray(a));
    // reverseArrray(&a);
    // reverseArraySwap(&a);
    // leftShiftArray(&a);
    // rightShiftArray(&a);
    // leftRotateArray(&a); 
    // rightRotateArray(&a);
    // int x = isSorted(a);
    // insertSortedArray(&a, 4);
}