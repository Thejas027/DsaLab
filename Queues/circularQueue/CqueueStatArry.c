#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue
{
  int Q[MAX_SIZE];
  int front;
  int rear;
};

void initializeQueue(struct Queue *q)
{
  q->front = -1;
  q->rear = -1;
}

int enqueue(struct Queue *q, int value)
{
  if ((q->rear + 1) % MAX_SIZE == q->front)
  {
    printf("QUEUE OVERFLOW\n");
    return 0; // Indicate failure
  }

  if (q->front == -1)
  {
    q->front = 0;
  }

  q->rear = (q->rear + 1) % MAX_SIZE;
  q->Q[q->rear] = value;
  return 1; // Indicate success
}

void display(struct Queue *q)
{
  printf("Queue elements : ");
  int i = q->front + 1;
  do
  {
    printf("%d ", q->Q[i]);
    i = (i + 1) % MAX_SIZE;
  } while (i != (q->rear + 1) % (MAX_SIZE));
  printf("\n");
}

int dequeue(struct Queue *q)
{
  int x = -1;
  if (q->front == -1)
  {
    printf("Queue is empty\n");
  }
  else
  {
    x = q->Q[q->front];
    if (q->front == q->rear)
    {
      q->front = -1;
      q->rear = -1;
    }
    else
    {
      q->front = (q->front + 1) % MAX_SIZE;
    }
  }
  return x;
}

int main()
{
  struct Queue q;
  initializeQueue(&q);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);

  display(&q);

  printf("Dequeued element: %d\n", dequeue(&q));

  display(&q);

  return 0;
}
