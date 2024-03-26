/*
13. Develop a menu driven program to implement the following types of Queues byallocating memory
dynamically.
i) Circular Queue ii) Priority Queue
Note: Define Queue structure and implement the operation with array representation
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
struct Pqueue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
};

void initpqueue(struct Pqueue *pq, int maxCapacity)
{
    pq->arr = (int *)malloc(sizeof(int) * maxCapacity);
    pq->rear = -1;
    pq->front = 0;
    pq->size = 0;
    pq->capacity = maxCapacity;
}

int isEmpty(struct Pqueue *pq)
{
    return pq->size == 0;
}

int isFull(struct Pqueue *pq)
{
    return pq->size == pq->capacity;
}

void display(struct Pqueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = pq->front; i <= pq->rear; i++)
    {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

void enqueue(struct Pqueue *pq, int value)
{
    if (isFull(pq))
    {
        printf("Queue is full\n");
        return;
    }

    int pos = pq->rear;

    while (pos >= pq->front && value <= pq->arr[pos])
    {
        pq->arr[pos + 1] = pq->arr[pos];
        pos--;
    }
    pq->arr[pos + 1] = value;
    pq->rear++;
    pq->size++;
}

int dequeue(struct Pqueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int val = pq->arr[pq->front++];
    pq->size--;

    if (pq->front > pq->rear)
    {
        pq->front = 0;
        pq->rear = -1;
    }
    return val;
}
void freeMemory(struct Pqueue *pq)
{
    free(pq->arr);
}

int main()
{
    struct Pqueue *pq = (struct Pqueue *)malloc(sizeof(struct Pqueue));
    initpqueue(pq, MAX_CAPACITY);
    int value, choice;

    do
    {
        printf("\nMenu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your Choice :  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            enqueue(pq, value);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(pq));
            break;
        case 3:
            display(pq);
            break;
        case 4:
            printf("Exiting program.\n");
            freeMemory(pq);
            return 0;
        default:
            printf("Invalid Choice...\n");
            break;
        }
    } while (choice != 4);

    return 0;
}