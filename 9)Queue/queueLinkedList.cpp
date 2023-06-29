#include <stdio.h>
#include <stdlib.h>

class node
{
    public:
        int value;
        node *next;
};

class Queue
{
    public:
        node *rear;
        node *front;

        Queue()
        {
            rear = NULL;
            front = NULL;
        }

        int isEmpty()
        {
            if(front == rear)
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

        void enQueue(int value)
        {
            if(!isFull())
            {
                node *n = (node *)malloc(sizeof(node));
                n->value = value;
                n->next = NULL;
                if(rear == NULL)
                {
                    rear = n;
                    front = n;
                }
                else
                {
                    rear->next = n;
                    rear = n;
                }
            }
            else
            {
                printf("QueueFull");
            }
        }

        int deQueue()
        {
            if(!isEmpty())
            {
                int value = front->value;
                front = front->next;
                return value;
            }
            else
            {
                printf("QueueEmpty");
                return INT_MAX;
            }
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
    Queue q = Queue();
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(7);
    q.enQueue(8);
    q.deQueue();
    printf("%d\n", q.lastQueue());
    printf("%d\n", q.firstQueue());
    q.displayQueue();
}
