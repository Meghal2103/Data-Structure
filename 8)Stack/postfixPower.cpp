#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        void push(char value)
        {
            if(!isFull())
            {
                node *n = (node *)malloc(sizeof(node));
                n->value = value;
                n->next = top;
                top = n;
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
                // printf("StackEmpty\n");
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

int outSstackPrecedence(char c)
{
    if(c == '+' || c == '-')
    {
        return 1;
    }
    else if(c == '*' || c == '/')
    {
        return 3;
    }
    else if(c == '^')
    {
        return 6;
    }
    else if(c == '(')
    {
        return 7;
    }
    else if(c == ')')
    {
        return 0;
    }
    return 0;
}

int inStackPrecedence(char c)
{
    if(c == '+' || c == '-')
    {
        return 2;
    }
    else if(c == '*' || c == '/')
    {
        return 4;
    }
    else if(c == '^')
    {
        return 5;
    }
    else if(c == '(')
    {
        return 0;
    }
    return 0;
}

int isOperand(char c)
{
    if(c == '*' || c == '-' || c == '+' || c == '/' || c == '^' || c == '(' || c == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
};

void postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    stack s = stack();
    while (infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if(outSstackPrecedence(infix[i])>inStackPrecedence(s.stackTop()))
            {
                s.push(infix[i]);
                i++;
            }
            else if(outSstackPrecedence(infix[i])<inStackPrecedence(s.stackTop()))
            {
                postfix[j]=s.pop();
                j++;
            }
            else if(outSstackPrecedence(infix[i])==inStackPrecedence(s.stackTop()))
            {
                s.pop();
                i++;
            }
        }
    }
    while(s.stackTop() != NULL)
    {
        postfix[j]=s.pop();
        j++;
    }
    postfix[j] = '\0';
}

int main()
{
    char exp[] = "((a+b)*c)-d^e^f";
    char pf[strlen(exp) + 1];
    postfix(exp,pf);
}