// priority queue implemented dynamically but using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct PQueue
{
    struct Node *rear;
    struct Node *front;
};

struct Node *createNode(int priority, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("memory allocation failed..\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = value;
    newnode->priority = priority;
    newnode->next = NULL;
    return newnode;
}

struct PQueue *createPQueue()
{
    struct PQueue *pq = (struct PQueue *)malloc(sizeof(struct PQueue));
    if (pq == NULL)
    {
        printf("Memory Allocation failed..\n");
        exit(EXIT_FAILURE);
    }
    pq->front = pq->rear = NULL;
    return pq;
}

// funtion where an element is inserted based on its priority

void enqueue(struct PQueue *pq, int priority, int value)
{
    struct Node *newnode = createNode(priority, value);
    if (pq->rear == NULL)
    {
        pq->front = pq->rear = newnode;
    }
    else
    {
        if (priority < pq->front->priority)
        {
            newnode->next = pq->front;
            pq->front = newnode;
        }
        else
        {
            struct Node *current = pq->front;
            while (current->next != NULL && priority >= current->next->priority)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
            if (newnode->next == NULL)
            {
                pq->rear = newnode;
            }
        }
    }
}

// function to dequeue the elements
int dequeue(struct PQueue *pq)
{
    if (pq->front == NULL)
    {
        printf("queue is empty no element to dequeue..\n");
        return -1;
    }

    struct Node *temp = pq->front;
    pq->front = temp->next;
    int x = temp->data;
    free(temp);

    // in case it contains only one node where front and rear pointing on same node
    if (pq->front == NULL)
    {
        pq->rear = NULL;
    }
    return x;
}

// function to display the elements
void display(struct PQueue *pq)
{
    struct Node *current = pq->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct PQueue *pq = createPQueue();
    enqueue(pq, 3, 10);
    enqueue(pq, 1, 20);
    enqueue(pq, 2, 100);
    enqueue(pq, 5, 25);
    enqueue(pq, 4, 45);
    display(pq);
    return 0;
}
