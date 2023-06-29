#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int rear;
    int front;
    int size;
    int *q;
};

void Queue(struct Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->q = (int *)malloc(sizeof(int) * size);
}

int isEmpty(struct Queue *q)
{
    if(q->front == q->rear)
    {
        return 1;
        q->front = q->rear = -1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if((!isEmpty(q)) && q->front == q->size-1)
    {
        return 1;
    }
    return 0;
}

void enQueue(struct Queue *q, int value)
{
    if(!isFull(q))
    {
        q->rear++;
        q->q[q->rear] = value;
    }
    else
    {
        printf("QueueFull");
    }
}

int deQueue(struct Queue *q)
{
    if(!isEmpty(q))
    {
        q->front++;
        return q->q[q->front];
    }
    else
    {
        printf("QueueEmpty");
        return INT_MAX;
    }
}

int firstQueue(struct Queue *q)
{
    if(!isEmpty(q))
    {
        int i = q->front;
        i++;
        return q->q[i];
    }
    else
    {
        printf("QueueEmpty");
        return INT_MAX;
    }
}

int lastQueue(struct Queue *q)
{
    if(!isEmpty(q))
    {
        return q->q[q->rear];
    }
    else
    {
        printf("QueueEmpty");
        return INT_MAX;
    }
}

void displayQueue(struct Queue *q)
{
    for(int i = q->front+1; i <=q->rear; i++)
    {
        printf("%d ", q->q[i]);
    }
}


int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    Queue(q,8);
    enQueue(q,6);
    enQueue(q,8);
    printf("%d\n",firstQueue(q));
    displayQueue(q);
    deQueue(q);
    printf("%d\n",firstQueue(q));
    displayQueue(q);
}