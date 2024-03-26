/*
12. Develop a menu driven program to implement the following types of Queues by allocatingmemory dynamically.
i) Circular Queue
Note: Define Queue structure and implement the operation with array representation
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
struct Cqueue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
};

void initQueue(struct Cqueue *cq, int maxCapacity)
{
    cq->arr = (int *)malloc(maxCapacity * sizeof(int));
    cq->rear = cq->front = -1;
    cq->capacity = maxCapacity;
    cq->size = 0;
}

int isEmpty(struct Cqueue *cq)
{
    return cq->size == 0;
}

int isFull(struct Cqueue *cq)
{
    return cq->size == cq->capacity;
}

void enqueue(struct Cqueue *cq, int value)
{
    if (isFull(cq))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(cq))
    {
        cq->front = cq->rear = 0;
    }
    else
    {
        cq->rear = (cq->rear + 1) % cq->capacity;
    }
    cq->arr[cq->rear] = value;
    cq->size++;
}

int dequeue(struct Cqueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty no element to dequeue\n");
        return -1;
    }
    int val = cq->arr[cq->front];
    if (cq->front == cq->rear)
        cq->front = cq->rear = -1;
    else
        cq->front = (cq->front + 1) % cq->capacity;
    cq->size--;
    return val;
}

int peek(struct Cqueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return cq->arr[cq->front];
}

void display(struct Cqueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty no element to delete\n");
        return;
    }
    for (int i = cq->front; i <= cq->rear; i++)
    {
        printf("%d ", cq->arr[i]);
    }
}

void freeQueue(struct Cqueue *cq)
{
    free(cq->arr);
}

int main()
{

    struct Cqueue *cq = (struct Cqueue *)malloc(sizeof(struct Cqueue));
    initQueue(cq, MAX_CAPACITY);
    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);
    display(cq);
    printf("\n\nDequeued element : %d \n \n", dequeue(cq));
    display(cq);

    // develop a menu driven here as required
    return 0;
}