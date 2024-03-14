#include <stdio.h>
#define MAX_SIZE 5

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
    printf("Queue is overflow\n");
    return;
  }
  q.rear++;
  q.Q[q.rear] = value;
}

int dequeue()
{
  if (q.front == q.rear)
  {
    printf("Queue is empty\n");
    return -1;
  }
  int x = q.Q[++q.front]; // Access the element first, then increment q.front
  return x;
}

void display()
{
  printf("Queue elements: ");
  for (int i = q.front + 1; i <= q.rear; i++)
  {
    printf("%d ", q.Q[i]);
  }
}

int main()
{
  // Initializing the queue
  q.front = q.rear = -1;

  // Enqueue some values
  enqueue(10);
  enqueue(20);
  enqueue(30);

  // Display the queue elements
  printf("\nBefore dequeue\n");
  display();

  printf("\n\nDequeued element : %d", dequeue());
  // display the elements after deleting
  printf("\n\nAfter dequeing the element from queue \n");
  display();
  return 0;
}
