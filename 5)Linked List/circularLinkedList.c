#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void displayCircularLinkedList(struct node *head)
{
    struct node *pointer = head;
    do
    {
        printf("%d ", pointer->value);
        pointer = pointer->next;
    }while(pointer != head);
}

void displayCircularLinkedListRecursive(struct node *head, struct node *pointer)
{
    static int flag = 0;
    if(pointer != head || flag == 0)
    {
        flag = 1;
        // printf("%d ", pointer->value);
        displayCircularLinkedListRecursive(head, pointer->next);
        printf("%d ", pointer->value);
    }
    flag = 0;
}

int countLinkedList(struct node *head)
{
    int count=1;
    struct node *pointer = head->next;
    while(pointer!=head)
    {
        count++;
        pointer = pointer->next;
    }
    return count;
}

void insertCircularLinkedList(struct node **head, int pos, int value)
{
    if(pos>=0 && pos<=countLinkedList(*head))
    {
        struct node *n = *head;        
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
            p->value = value;
            if(n != NULL)
            {
                while(n->next != *head)
                {
                    n = n->next;
                }
                n->next = p;
                p->next = *head;
                *head = p;
            }
            else
            {
                *head = p;
                p->next = *head;
            }
        }
    }
}

int deleteCircularLinkedList(struct node **head, int pos)
{
    if(pos>=0 && pos<countLinkedList(*head))
    {
        struct node *n = (*head)->next;  
        struct node *p = *head;
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
            free(r);
            return value;
        }
        else
        {
            r = *head;
            int value = r->value;
            while(n->next != *head)
            {
                n = n->next;
            }
            n->next = (*head)->next;
            (*head) = (*head)->next;
            free(r);
            return value;
        }
    }
}

int main()
{
    struct node *head=NULL;
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n1;
    n1->value = 1;
    n2->value = 2;
    n3->value = 3;
    n4->value = 4;
    // // displayCircularLinkedList(head);
    // insertCircularLinkedList(&head,0,8);
    // printf("%d ", countLinkedList(head));
    // insertCircularLinkedList(&head, 0, -1);
    displayCircularLinkedList(head);
    // deleteCircularLinkedList(&head,0);
    displayCircularLinkedListRecursive(head, head);
}

