#include <stdio.h>
#include <stdlib.h>

class node
{
    public:
        struct binaryTree *value;
        node *next;
};


struct binaryTree
{
    struct binaryTree *left;
    int value;
    struct binaryTree *right;
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

        void enQueue(struct binaryTree *value)
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

        struct binaryTree *deQueue()
        {
            if(!isEmpty())
            {
                struct binaryTree *value = front->value;
                if(front==rear)
                {
                    front = NULL;
                    rear = NULL;
                }
                else
                {
                    front = front->next;
                }
                return value;
            }
            else
            {
                printf("QueueEmpty");
                return 0;
            }
        }

        struct binaryTree *firstQueue()
        {
            if(!isEmpty())
            {
                return front->value;
            }
            else
            {
                printf("QueueEmpty");
                return 0;
            }
        }

        struct binaryTree *lastQueue()
        {
            if(!isEmpty())
            {
                return rear->value;
            }
            else
            {
                printf("QueueEmpty");
                return 0;
            }
        }

        void displayQueue()
        {
            node *n = front;
            while(n != nullptr)
            {
                printf("%u ", n->value);
                n = n->next;
            }
        }
};
