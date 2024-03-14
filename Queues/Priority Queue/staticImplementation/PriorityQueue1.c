// PRIRORITY QUEUE CAN BE IMPLEMENTED IN TWO WAYS
/*
here the insertion to queue is random where through rear pointer the data is inserted where -->
while dequeuing the element the prirority comes to the matter where the the most prirored elemented data comes out first
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Queue
{
    int front;
    int rear;
    int Q[MAX_SIZE];
} q;

void enqueue(int value)
{
    if (q.rear == MAX_SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }

    q.Q[++q.rear] = value;
}

int dequeue()
{
    if (q.front > q.rear || q.front == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    int min = q.front;

    for (int i = q.front + 1; i <= q.rear; i++)
    {
        if (q.Q[i] < q.Q[min])
        {
            min = i;
        }
    }
    printf("%d ", q.Q[min]);
    for (int i = min; i <= q.rear; i++)
    {
        q.Q[i] = q.Q[i + 1];
    }
    q.rear--;
}

int main()
{
    q.front = 0;
    q.rear = -1;

    enqueue(12);
    enqueue(4);
    enqueue(11);
    enqueue(18);

    printf("Dequeued element : ");
    dequeue();
    dequeue();
    dequeue();

    return 0;
}