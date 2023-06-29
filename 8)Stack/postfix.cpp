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

int operatorPrecedence(char c)
{
    if(c == '-' || c == '+')
    {
        return 1;
    }
    else if(c == '/' || c == '*')
    {
        return 2;
    }
    return 0;
}

int ifOpenBracket(char c)
{
    if(c == '(')
    {
        return 1;
    }
    return 0;
}

void postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    stack s = stack();
    s.push('(');
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
            if(operatorPrecedence(s.stackTop())<operatorPrecedence(infix[i]) || ifOpenBracket(infix[i]))
            {
                s.push(infix[i]);
                i++;
            }
            else if(operatorPrecedence(s.stackTop())>=operatorPrecedence(infix[i]) && (infix[i]!=')'))
            {
                while(operatorPrecedence(s.stackTop())>=operatorPrecedence(infix[i]) && (s.stackTop()!='('))
                {
                    postfix[j] = s.pop();
                    j++;
                }  
            }
            else if (infix[i] == ')')
            {
                while (s.stackTop() != '(')
                {
                    postfix[j]=s.pop();
                    j++;
                }
                s.pop();
                i++;
            }
        }
    }
    while (s.stackTop() != '(')
    {
        postfix[j]=s.pop();
        j++;
    }
    s.pop();
    postfix[j] = '\0';
};

int main()
{
    char exp[] = "(a+(b*c-(d/e*f)*g)*h)";
    // char exp[] = "a+b*c";
    char pf[strlen(exp) + 1];
    // int i = paranthesisMatching(exp);
    // printf("%d\n", i);
    postfix(exp,pf);
}