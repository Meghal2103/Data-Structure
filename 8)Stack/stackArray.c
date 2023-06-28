#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *s;
};

void create(struct stack *s, int len)
{
    s->top = -1;
    s->size = len;
    s->s = (int *)malloc(len*sizeof(int));
};

int isFull(struct stack *s)
{
    if(s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, int value)
{
    if(!isFull(s))
    {
        (s->top)++;
        s->s[s->top] = value;

    }
    else
    {
        printf("StackFull");
    }
}

int pop(struct stack *s)
{
    if(!isEmpty(s))
    {
        int value;
        value = s->s[s->top];
        s->top--;
        return value;
    }
    else
    {
        printf("StackEmpty");
        return INT_MAX;
    }
}

int stackTop(struct stack *s)
{
    if(!isEmpty(s))
    {
        int value;
        value = s->s[s->top];
        return value;
    }
    else
    {
        printf("StackEmpty");
        return INT_MAX;
    }
}

void display(struct stack *s)
{
    int i = s->top;
    for(i; i>-1; i--)
    {
        printf("%d ", s->s[i]);
    }
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s,6);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    printf("%d \n", isFull(s));
    pop(s);
    pop(s);
    display(s);
    printf("%d \n", isEmpty(s));
}