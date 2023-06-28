#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct stack
{
    struct node *top;
};

void create(struct stack *s)
{
    s->top = NULL;
}

int isEmpty(struct stack *s)
{
    if(s->top == NULL)
    {
        printf("Stack Empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("Stack Full\n");
        return 1;
    }
    else
    {
        free(n);
        return 0;
    }
}

void push(struct stack *s, int value)
{
    if(!isFull(s))
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->value = value;
        n->next = s->top;
        s->top = n;
    }
    else
    {
        printf("Stack Full\n");
    }
}

int pop(struct stack *s)
{
    if(!isEmpty(s))
    {
        int value = s->top->value;
        s->top = s->top->next;
        return value;
    }
    else
    {
        printf("Stack Empty\n");
    }
}

int stackTop(struct stack *s)
{
    if(!isEmpty(s))
    {
        int value;
        value = s->top->value;
        return value;
    }
    else
    {
        printf("StackEmpty\n");
        return INT_MAX;
    }
}

void display(struct stack *s)
{
    struct node *n = s->top;
    while(n!=NULL)
    {
        printf("%d ", n->value);
        n = n->next;
    }
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s);
    printf("%d\n", isEmpty(s));
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    pop(s);
    printf("%d\n", stackTop(s));
    display(s);
}