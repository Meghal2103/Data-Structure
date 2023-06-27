#include<stdio.h>
#include<stdlib.h>

class circularDoublyLinkedListNode
{
    public:
        circularDoublyLinkedListNode *prev;
        int value;
        circularDoublyLinkedListNode *next;
};

class circularDoublyLinkedList
{
    public:
        circularDoublyLinkedListNode *LL;
    private:
        circularDoublyLinkedListNode *last;
    public:
        circularDoublyLinkedList(int value)
        {
            circularDoublyLinkedListNode *n = (circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
            n->value = value;
            n->next = n;
            n->prev = n;
            last = n;
            LL = n;
        }

        circularDoublyLinkedList(int a[], int n)
        {
            circularDoublyLinkedListNode *head = (circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
            head->prev = head;
            head->next = head;
            head->value = 0;
            last = head;
            for(int i=1; i<n; i++)
            {
                circularDoublyLinkedListNode *n = (circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
                n->value = a[i];
                last->next = n;
                n->next = NULL;
                n->prev = last;
                last = n;
            }
            last->next = head;
            head->prev = last;
            LL = head;
        }

        void appendArray(int a[], int n)
        {
            for(int i=1; i<n; i++)
            {
                circularDoublyLinkedListNode *n = (circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
                n->value = a[i];
                last->next = n;
                n->next = NULL;
                n->prev = last;
                last = n;
            }
            last->next = LL;
            LL->prev = last;
        }

        void insert(int pos, int value)
        {
            int c = count();
            if(pos>=0 && pos<=c)
            {
                if(pos!=0)
                {
                    circularDoublyLinkedListNode *n = LL;
                    circularDoublyLinkedListNode *p = (circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
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
                    if(n->next!=LL)
                    {
                        (n->next)->prev = p;
                    }
                    p->prev = n;
                    n->next = p;
                }
                else
                {
                    circularDoublyLinkedListNode *p = (circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
                    p->value = value;
                    p->next = LL;
                    p->prev = (LL->prev);
                    (LL->prev)->next = p;
                    LL->prev = p;
                    LL = p;
                }
            }
        }

        void insertLast(int value)
        {
            circularDoublyLinkedListNode * p;
            p = (struct circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
            p->value = value;
            p->next = LL;
            p->prev = LL->prev;
            (LL->prev)->next = p;
            LL->prev = p;
            last = p;
        }

        int deleteDLL(int pos)
        {
            int c = count();
            if(pos>=0 && pos<c)
            {
                if(pos!=0)
                {
                    circularDoublyLinkedListNode *n = LL;
                    circularDoublyLinkedListNode *node;
                    for(int i=1; i<=pos; i++)
                    {
                        n = n->next;
                    }
                    node = n;
                    (node->prev)->next = node->next;
                    (node->prev)->next = node->next;
                    if(node->next!=LL)
                    {
                        (node->next)->prev = node->prev;
                    }
                    if(pos == c-1)
                    {
                        last = node->prev;
                        LL->prev = last;
                    }
                    int value = node->value;
                    free(node);
                    return value;
                }
                else
                {
                    (LL->prev)->next = LL->next;
                    (LL->next)->prev = LL->prev;
                    circularDoublyLinkedListNode *node = LL;
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
            circularDoublyLinkedListNode *n = LL;
            do
            {
                printf("%d ", n->value);
                n = n->next;
            }while(n!=LL);
        }

        void display(circularDoublyLinkedListNode *pointer)
        {
            circularDoublyLinkedListNode *n = last;
            do
            {
                printf("%d ", n->value);
                n = n->prev;
            }while(n!=last);
        }

        int count()
        {
            circularDoublyLinkedListNode *n = LL;
            int count = 0;
            do
            {
                count++;
                n = n->next;
            }while(n!=LL);

            return count;
        }

        int sum()
        {
            circularDoublyLinkedListNode *n = LL;
            int sum = 0;
                do
                {
                    sum = sum + n->value;
                    n = n->next;
                }while(n!=LL);
            return sum;
        }

        void reverse()
        {
            circularDoublyLinkedListNode *n = LL;
            circularDoublyLinkedListNode *node;
            last = LL;
            do
            {
                node = n->next;
                n->next = n->prev;
                n->prev = node;
                n = n->prev;
                if(n != LL)
                {
                    LL = node;
                }
            }while(LL != last);
            LL = LL->next;
        }

        int max()
        {
            circularDoublyLinkedListNode *n;
            int max = LL->value;
            n = LL->next;
            do
            {
                if((n->value)>max)
                {
                    max = n->value;
                }
                n = n->next;
            }while(n!=LL);

            return max;
        }

        int min()
        {
            circularDoublyLinkedListNode *n;
            int min = LL->value;
            n = LL->next;
            do
            {
                if((n->value)<min)
                {
                    min = n->value;
                }
                n = n->next;
            }while(n!=LL);

            return min;
        }

        circularDoublyLinkedListNode * linearSearch(int value)
        {
            circularDoublyLinkedListNode *n = LL;
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

        int isSortedLinkedList()
        {
            int prev_value = LL->value;
            circularDoublyLinkedListNode *q = (circularDoublyLinkedListNode *)malloc(sizeof(circularDoublyLinkedListNode));
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
    int a[] = {0,1,2,3,4,5,6,7};
    circularDoublyLinkedList ll = circularDoublyLinkedList(6);
    // printf("%d\n", ll.isSortedLinkedList());
    // ll.insertLast(6);
    // // ll.deleteDLL(4);
    // // ll.appendArray(a,6);
    // ll.reverse(); 
    // ll.reverse(); 
    ll.insertLast(7);
    ll.display();
}