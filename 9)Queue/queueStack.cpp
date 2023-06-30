#include <stdio.h>
#include <stdlib.h>
#include <D:\Data Structure\9)Queue\stack.h>

class queue
{
    private:
        stack s1; //enqueue
        stack s2; //dequque
    public:
        int isEmpty()
        {
            if(s1.isEmpty() == 1 && s2.isEmpty() == 1)
            {
                return 1;
            }
            return 0;
        }

        int isFull()
        {
            if(s1.isFull() == 1)
            {
                return 1;
            }
            return 0;
        }

        void enQueue(int value)
        {
            if(!isFull())
            {
                s1.push(value);
            }
        }

        int deQueue()
        {
            if(!(s2.isEmpty()))
            {
                return s2.pop();
            }
            else
            {
                while(s1.stackTop() != INT_MAX)
                {
                    s2.push(s1.pop());
                }
                return s2.pop();
            }
        }

        int firstQueue()
        {
            if(!isEmpty())
            {
                return s2.stackTop();
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
                return s1.stackTop();
            }
            else
            {
                printf("QueueEmpty");
                return INT_MAX;
            }
        }
};

int main()
{
    queue q = queue();
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    int x = q.deQueue();
    x = q.deQueue();
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(7);
    q.enQueue(8);
    x = q.deQueue();
    x = q.deQueue();
    x = q.deQueue();
    x = q.deQueue();
    x = q.deQueue();
}