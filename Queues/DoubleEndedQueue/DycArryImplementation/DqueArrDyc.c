// program to perform operations on double ended queue which is implemenated dyanamically using array

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10

typedef struct Dqueue
{
  int *arr;
  int front, rear;
  int size;
  int capacity;
} DQ;

void createDque(DQ *dq, int maxCapacity)
{
  dq->arr = (int *)malloc(sizeof(int) * maxCapacity);
  if (dq->arr == NULL)
  {
    printf("memory allocation failed.\n");
    return;
  }
  dq->front = dq->rear = -1;
  dq->capacity = maxCapacity;
  dq->size = 0;
}

int isEmpty(DQ *dq)
{
  return dq->size == 0;
}

int isFull(DQ *dq)
{
  return dq->size == dq->capacity;
}

void insertAtrear(DQ *dq, int value)
{
  if (isFull(dq))
  {
    printf("queue is full overflow condition.\n");
    return;
  }
  dq->arr[++dq->rear] = value;
  dq->size++;
}

void insertAtFront(DQ *dq, int value)
{
  if (isFull(dq))
  {
    printf("Queue overflow condition.\n");
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

int deleteAtFront(DQ *dq)
{
 if (isEmpty(dq))
 {
    printf("Cannot delete the element from front end.\n");
    return -1;
 }
 int x = dq->arr[dq->front]; 
 dq->front++; 
 dq->size--;
 if (dq->size == 0)
 {
    dq->front = dq->rear = -1; 
 }
 else if (dq->front > dq->rear) 
 {
    dq->front = 0; 
 }

 return x;
}

int deleteAtRear(DQ *dq)
{
  if (isEmpty(dq))
  {
    printf("Queue is underflow condition.\n");
    return -1;
  }
  int val = dq->arr[dq->rear--];
  dq->size--;
  if (dq->front > dq->rear)
  {
    dq->front = dq->rear = -1;
  }
  return val;
}

void display(DQ *dq)
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
  DQ *dq = (DQ *)malloc(sizeof(DQ));
  createDque(dq, MAX_CAPACITY);
  insertAtrear(dq, 10);
  insertAtrear(dq, 20);
  display(dq);
  printf("\n");

  printf("Deleted elemet at front : %d\n", deleteAtFront(dq));
  return 0;
}