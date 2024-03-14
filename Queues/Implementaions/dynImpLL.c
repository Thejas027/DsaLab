#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Qlist
{
  struct Node *rear;
  struct Node *head; // dummy node used to store a meta data of a QUEUE
  struct Node *front;
};

struct Node *createNode(int value)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    printf("Memory Allocation Failed\n");
    exit(1);
  }
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}

void createList(struct Qlist *q, int value)
{
  q->head = createNode(value);
  q->front = q->rear = NULL;
}

void display(struct Qlist *q)
{
  printf("Queue elements are\n");
  struct Node *current = q->front;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
}

void enqueue(struct Qlist *q, int value)
{
  struct Node *newnode = createNode(value);
  // base case whee queue has no elements 
  if (q->rear == NULL)
  {
    q->front = q->rear = newnode;
  }
  else
  {
    q->rear->next = newnode;
    q->rear = newnode;
  }
}

int dequeue(struct Qlist *q)
{
  struct Node *current = q->front;
  // base case where queue is empty it does not have any elements
  if (q->front == NULL)
  {
    printf("Queue is empty\n");
    exit(2);
  }
  int x = current->data;
  q->front = current->next;
  free(current);
  return x;
}

int main()
{
  struct Qlist *q = (struct Qlist *)malloc(sizeof(struct Qlist));
  if (q == NULL)
  {
    printf("Memory Allocation Failed\n");
    return -1;
  }
  createList(q, 10);
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  display(q);
  printf("\n");
  printf("The dequeud element : %d ", dequeue(q));
  printf("\n");
  display(q);
  return 0;
}