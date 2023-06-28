#include <stdio.h>
#include <stdlib.h>

class node
{
    public:
        char value;
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

        void push(char value)
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
                // printf("Stack Full\n");
            }
        }

        char pop()
        {
            if(!isEmpty())
            {
                char value = top->value;
                top = top->next;
                return value;
            }
            else
            {
                // printf("Stack Empty\n");
                return NULL;
            }
        }

        char stackTop()
        {
            if(!isEmpty())
            {
                char value;
                value = top->value;
                return value;
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
                printf("%c ", n->value);
                n = n->next;
            }
        }

};

int paranthesisMatching(char exp[])
{
    stack s = stack();
    char a = exp[0];
    int i = 0, j = 0;
    while(a!=NULL && i==0)
    {
        if(a == '(' || a == '{' || a == ']')
        {
            s.push(a);
        }
        else if(a ==')' || a == '}' || a == ']')
        {
            char b = s.pop();
            if(b  != NULL)
            {
                if(b == '(')
                {
                    if(a != ')')
                    {
                        i = 1;
                    }
                }
                else if(b == '{')
                {
                    if(a != '}')
                    {
                        i = 1;
                    }
                }
                else if (b == '[')
                {
                    if(a != ']')
                    {
                        i = 1;
                    }
                }
            }
            else
            {
                i = 1;
            }
        }
        j++;
        a = exp[j];
    }
    if(s.pop() != NULL)
    {
        i = 1;
    }
    return i;
}

int main()
{
    char exp[] = "((a+b)*(c-d))";
    int i = paranthesisMatching(exp);
    printf("%d\n", i);
}