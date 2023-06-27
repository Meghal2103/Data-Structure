#include <stdio.h>
#include <stdlib.h>

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

        void appendArray(int a[], int n)
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

        void insert(int pos, int value)
        {
            int c = count();
            if(pos>=0 && pos<=c)
            {
                node *n;        
                node *p;
                p = (node *)malloc(sizeof(node));
                if(pos!=0)
                {  
                    if(pos==c)      
                    {
                        last = p;
                    }
                    n = LL;
                    for(int i=1; i<pos; i++)
                    {
                        n=n->next;
                    }
                    p->value = value;
                    p->next = n->next;
                    n->next = p;
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

        int deleteLinkedList(int pos)//last pointer
        {
            struct node *p, *q, *r;
            p = LL;
            int c = count();
            if(pos<-1 || pos>c)
                return INT_MAX;
            if(pos == 0)
            {
                LL = LL->next;
                int value = p->value;
                free(p);
                return value;
            }
            if(pos != c-1)
            {
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
            else
            {
                for(int i=1; i<pos; i++)
                {
                    last = p;
                    p = p->next;
                }
                last = p;
                r = p->next;
                p->next = (p->next)->next;
                int value = r->value;
                free(r);
                return value;
            }
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

        int count()
        {
            node *n = LL;
            int count = 0;
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
            int sum=0;
            while(n!=NULL)
            {
                sum = sum + n->value;
                n = n->next;
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
