#include <stdio.h>
#include <stdlib.h>
#include <D:\Data_Structure\10)Tree\queue.h>

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
                // printf("Stack Empty\n");
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

        void push(struct binaryTree *value)
        {
            if(!isFull())
            {
                node *n = (node *)malloc(sizeof(node));
                n->value = value;
                n->next = top;
                top = n;
            }
            else
            {
                printf("Stack Full\n");
            }
        }

        struct binaryTree *pop()
        {
            if(!isEmpty())
            {
                struct binaryTree *value = top->value;
                top = top->next;
                return value;
            }
            else
            {
                printf("Stack Empty\n");
                return NULL;
            }
        }

        struct binaryTree *stackTop()
        {
            if(!isEmpty())
            {
                struct binaryTree *value;
                value = top->value;
                return value;
            }
            else
            {
                printf("StackEmpty\n");
                return NULL;
            }
        }

        struct node *Top()
        {
            if(!isEmpty())
            {
                return top;
            }
            else
            {
                printf("StackEmpty\n");
                return NULL;
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