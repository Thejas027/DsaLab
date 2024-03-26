
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10

typedef struct Pqueue
{
    int *arr;
    int front, rear;
    int capacity;
    int size;
} PQ;

void createPQueue(PQ *pq)
{
    pq->arr = (int *)malloc(MAX_CAPACITY * sizeof(int));
    if (pq->arr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    pq->front = 0;
    pq->rear = -1;
    pq->capacity = MAX_CAPACITY;
    pq->size = 0;
}

int isEmpty(PQ *pq)
{
    return pq->size == 0;
}

int isFull(PQ *pq)
{
    return pq->size == pq->capacity;
}

void display(PQ *pq)
{
    if (isEmpty(pq))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements: ");
    for (int i = pq->front; i <= pq->rear; i++)
    {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

void enqueue(PQ *pq, int value)
{
    if (isFull(pq))
    {
        printf("Queue is full, cannot insert element.\n");
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

int dequeue(PQ *pq)
{
    if (isEmpty(pq))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = pq->arr[pq->front++];
    pq->size--;
    if (pq->front > pq->rear)
    {
        pq->front = 0;
        pq->rear = -1;
    }
    return value;
}

void freeMemory(PQ *pq)
{
    free(pq->arr);
}

int main()
{
    PQ pq;
    createPQueue(&pq);
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
            enqueue(&pq, value);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(&pq));
            break;
        case 3:
            display(&pq);
            break;
        case 4:
            printf("Exiting program.\n");
            freeMemory(&pq);
            return 0;
        default:
            printf("Invalid Choice...\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
