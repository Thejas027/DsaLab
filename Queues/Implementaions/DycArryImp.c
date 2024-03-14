#include <stdio.h>
#include <stdlib.h>
#define MAX_CAPACITY 10

typedef struct Queue
{
  int *arr;
  int front, rear;
  int capacity;
  int size;
} Q;

void createQueue(Q *q, int maxCapacity)
{
  q->arr = (int *)malloc(maxCapacity * sizeof(int));
  if (q->arr == NULL)
  {
    printf("memory ALlocation failed..\n");
    exit(1);
  }
  q->front = q->rear = -1;
  q->size = 0;
  q->capacity = maxCapacity;
}

int isEmpty(Q *q)
{
  return q->size == 0;
}

int isFull(Q *q)
{
  return q->size == q->capacity;
}

void enqueue(Q *q, int value)
{
  if (isFull(q))
  {
    printf("queue is full overflow condition..\n");
    return;
  }
  q->rear++;
  q->arr[q->rear] = value;
  q->size++;
}

int dequeue(Q *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty underflow condition..\n");
    return -1;
  }
  int val = q->arr[++q->front];
  q->size--;
  return val;
}

void display(Q *q)
{
  for (int i = q->front + 1; i <= q->rear; i++)
  {
    printf("%d ", q->arr[i]);
  }
}

void freeQueue(Q * q){
  free(q->arr);
}

int main()
{
  Q *q = (Q *)malloc(sizeof(Q));
  createQueue(q, MAX_CAPACITY);
  enqueue(q, 10);
  enqueue(q, 20);
  printf("Dequeued elemet : %d \n\n", dequeue(q));
  display(q);
  free(q);
  return 0;
}