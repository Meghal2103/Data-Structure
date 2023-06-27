#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int co_efficent;
    int power;
    struct node *next;
};

int polynomialEvaluation(struct node *p, int x)
{
    int result = 0;
    while (p != NULL)
    {
        result = result + (p->co_efficent * pow(x, p->power));
        p = p->next;
    }
    return result;
}

int polynomialAddition(struct node *a, struct node *b, struct node *c)
{
    struct node *p1, *p2, *p3, *node;
    p1 = a;
    p2 = b;
    p3 = c;
    while(p1!=NULL && p2!=NULL)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        if(p1->power == p2->power)
        {
            n->co_efficent = p1->co_efficent + p2->co_efficent;
            n->power = p1->power;
            n->next = NULL;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->power > p2->power)
        {
            n->co_efficent = p1->co_efficent;
            n->power = p1->power;
            n->next = NULL;
            p1 = p1->next;
        }
        else if(p1->power < p2->power)
        {
            n->co_efficent = p2->co_efficent;
            n->power = p2->power;
            n->next = NULL;
            p2 = p2->next;
        }
        if(p3==NULL)
        {
            p3 = n;
            node = n;
        }
        else
        {
            p3->next = n;
            p3 = n;
        }
        c = node;
    }
    while(p1!=NULL)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        if(p1!=NULL)
        {
            n->co_efficent = p1->co_efficent;
            n->power = p1->power;
            n->next = NULL;
            p1 = p1->next;
        }
        if(p3==NULL)
        {
            p3 = n;
        }
        else
        {
            p3->next = n;
            p3 = n;
        }
    }
    while(p2!=NULL)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        if(p2!=NULL)
        {
            n->co_efficent = p2->co_efficent;
            n->power = p2->power;
            n->next = NULL;
            p2 = p2->next;
        }
        if(p3==NULL)
        {
            p3 = n;
        }
        else
        {
            p3->next = n;
            p3 = n;
        }
    }

}

int main()
{
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    n1->co_efficent = 5;
    n1->power = 4;
    n2->co_efficent = 2;
    n2->power = 2;
    // n3->co_efficent = 5;
    // n3->power = 0;
    n1->next = n2;
    n2->next = NULL;
    n3->next = NULL;
    printf("%d\n", polynomialEvaluation(n1, 1));

    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    struct node *n5 = (struct node *)malloc(sizeof(struct node));
    struct node *n6 = (struct node *)malloc(sizeof(struct node));
    struct node *n7 = (struct node *)malloc(sizeof(struct node));
    struct node *n8 = (struct node *)malloc(sizeof(struct node));
    n4->co_efficent = 6;
    n4->power = 4;
    n5->co_efficent = 5;
    n5->power = 3;
    n6->co_efficent = 9;
    n6->power = 2;
    n7->co_efficent = 2;
    n7->power = 1;
    n8->co_efficent = 3;
    n8->power = 0;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = NULL;
    printf("%d\n", polynomialEvaluation(n4, 1));

    struct node *n9 = (struct node *)malloc(sizeof(struct node));
    n9 = NULL;
    polynomialAddition(n1,n4,n9);
    return 0;
}
