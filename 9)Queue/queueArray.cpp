#include <stdio.h>
#include <stdlib.h>

class Queue
{
    public:
        int rear;
        int front;
        int size;
        int *q;

        Queue(int size)
        {
            size = size;
            front = -1;
            rear = -1;
            q = (int *)malloc(sizeof(int) * size);
        }

        int isEmpty()
        {
            if(front == rear)
            {
                front = rear = -1;
                return 1;   
            }
            return 0;
        }

        int isFull()
        {
            if((!isEmpty()) && front == size-1)
            {
                return 1;
            }
            return 0;
        }

        void enQueue(int value)
        {
            if(!isFull())
            {
                rear++;
                q[rear] = value;
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
                front++;
                return q[front];
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
                int i = front;
                i++;
                return q[i];
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
                return q[rear];
            }
            else
            {
                printf("QueueEmpty");
                return INT_MAX;
            }
        }

        void displayQueue()
        {
            for(int i = front+1; i <=rear; i++)
            {
                printf("%d ", q[i]);
            }
        }
};

int main()
{
    Queue q = Queue(8);
    q.enQueue(6);
    q.enQueue(8);
    printf("%d\n",q.lastQueue());
    q.displayQueue();
    q.deQueue();
    q.enQueue(9);
    printf("%d\n",q.lastQueue());
    q.displayQueue();
}