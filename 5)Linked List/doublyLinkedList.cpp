#include<stdio.h>
#include<stdlib.h>

class node
{
    public:
        node *prev;
        int value;
        node *next;
};

class doublyLinkedList
{
    public:
        node *LL;
    private:
        node *last;
    public:
        doublyLinkedList(int value)
        {
            node *n = (node *)malloc(sizeof(node));
            n->value = value;
            n->next = n;
            last = n;
            LL = n;
        }

        doublyLinkedList(int a[], int n)
        {
            node *head = (node *)malloc(sizeof(node));
            head->prev = NULL;
            head->next = NULL;
            head->value = 0;
            last = head;
            for(int i=1; i<n; i++)
            {
                node *n = (node *)malloc(sizeof(node));
                n->value = a[i];
                last->next = n;
                n->next = NULL;
                n->prev = last;
                last = n;
            }
            LL = head;
        }

        void appendArray(int a[], int n)
        {
            for(int i=0; i<n; i++)
            {
                node *n=(node *)malloc(sizeof(node));
                n->prev = last;
                last->next = n;
                n->value = a[i];
                n->next = NULL;
                last = n;
            }
        }

        void insert(int pos, int value)
        {
            int c = count();
            if(pos>=0 && pos<=c)
            {
                if(pos!=0)
                {
                    node *n = LL;
                    node *p = (node *)malloc(sizeof(node));
                    for(int i=1; i<pos; i++)
                    {
                        n = n->next;
                    }
                    if(pos==c)
                    {
                        last = p;
                    }
                    p->value = value;
                    p->next = n->next;
                    if(n->next!=NULL)
                    {
                        (n->next)->prev = p;
                    }
                    p->prev = n;
                    n->next = p;
                }
                else
                {
                    node *p = (node *)malloc(sizeof(node));
                    p->next = LL;
                    p->prev = NULL;
                    p->value = value;
                    LL->prev = p;
                    LL = p;
                }
            }
        }

        void insertLast(int value)
        {
            node * p;
            p = (struct node *)malloc(sizeof(struct node));
            p->prev = last;
            last->next = p;
            p->value = value;
            p->next = NULL;
            last=last->next;
        }

        int deleteDLL(int pos)
        {
            int c = count();
            if(pos>=0 && pos<c)
            {
                if(pos!=0)
                {
                    node *n = LL;
                    node *node;
                    for(int i=1; i<=pos; i++)
                    {
                        n = n->next;
                    }
                    node = n;
                    (node->prev)->next = node->next;
                    if(node->next!=NULL)
                    {
                        (node->next)->prev = node->prev;
                    }
                    if(pos == c-1)
                    {
                        last = node->prev;
                    }
                    int value = node->value;
                    free(node);
                    return value;
                }
                else
                {
                    (LL->next)->prev = NULL;
                    node *node = LL;
                    LL = LL->next;
                    int value = LL->value;
                    free(node);
                    return value;
                }
            }
            return INT_MAX;
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

        void display(node *pointer)
        {
            node *n = last;
            while(n!=NULL)
            {
                printf("%d ", n->value);
                n = n->prev;
            }
        }

        int count()
        {
            node *n = LL;
            int count = 1;
            while(n!=NULL)
            {
                count++;
                n = n->next;
            }
            return count;
        }

        int sum()
        {
            node *n = LL;
            int sum = 0;
            while(n!=NULL)
            {
                sum = sum + n->value;
                n = n->next;
            }
            return sum;
        }

        void reverse()
        {
            node *n = LL;
            node *node;
            last = LL;
            while(n != NULL)
            {
                node = n->next;
                n->next = n->prev;
                n->prev = node;
                n = n->prev;
                if(n != NULL)
                {
                    LL = node;
                }
            }
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

};

int main()
{
    int a[] = {0,1,2,3,4,5,6,7};
    doublyLinkedList ll = doublyLinkedList(a,6);
    // ll.appendArray(a,8);
    // ll.insert(8,9);
    // ll.deleteDLL(8);
    // printf("%d ", ll.min());
    ll.reverse();
    ll.display(ll.LL);

}