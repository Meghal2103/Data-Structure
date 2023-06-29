#include <stdio.h>
#include <stdlib.h>

class circularQueue
{
    public:
        int rear;
        int front;
        int size;
        int *q;

        circularQueue(int s)
        {
            size = s;
            front = -1;
            rear = -1;
            q = (int *)malloc(sizeof(int) * size);
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
            if((rear+1)%size==front)
            {
                return 1;
            }
            return 0;
        }

        void enQueue(int value)
        {
            if(!isFull())
            {
                rear = (rear + 1) % size;
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
                front = (front + 1) % size;
                int value = q[front];
                q[front] = INT_MAX;
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
            int i = front + 1;
            do
            {
                printf("%d ", q[i]);
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
        }
};

int main()
{
    circularQueue q = circularQueue(8);
    q.enQueue(6);
    q.enQueue(8);
    printf("%d\n",q.lastQueue());
    q.displayQueue();
    q.deQueue();
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.deQueue();
    q.enQueue(9);
    printf("%d\n",q.lastQueue());
    q.displayQueue();
}