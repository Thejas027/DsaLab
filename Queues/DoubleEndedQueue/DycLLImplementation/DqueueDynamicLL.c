#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
  {
    printf("Memory Allocation Failed..\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

struct Dqueue
{
  struct Node *rear;
  struct Node *head;
  struct Node *front;
};

void createQList(struct Dqueue *q, int value)
{
  q->head = createNode(value);
  q->rear = q->front = NULL;
}

void insertAtRear(struct Dqueue *q, int value)
{
  struct Node *newnode = createNode(value);
  if (q->rear == NULL)
  {
    q->rear = q->front = newnode;
  }
  else
  {
    q->rear->next = newnode;
    q->rear = newnode;
  }
}

int deleteAtFront(struct Dqueue *q)
{
  if (q->front == NULL)
  {
    printf("No element to delete\n");
    return -1;
  }
  struct Node *current = q->front;
  int x = q->front->data;
  q->front = q->front->next;
  free(current);
  return x;
}

void insertAtFront(struct Dqueue *q, int value)
{
  struct Node *newnode = createNode(value);
  if (q->front == NULL)
  {
    q->front = q->rear = newnode;
    return;
  }
  newnode->next = q->front;
  q->front = newnode;
}

int deleteAtRear(struct Dqueue *q)
{
  if (q->front == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }
  struct Node *current = q->front->next;
  struct Node *prev = NULL;
  while (current != q->rear)
  {
    prev = current;
    current = current->next;
  }
  int x = current->data;
  prev->next = NULL;
  free(current);
  return x;
}

void display(struct Dqueue *q)
{
  if (q->front == NULL)
  {
    printf("Queue is empty");
    return;
  }
  struct Node *current = q->front;
  while (current != q->rear)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("%d ", current->data);
}

int main()
{
  struct Dqueue *q = (struct Dqueue *)malloc(sizeof(struct Dqueue));
  if (q == NULL)
  {
    printf("Memory Allocation Failed..\n");
    exit(EXIT_FAILURE);
  }
  // int size;
  // printf("Enter the size of a queue to be created : ");
  // scanf("%d", &size);
  createQList(q, 10);
  insertAtFront(q, 10);
  insertAtFront(q, 5);
  insertAtRear(q, 80);
  insertAtRear(q, 90);
  printf("elements before deletion : ");
  display(q);
  deleteAtFront(q);
  deleteAtRear(q);
  printf("\nelements after deletion : ");
  display(q);

  free(q);
  return 0;
}