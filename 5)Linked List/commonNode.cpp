#include <stdio.h>
#include <stdlib.h>
#include <D:\Data Structure\5)Linked List\linkedList.h>

node * commonNode(linkedList ll1, linkedList ll2)
{

    node *address1[ll1.count()], *address2[ll2.count()];
    node *p = ll1.LL;
    int top1 = 0, top2 =0;
    while(p != NULL)
    {
        address1[top1] = p;
        p = (p)->next; 
        top1++;
    }
    p = ll2.LL;
    while(p != NULL)
    {
        address2[top2] = p;
        p = (p)->next; 
        top2++;
    }
    node *address = NULL;
    top1--;
    top2--;
    while(address1[top1] == address2[top2])
    {
        address = address1[top1];
        top1--;
        top2--;
    }
    return address;
}

int main()
{
    int a[] = {7,2,5,3,4};
    int b[] = {1,2,3,4};
    int c[] = {5,6,7};
    linkedList ll1 = linkedList(b,4);
    linkedList ll2 = linkedList(c,3);
    linkedList ll = linkedList(a,5);
    node *n = ll1.LL;
    while(n->next != NULL)
    {
        n = n->next;
    }
    n->next = ll.LL;
    n = ll2.LL;
    while(n->next != NULL)
    {
        n = n->next;
    }
    n->next = ll.LL;
    commonNode(ll1, ll2);
    ll1.display();
    printf("\n");
    ll2.display();
}