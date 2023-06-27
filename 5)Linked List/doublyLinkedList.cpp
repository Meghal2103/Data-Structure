#include<stdio.h>
#include<stdlib.h>

class doublyLinkedListNode
{
    public:
        doublyLinkedListNode *prev;
        int value;
        doublyLinkedListNode *next;
};

class doublyLinkedList
{
    public:
        doublyLinkedListNode *LL;
    private:
        doublyLinkedListNode *last;
    public:
        doublyLinkedList(int value)
        {
            doublyLinkedListNode *n = (doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
            n->value = value;
            n->next = NULL;
            n->prev = NULL;
            last = n;
            LL = n;
        }

        doublyLinkedList(int a[], int n)
        {
            doublyLinkedListNode *head = (doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
            head->prev = NULL;
            head->next = NULL;
            head->value = 0;
            last = head;
            for(int i=1; i<n; i++)
            {
                doublyLinkedListNode *n = (doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
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
                doublyLinkedListNode *n=(doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
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
                    doublyLinkedListNode *n = LL;
                    doublyLinkedListNode *p = (doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
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
                    doublyLinkedListNode *p = (doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
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
            doublyLinkedListNode * p;
            p = (doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
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
                    doublyLinkedListNode *n = LL;
                    doublyLinkedListNode *node;
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
                    doublyLinkedListNode *node = LL;
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
            doublyLinkedListNode *n = LL;
            while(n!=NULL)
            {
                printf("%d ", n->value);
                n = n->next;
            }
        }

        void display(doublyLinkedListNode *pointer)
        {
            doublyLinkedListNode *n = last;
            while(n!=NULL)
            {
                printf("%d ", n->value);
                n = n->prev;
            }
        }

        int count()
        {
            doublyLinkedListNode *n = LL;
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
            doublyLinkedListNode *n = LL;
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
            doublyLinkedListNode *n = LL;
            doublyLinkedListNode *node;
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
            doublyLinkedListNode *n;
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
            doublyLinkedListNode *n;
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

        doublyLinkedListNode * linearSearch(int value)
        {
            doublyLinkedListNode *n = LL;
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
            doublyLinkedListNode *q = (doublyLinkedListNode *)malloc(sizeof(doublyLinkedListNode));
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
    ll.display();

}