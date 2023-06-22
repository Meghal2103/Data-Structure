#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void displayLinkedList(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

int countNodeIterative(struct node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int countNodeRecursive(struct node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return countNodeRecursive(head->next)+1;
    }
}

int sumNodeIterative(struct node *head)
{
    int sum=0;
    while(head!=NULL)
    {
        sum = sum + head->value;
        head = head->next;
    }
    return sum;
}

int sumNodeRecursive(struct node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return sumNodeRecursive(head->next)+head->value;
    }
}

void displayRecursiveLinkedList(struct node *head)
{
    if(head!=NULL)
    {
        printf("%d ", head->value);
        displayRecursiveLinkedList(head->next);
    }
}

void displayReverseLinkedList(struct node *head)
{
    if(head!=NULL)
    {
        displayReverseLinkedList(head->next);
        printf("%d ", head->value);
    }
}

struct node * arrayToLinkedList(int a[], int n)
{
    struct node *head,*p;
    head=(struct node *)malloc(sizeof(struct node));
    head->value = a[0];
    head->next = NULL;
    p=head;
    for(int i=1; i<n; i++)
    {
        struct node *n=(struct node *)malloc(sizeof(struct node));
        n->value = a[i];
        n->next = NULL;
        p->next = n;
        p = n;
    }
    return head;
}

int max(struct node *head)
{
    struct node *n;
    int max = head->value;
    n = head->next;
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

int maxRecursive(struct node *head)
{
    if(head == NULL)
    {
        return INT_MIN;
    }
    int max = maxRecursive(head->next);
    {
        if(head->value>max)
        {
            max = head->value;
        }
    }
    return max;
}

int min(struct node *head)
{
    struct node *n;
    int min = head->value;
    n = head->next;
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

int minRecursive(struct node *head)
{
    if(head == NULL)
    {
        return INT_MAX;
    }
    int min = minRecursive(head->next);
    {
        if(head->value<min)
        {
            min = head->value;
        }
    }
    return min;
}

void moveStarting(struct node **head, int pos)
{
    struct node *p;
    struct node *h=*head;
    for(int i=0;i<pos-1;i++)
    {
        h = h->next;
    }
    if(h->next != NULL)
    {
        p=h->next;
        h->next=p->next;
        p->next=*head;
        *head=p;
    }
}

struct node * linearSearch(struct node *head, int value)
{
    while(head!=NULL)
    {
        if(head->value == value)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

struct node * recursiveLinearSearch(struct node *head, int value)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->value == value)
    {
        return head;
    }
    return recursiveLinearSearch(head->next,value);
}

void inserLinkedList(struct node **head, int pos, int value)
{
    if(pos>=0 && pos<=countNodeIterative(*head))
    {
        struct node *n;        
        struct node *p;
        p = (struct node *)malloc(sizeof(struct node));
        if(pos!=0)
        {        
            n = *head;
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
            p->next = *head;
            p->value = value;
            *head = p;
        }
    }
}

// void inserLinkedListf(struct node *head, int pos, int value)
// {
//     // if(pos>=0 && pos<countNodeIterative(head));
//     struct node *n;        
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));
//     if(pos!=0)
//     {        
//         n = head;
//         for(int i=1; i<pos; i++)
//         {
//             n=n->next;
//         }
//         p->value = value;
//         p->next = n->next;
//         n->next = p;
//     }
//     else
//     {
//         p->next = head;
//         p->value = value;
//         head = p;
//     }
// }

void insertLast(struct node *head, struct node ** last, int value)
{
    struct node * p;
    p = (struct node *)malloc(sizeof(struct node));
    if(*last == NULL)
    {
        *last = head;
        while ((*last)->next!=NULL)
        {
            *last = (*last)->next;
        }
        
    }
    (*last)->next = p;
    p->value = value;
    p->next = NULL;
    (*last)=(*last)->next;
}

void insertSorted(struct node **head, int value)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
    struct node *r = (struct node *)malloc(sizeof(struct node));
    p = *head;
    int i=0;
    while(p!=NULL && value>p->value) 
    {
        q = p;
        p = p->next;
        i++;
    }
    if(i==0)
    {
        r->next = p;
        r->value = value;
        *head = r;
    }
    else
    {
        r->next = p;
        r->value = value;
        q->next = r;
    }
} 

int main()
{
    struct node *head=NULL;
    struct node *n;
    struct node *last=NULL;
    int a[]={1,2,3,4,5,6};
    head = arrayToLinkedList(a,6);
    insertSorted(&head,0);
    insertLast(head,&last,4);
    // printf("%d", countNodeIterative(head));
    // printf("%d",minRecursive(head));
    // displayLinkedList(head);
    // printf("\n");
    // displayRecursiveLinkedList(head);
    // printf("\n");
    // displayReverseLinkedList(head);
    // printf("%d\n%d",countNodeIterative(head),countNodeRecursive(head));
    // printf("\n");
    // printf("%d\n%d",sumNodeIterative(head),sumNodeRecursive(head));
    // displayLinkedList(head);
    // moveStarting(&head,5);
    // n=recursiveLinearSearch(head,7);
    // if(n!=NULL)
    // {
    //     printf("%d",n->value);
    // }
    // displayLinkedList(head);
    // inserLinkedList(&head,0,8);                      
    // printf("\n");
    displayLinkedList(head);
}

