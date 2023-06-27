#include <stdio.h>
#include <stdlib.h>

struct node
{
    int column;
    int value;
    struct node *next;
};

void insert(struct node *m[], int n1, int n2, int value)
{
    n1--;
    n2--;
    if(m[n1] == NULL)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->value = value;
        n->column = n2;
        n->next = NULL;
        m[n1] = n;
    }
    else if(n2 != 1)
    {
        struct node *n, *p;
        n = (struct node *)malloc(sizeof(struct node));
        p = m[n1];
        while(p->next!= NULL && (p->next)->column<n2)
        {
            p = p->next;
        }
        n->value = value;
        n->next = p->next;
        n->column = n2;
        p->next = n;
    }
    else
    {
        if(m[n1]->column==1)
        {
            m[n1]->value = value;
        }
        else
        {
            struct node *n = (struct node *)malloc(sizeof(struct node));
            n->value = value;
            n->column = n2;
            n->next = m[n1];
            m[n1] = n;
        }
    }
}

void display(struct node *m[], int n1, int n2)
{
    for(int i = 0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            struct node *n;
            if(n == NULL)
            {
                printf("%d ",0);
            }
            else
            {
                n = m[i];
                while(n->next!=NULL && (n->next)->column<=j)
                {
                    n = n->next;
                }
                if(n->column==j)
                {
                    printf("%d ",n->value);
                }
                else
                {
                    printf("%d ",0);
                }
            }
        }
        printf("\n");
    }
}

void add(struct node *m1[], struct node *m2[], int n1, int n2, struct node *m[])
{
    struct node *i1, *i2, *i3;
    for(int i = 0; i<n1; i++)
    {
        i1 = m1[i];
        i2 = m2[i];
        if(i1 == NULL && i2 == NULL)
        {
            m[i] = NULL;
        }
        else
        {
            for(int j = 0; j<n2; j++)
            {
                i3 = m[i];
                int c = 0;
                while(i1->next != NULL && (i1->next)->column<=j)
                {
                    i1 = i1->next;
                }
                while(i2->next != NULL && (i2->next)->column<=j)
                {
                    i2 = i2->next;
                }
                struct node *n = (struct node *)malloc(sizeof(struct node));
                if(i1->column == i2->column && i1->column==j)
                {
                    n->value = i1->value + i2->value;
                    n->column = i1->column;
                    c = 1;
                }
                else if(i2->column==j)
                {
                    n->value = i2->value;
                    n->column = i2->column;
                    c = 1;
                }
                else if(i1->column==j)
                {
                    n->value = i1->value;
                    n->column = i1->column;
                    c = 1;
                }
                if(i3 == NULL && c == 1)
                {
                    m[i] = n;
                    n->next = NULL;
                }
                else if(c ==  1)
                {
                    while(i3->next != NULL && (i3->next)->column<=j)
                    {
                        i3 = i3->next;
                    }
                    n->next = i3->next;
                    i3->next = n;
                }
            }
        }
    }
}


int main()
{
    int n1 = 5;
    int n2 = 6;
    struct node *m1[n1];
    for(int i=0; i<n1; i++)
    {
        m1[i] = NULL;
    }
    insert(m1,1,5,8);
    insert(m1,2,4,7);
    insert(m1,3,1,5);
    insert(m1,3,5,9);
    insert(m1,4,6,3);
    insert(m1,5,1,6);
    insert(m1,5,4,4);
    display(m1,5,6);
    printf("\n");
    struct node *m2[n1];
    for(int i=0; i<n1; i++)
    {
        m2[i] = NULL;
    }
    insert(m2,1,5,8);
    insert(m2,2,4,7);
    insert(m2,3,1,5);
    insert(m2,3,5,9);
    insert(m2,4,6,3);
    insert(m2,5,1,6);
    // insert(m2,5,4,4);
    display(m2,5,6);
    printf("\n");
    struct node *m3[n1];
    for(int i=0; i<n1; i++)
    {
        m3[i] = NULL;
    }
    add(m1,m2,5,6,m3);
    display(m3,5,6);
}