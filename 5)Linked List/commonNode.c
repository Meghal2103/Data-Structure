#include <stdio.h>
#include <stdlib.h>
#include <D:\Data Structure\5)Linked List\linkedList.h>

void middle(linkedList ll)
{
    linkedList p1, p2;
    p1.LL = ll.LL;
    p2.LL = ll.LL;
    while(p1.LL != NULL)
    {
        p1.LL = (p1.LL)->next;
        if(p1.LL != NULL)
        {
            p1.LL = (p1.LL)->next;
        }
        if(p1.LL != NULL)
        {
            p2.LL = (p2.LL)->next;
        }
    }
    printf("\n%d\n",(p2.LL)->value);
}

void middleStack(linkedList ll)
{
    node *address[ll.count()];
    node *p = ll.LL;
    int top = 0;
    while(p != NULL)
    {
        address[top] = p;
        p = (p)->next; 
        top++;
    }
    for(int i=0; i<=top/2; i++)
    {
        top--;
    }
    printf("%d\n", address[top]->value);
}

int main()
{
    int a[] = {7,2,5,3,4};
    linkedList ll = linkedList(a,5);
    middleStack(ll);
    ll.display();
}