/*

 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
struct Dqueue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
};

void initDqueue(struct Dqueue *dq, int maxCapacity)
{
    dq->arr = (int *)malloc(sizeof(int) * maxCapacity);
    dq->rear = dq->front = -1;
    dq->size = 0;
    dq->capacity = maxCapacity;
}

int isEmpty(struct Dqueue *dq)
{
    return dq->size == 0;
}

int isFull(struct Dqueue *dq)
{
    return dq->size == dq->capacity;
}

void insertAtrear(struct Dqueue *dq, int value)
{
    if (isFull(dq))
    {
        printf("Queue is empty\n");
        return;
    }
    dq->arr[++dq->rear] = value;
    dq->size++;
}

void insertAtFraont(struct Dqueue *dq, int value)
{
    if (isFull(dq))
    {
        printf("Queue is full\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = dq->capacity - 1;
    }
    else
    {
        dq->arr[--dq->front] = value;
    }
    dq->size++;
}

int deleteAtFront(struct Dqueue *dq)
{
    if (isEmpty(dq))
    {
        printf("Queue is empty cannot be deleted from front end\n");
        return -1;
    }
    int val = dq->arr[++dq->front];

    dq->size--;
    if (dq->size == 0)
    {
        dq->rear = dq->front = -1;
    }
    else if (dq->front > dq->rear)
    {
        dq->front = 0;
    }
    return val;
}

int deleteAtRear(struct Dqueue *dq)
{
    if (isEmpty(dq))
    {
        printf("Queue is empty.Element cannot be deleted at rerar end\n");
        return -1;
    }
    int val = dq->arr[dq->rear--];
    if (dq->front > dq->rear)
        dq->front = dq->rear = -1;

    dq->size--;
    return val;
}

void display(struct Dqueue *dq)
{
    if (isEmpty(dq))
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = dq->front + 1; i <= dq->rear; i++)
    {
        printf("%d ", dq->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Dqueue *dq = (struct Dqueue *)malloc(sizeof(struct Dqueue));
    initDqueue(dq, MAX_CAPACITY);
    insertAtrear(dq, 10);
    insertAtrear(dq, 20);
    display(dq);
    printf("\n");

    printf("Deleted elemet at front : %d\n", deleteAtFront(dq));
    printf("Deleted elemet at front : %d\n", deleteAtFront(dq));
    display(dq);
    return 0;
}