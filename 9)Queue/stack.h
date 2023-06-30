#include <stdio.h>
#include <stdlib.h>

class node
{
    public:
        int value;
        node *next;
};

class stack
{
    private:
        class node *top;
    public:
        stack()
        {
            top = NULL;
        }

        int isEmpty()
        {
            if(top == NULL)
            {
                printf("Stack Empty\n");
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int isFull()
        {
            node *n = (node *)malloc(sizeof(node));
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

        int push(int value)
        {
            if(!isFull())
            {
                node *n = (node *)malloc(sizeof(node));
                n->value = value;
                n->next = top;
                top = n;
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int pop()
        {
            if(!isEmpty())
            {
                int value = top->value;
                top = top->next;
                return value;
            }
            else
            {
                printf("Stack Empty\n");
                return INT_MAX;
            }
        }

        int stackTop()
        {
            if(!isEmpty())
            {
                int value;
                value = top->value;
                return value;
            }
            else
            {
                printf("StackEmpty\n");
                return INT_MAX;
            }
        }

        void display()
        {
            struct node *n = top;
            while(n!=NULL)
            {
                printf("%d ", n->value);
                n = n->next;
            }
        }

};