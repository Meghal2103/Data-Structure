#include<stdio.h>
#include<stdlib.h>

class node
{
    public:
        int value;
        node *next;
};

class circularLinkedList
{
    public:
        node *LL;
    private:
        node *last;
    public:
        circularLinkedList()
        {
            LL = NULL;
        }

        circularLinkedList(int value)
        {
            node *n = (node *)malloc(sizeof(node));
            n->value = value;
            n->next = n;
            last = n;
            LL = n;
        }

        circularLinkedList(int a[], int n)//array to linkedList
        {
            node *p;
            LL=(node *)malloc(sizeof(node));
            LL->value = a[0];
            LL->next = LL;
            p=LL;
            last = LL;
            for(int i=1; i<n; i++)
            {
                node *n=(node *)malloc(sizeof(node));
                last->next=n;
                n->value = a[i];
                n->next = LL;
                last = n;
            }
        }

        void appendArray(int a[], int n)
        {
            for(int i=0; i<n; i++)
            {
                node *n=(node *)malloc(sizeof(node));
                last->next=n;
                n->value = a[i];
                n->next = LL;
                last = n;
            }
        }

        void insert(int pos, int value)
        {
            int c = count();
            if(pos>=0 && pos<=c)
            {
                struct node *n = LL;        
                struct node *p;
                p = (struct node *)malloc(sizeof(struct node));
                if(pos!=0)
                {        
                    n = LL;
                    for(int i=1; i<pos; i++)
                    {
                        n=n->next;
                    }
                    if(pos==c)
                    {
                        last = p;
                    }
                    p->value = value;
                    p->next = n->next;
                    n->next = p;
                }
                else
                {
                    p->value = value;
                    if(n != NULL)
                    {
                        while(n->next != LL)
                        {
                            n = n->next;
                        }
                        n->next = p;
                        p->next = LL;
                        LL = p;
                    }
                    else
                    {
                        LL = p;
                        p->next = LL;
                        last = LL;
                    }
                }
            }
        }

        void insertLast(int value)
        {
            node * p;
            p = (struct node *)malloc(sizeof(struct node));
            last->next = p;
            p->value = value;
            p->next = LL;
            last=last->next;
        }

        int deleteCLL(int pos)
        {
            if(pos>=0 && pos<count())
            {
                struct node *n = LL->next;  
                struct node *p = LL;
                struct node *r;
                if(pos!=0)
                {
                    for(int i=1; i<pos; i++)
                    {
                        n = n->next;
                        p = p->next;
                    }
                    r = n;
                    int value = r->value;
                    p->next = r->next;
                    last = p;
                    free(r);
                    return value;
                }
                else
                {
                    r = LL;
                    int value = r->value;
                    while(n->next != LL)
                    {
                        n = n->next;
                    }
                    n->next = LL->next;
                    LL = LL->next;
                    free(r);
                    return value;
                }
            }
            return INT_MAX;
        }

        void display()
        {
            struct node *pointer = LL;
            do
            {
                printf("%d ", pointer->value);
                pointer = pointer->next;
            }while(pointer != LL);
        }

        void display(node *pointer)
        {
            static int flag = 0;
            if(pointer != LL || flag == 0)
            {
                flag = 1;
                display(pointer->next);
                printf("%d ", pointer->value);
            }
            flag = 0;
        }

        int count()
        {
            int count=1;
            if(LL!=NULL)
            {
                struct node *pointer = LL->next;
                while(pointer!=LL)
                {
                    count++;
                    pointer = pointer->next;
                }
            }
            return count;
        }

        int sum()
        {
            int sum=LL->value;
            struct node *pointer = LL->next;
            while(pointer!=LL)
            {
                sum = sum + pointer->value;
                pointer = pointer->next;
            }
            return sum;
        }

        void reverse()
        {
            last = LL;
            node *q = (node *)malloc(sizeof(node));
            node *p = (node *)malloc(sizeof(node));
            node *r = (node *)malloc(sizeof(node));
            q=LL;
            p=NULL;
            r=NULL;
            while (q->next!=LL)
            {
                r = p;
                p = q;
                q = q->next;
                p->next = r;
            }
            r = p;
            p = q;
            q = q->next;
            p->next = r;
            LL=p;
            last->next = LL;
        }

        int max()
        {
            node *n;
            int max = LL->value;
            n = LL->next;
            while(n!=LL)
            {
                if((n->value)>max)
                {
                    max = n->value;
                }
                n = n->next;
            }
            return max;
        }

        int min()
        {
            node *n;
            int min = LL->value;
            n = LL->next;
            while(n!=LL)
            {
                if((n->value)<min)
                {
                    min = n->value;
                }
                n = n->next;
            }
            return min;
        }

        node * linearSearch(int value)
        {
            node *n = LL;
            do
            {
                if(n->value == value)
                {
                    return n;
                }
                n = n->next;
            }while(n!=LL);

            return NULL;
        }

        int isSorted()
        {
            int prev_value = LL->value;
            node *q = (node *)malloc(sizeof(node));
            q=LL->next;
            do
            {
                if(prev_value > q->value)
                {
                    return 0;
                }
                prev_value = q->value;
                q=q->next;
            }while(q!=LL);

            return 1;
        }
};

int main()
{
    int a[]={1,2,3,4,5};
    circularLinkedList ll = circularLinkedList();
    ll.insert(0,6);
    // ll.appendArrayCLL(a,5);
    // ll.insertCircularLinkedList(9,-1);
    // ll.insertLast(20);
    // ll.deleteCircularLinkedList(9);
    // ll.displayCircularLinkedList();
    // printf("%d", ll.sumLinkedList());
    // ll.reverse();
    // // printf("%d \n", ll.max());
    // printf("%d \n", ll.isSorted());
    // ll.linearSearch(6);
    ll.deleteCLL(5);
    ll.display();
}