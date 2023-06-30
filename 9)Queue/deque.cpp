#include <stdio.h>
#include <stdlib.h>

class node
{
    public:
        node *prev;
        int value;
        node *next;
};

class deque
{
    public:
        node *front;
        node *rear;

        deque()
        {
            front = NULL;
            rear = NULL;
        }

        int isEmpty()
        {
            if (front == rear && rear == NULL)
            {
                return 1;
            }
            return 0;
        }

        int isFull()
        {
            node *n = (node *)malloc(sizeof(node));
            if(n == NULL)
            {
                free(n);
                return 1;
            }
            return 0;
        }

        void enQueueR(int value)
        {
            if(!isFull())
            {
                if(front == NULL && rear == NULL)
                {
                    node *n = (node *)malloc(sizeof(node));
                    n->value = value;
                    n->next = NULL;
                    n->prev = NULL;
                    front = n;
                    rear = n;
                }
                else
                {
                    node *n = (node *)malloc(sizeof(node));
                    n->value = value;
                    n->prev = rear;
                    rear->next = n;
                    n->next = NULL;
                    rear = n;
                }
            }
        }
                
        void enQueueF(int value)
        {
            if(!isFull())
            {
                if(front == NULL && rear == NULL)
                {
                    node *n = (node *)malloc(sizeof(node));
                    n->value = value;
                    n->next = NULL;
                    n->prev = NULL;
                    front = n;
                    rear = n;
                }
                else
                {
                    node *n = (node *)malloc(sizeof(node));
                    n->value = value;
                    n->next = front;
                    front->prev = n;
                    n->prev = NULL;
                    front = n;
                }
            }
        }

        int deQueueF()
        {
            if(!isEmpty())
            {
                if(front->next == NULL && front->prev == NULL)
                {
                    node *n;
                    n = rear;
                    int value  = n->value;
                    front = NULL;
                    rear = NULL;
                    free(n);
                    return value;
                }
                else
                {
                    node *n;
                    n = front;
                    front = front->next;
                    front->prev = NULL;
                    int value = n->value;
                    free(n);
                    return value;
                }
            }
            return INT_MAX;
        }

        int deQueueR()
        {
            if(!isEmpty())
            {
                if(rear->next == NULL && rear->prev == NULL)
                {
                    node *n;
                    n = rear;
                    int value  = n->value;
                    front = NULL;
                    rear = NULL;
                    free(n);
                    return value;
                }
                else
                {
                    node *n;
                    n = rear;
                    rear = rear->prev;
                    if(rear!=NULL)
                    rear->next = NULL;
                    int value = n->value;
                    free(n);
                    return value;
                }
            }
            return INT_MAX;
        }

        int firstQueue()
        {
            if(!isEmpty())
            {
                return front->value;
            }
            else
            {
                printf("QueueEmpty");
                return INT_MAX;
            }
        }

        int lastQueue()
        {
            if(!isEmpty())
            {
                return rear->value;
            }
            else
            {
                printf("QueueEmpty");
                return INT_MAX;
            }
        }

        void displayQueue()
        {
            node *n = front;
            while(n != NULL)
            {
                printf("%d ", n->value);
                n = n->next;
            }
        }
};

int main()
{
    deque q = deque();
    q.enQueueR(5);
    q.enQueueR(6);
    q.enQueueR(7);
    q.enQueueF(8);
    q.displayQueue();
    q.deQueueF();
    q.deQueueR();
    q.deQueueF();
    q.deQueueR();
}