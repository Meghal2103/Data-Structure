#include<stdio.h>
#include<stdlib.h>

struct doublyLLNode
{
    struct doublyLLNode *prev;
    int value;
    struct doublyLLNode *next;
};

struct doublyLLNode * arrayToLinkedList(int a[], int n)
{
    struct doublyLLNode *head = (struct doublyLLNode *)malloc(sizeof(struct doublyLLNode));
    struct doublyLLNode *last;
    head->prev = NULL;
    head->next = NULL;
    head->value = 0;
    last = head;
    for(int i=1; i<n; i++)
    {
        struct doublyLLNode *n = (struct doublyLLNode *)malloc(sizeof(struct doublyLLNode));
        n->value = a[i];
        last->next = n;
        n->next = NULL;
        n->prev = last;
        last = n;
    }
    return head;
}

int count(struct doublyLLNode * head)
{
    struct doublyLLNode *n = head;
    int count = 0;
    while(n!=NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}

void insert(struct doublyLLNode **head, int pos, int value)
{
    if(pos>=0 && pos<=count(*head))
    {
        if(pos!=0)
        {
            struct doublyLLNode *n = *head;
            struct doublyLLNode *node = (struct doublyLLNode *)malloc(sizeof(struct doublyLLNode));
            for(int i=1; i<pos; i++)
            {
                n = n->next;
            }
            node->value = value;
            node->next = n->next;
            if(n->next!=NULL)
            {
                (n->next)->prev = node;
            }
            node->prev = n;
            n->next = node;
        }
        else
        {
            struct doublyLLNode *node = (struct doublyLLNode *)malloc(sizeof(struct doublyLLNode));
            node->next = *head;
            node->prev = NULL;
            node->value = value;
            (*head)->prev = node;
            *head = node;
        }
    }
}

int delete(struct doublyLLNode **head, int pos)
{
    if(pos>=0 && pos<count(*head))
    {
        if(pos!=0)
        {
            struct doublyLLNode *n = *head;
            struct doublyLLNode *node;
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
            int value = node->value;
            free(node);
            return value;
        }
        else
        {
            ((*head)->next)->prev = NULL;
            struct doublyLLNode *node = *head;
            *head = (*head)->next;
            int value = node->value;
            free(node);
            return value;
        }
    }
}

void display(struct doublyLLNode *head)
{
    struct doublyLLNode *n = head;
    while(n!=NULL)
    {
        printf("%d ", n->value);
        n = n->next;
    }
}

int main()
{
    struct doublyLLNode *head;
    // struct doublyLLNode *last;
    // head->prev = NULL;
    // head->next = NULL;
    // head->value = 0;
    // last = head;
    // for(int i=1; i<5; i++)
    // {
    //     struct doublyLLNode *n = (struct doublyLLNode *)malloc(sizeof(struct doublyLLNode));
    //     n->value = i;
    //     last->next = n;
    //     n->next = NULL;
    //     n->prev = last;
    //     last = n;
    // }
    int a[] = {0,1,2,3,4,5};
    head = arrayToLinkedList(a,6);
    // insert(&head,1,-1);
    display(head);
    printf("\n%d\n", delete(&head,1));
    display(head);
}