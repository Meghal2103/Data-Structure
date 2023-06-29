#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <D:\Data Structure\8)Stack\stack.h>

class nodeChar
{
    public:
        char value;
        nodeChar *next;
};

class stackChar
{
    private:
        class nodeChar *top;
    public:
        stackChar()
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
            nodeChar *n = (nodeChar *)malloc(sizeof(nodeChar));
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
                nodeChar *n = (nodeChar *)malloc(sizeof(nodeChar));
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
            nodeChar *n = top;
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
    stackChar s = stackChar();
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

int postfixEvaluation(char pf[])
{
    stack s = stack();
    int i = 0;
    while(pf[i] != '\0')
    {
        if(pf[i] == '+' || pf[i] == '-' || pf[i] == '*' || pf[i] == '/' || pf[i] == '^')
        {
            int a = s.pop();
            int b = s.pop();
            switch (pf[i])
            {
                case '+':
                    s.push(b+a);
                    break;
                case '-':
                    s.push(b-a);
                    break;
                case '*':
                    s.push(b*a);
                    break;
                case '/':
                    s.push(b/a);
                    break;
                case '^':
                    s.push(pow(b,a));
                    break;
            }
        }
        else
        {
            int a = (int)pf[i]-(int)'0';
            s.push(a);
        }
        i++;
    }
    return s.pop();
}

int main()
{
    char exp[] = "8-2+(3*4)/2^2";
    char pf[strlen(exp) + 1];
    postfix(exp,pf);
    printf("%d ", postfixEvaluation(pf));
}