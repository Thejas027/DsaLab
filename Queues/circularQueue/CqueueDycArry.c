// dynamically implementinting the circular queue using array

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 5
typedef struct CircularQueue
{
  int *arr;
  int front, rear;
  int size;
  int capacity;
} CQueue;

void initQueue(CQueue *cq, int maxCapacity)
{
  cq->arr = (int *)malloc(sizeof(int) * maxCapacity);
  cq->front = cq->rear = -1;
  cq->capacity = maxCapacity;
  cq->size = 0;
}

int isEmpty(CQueue *cq)
{
  return cq->size == 0;
}

int isFull(CQueue *cq)
{
  return cq->size == cq->capacity;
}

void enqueue(CQueue *cq, int value)
{
  if (isFull(cq))
  {
    printf("queue is full.\n");
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

int dequeue(CQueue *cq)
{
  if (isEmpty(cq))
  {
    printf("Queue is empty.\n");
    return -1;
  }
  int value = cq->arr[cq->front];
  if (cq->rear == cq->front)
  {
    cq->front = cq->rear = -1;
  }
  else
  {
    cq->front = (cq->front + 1) % cq->capacity;
  }
  cq->size--;
  return value;
}

int peek(CQueue *cq)
{
  if (isEmpty(cq))
  {
    printf("Queue is empty.\n");
    return -1;
  }
  return cq->arr[cq->front];
}

void display(CQueue *cq)
{
  if (isEmpty(cq))
  {
    printf("Queue is empty.\n");
    return;
  }
  for (int i = cq->front; i <= cq->rear; i++)
  {
    printf("%d ", cq->arr[i]);
  }
}

void freeQueue(CQueue *cq)
{
  free(cq->arr);
}

int main()
{

  CQueue *cq = (CQueue *)malloc(sizeof(CQueue));
  initQueue(cq, MAX_CAPACITY);
  enqueue(cq, 10);
  enqueue(cq, 20);
  enqueue(cq, 30);
  display(cq);
  printf("\n\nDequeued element : %d \n \n", dequeue(cq));
  display(cq);

  freeQueue(cq);
  return 0;
}