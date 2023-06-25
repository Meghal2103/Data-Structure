#include<stdio.h>
#include<stdlib.h>

class node
{
    public:
        int value;
        node *next;
};

class linkedList
{
    public:
        node *LL;
    private:
        node *last;
    public:
        linkedList(int value)// creates 1st node of linkedList with value
        {
            node *n = (node *)malloc(sizeof(node));
            n->value = value;
            n->next = NULL;
            LL = n;
            last = n;
        }

        linkedList(int a[], int n)//array to linkedList
        {
            node *p;
            LL=(node *)malloc(sizeof(node));
            LL->value = a[0];
            LL->next = NULL;
            p=LL;
            last = LL;
            for(int i=1; i<n; i++)
            {
                node *n=(node *)malloc(sizeof(node));
                last->next=n;
                n->value = a[i];
                n->next = NULL;
                last = n;
            }
        }

        void appendArrayLL(int a[], int n)
        {
            for(int i=0; i<n; i++)
            {
                node *n=(node *)malloc(sizeof(node));
                last->next=n;
                n->value = a[i];
                n->next = NULL;
                last = n;
            }
        }

        void insertLinkedList(int pos, int value)
        {
            int count = countNodeIterative();
            if(pos>=0 && pos<=count)
            {
                node *n;        
                node *p;
                p = (node *)malloc(sizeof(node));
                if(pos!=0)
                {  
                    int flag = 0;
                    if(pos==count)      
                    {
                        flag = 1;
                    }
                    n = LL;
                    for(int i=1; i<pos; i++)
                    {
                        n=n->next;
                    }
                    p->value = value;
                    p->next = n->next;
                    n->next = p;
                    if(flag == 1)
                    {
                        last = p;
                    }
                }
                else
                {
                    p->next = LL;
                    p->value = value;
                    LL = p;
                }
            }
        }

        void insertLast(int value)
        {
            node * p;
            p = (struct node *)malloc(sizeof(struct node));
            last->next = p;
            p->value = value;
            p->next = NULL;
            last=last->next;
        }

        int deleteLinkedList(int pos)
        {
            struct node *p, *q, *r;
            p = LL;
            if(pos<-1 || pos>countNodeIterative())
                return INT_MAX;
            if(pos == 0)
            {
                LL = LL->next;
                int value = p->value;
                free(p);
                return value;
            }
            for(int i=1; i<pos; i++)
            {
                p = p->next;
            }
            q = p->next;
            r = q;
            q = q->next;
            int value = r->value;
            free(r);
            p->next = q;
            return value;
        }

        void display()
        {
            node *n = LL;
            while(n!=NULL)
            {
                printf("%d ", n->value);
                n = n->next;
            }
        }

        void display(node *head)  //displays reverse LinkedList
        {
            if(head!=NULL)
            {
                display(head->next);
                printf("%d ", head->value);
            }
        }

        int countNodeIterative()
        {
            node *n = LL;
            int count=0;
            while(n!=NULL)
            {
                count++;
                n = n->next;
            }
            return count;
        }

        int sumNodeIterative()
        {
            node *n = LL;
            int sum=0;
            while(n!=NULL)
            {
                sum = sum + n->value;
                n = n->next;
            }
            return sum;
        }

        void reverseLinkedList()
        {
            node *q = (node *)malloc(sizeof(node));
            node *p = (node *)malloc(sizeof(node));
            node *r = (node *)malloc(sizeof(node));
            q=LL;
            p=NULL;
            r=NULL;
            while (q!=NULL)
            {
                r = p;
                p = q;
                q = q->next;
                p->next = r;
            }
            LL=p;
        }

        int max()
        {
            node *n;
            int max = LL->value;
            n = LL->next;
            while(n!=NULL)
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
            while(n!=NULL)
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
            while(n!=NULL)
            {
                if(n->value == value)
                {
                    return n;
                }
                n = n->next;
            }
            return NULL;
        }

        int isSortedLinkedList()
        {
            int prev_value = LL->value;
            node *q = (node *)malloc(sizeof(node));
            q=LL->next;
            while(q!=NULL) 
            {
                if(prev_value > q->value)
                {
                    return 0;
                }
                prev_value = q->value;
                q=q->next;
            }
            return 1;
        }

        int isLoop()
        {
            node *p,*q;
            p=q=LL;
            do
            {
                p=p->next;
                q=q->next;
                q=q?q->next:q;
            }
            while(p && q && p!=q);
            return p==q?1:0;
        }    
};

int main()
{
    int a[]={1,2,3,4,5};
    linkedList ll = linkedList(a,5);
    // ll.appendArrayLL(a,5);
    // printf("%d\n", ll.min());
    // node *n = (node *)malloc(sizeof(node));
    // n->value = 6;
    // n->next =NULL;
    // ll.LL->next = n;
    // ll.insertLinkedList(0,-1);
    ll.display();
    // printf("%d",ll.isLoop());
    // ll.deleteLinkedList(0);
    ll.reverseLinkedList();
    ll.display();
    // ll.display(ll.LL);

}