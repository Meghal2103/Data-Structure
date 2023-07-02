#include <cstdio>
#include <cstdlib>

class node
{
    public:
        int value;
        node *next;
};

class Queue
{
    private:
        node *rear;
        node *front;
    public:
        Queue()
        {
            rear = nullptr;
            front = nullptr;
        }

        int isEmpty()
        {
            if(front == rear && front == nullptr)
            {
                return 1;   
            }
            return 0;
        }

        int isFull()
        {
            node *n = (node *)malloc(sizeof(node));
            if(n == nullptr)
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
                n->next = nullptr;
                if(rear == nullptr)
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

        int deQueueF()
        {
            if(!isEmpty())
            {
                if(front->next == nullptr && front == rear)
                {
                    node *n;
                    n = rear;
                    int value  = n->value;
                    front = nullptr;
                    rear = nullptr;
                    free(n);
                    return value;
                }
                else
                {
                    node *n;
                    n = front;
                    front = front->next;
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
            while(n != nullptr)
            {
                printf("%d ", n->value);
                n = n->next;
            }
        }
};
