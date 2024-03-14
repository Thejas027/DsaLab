#ifndef Queue_h
#define Queue_h
#include <stdlib.h>
#include<stdio.h>
struct Node
{
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed..\n");
    return NULL;
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

void enqueue(int value)
{
  struct Node *newNode = createNode(value);
  if (front == NULL)
  {
    front = rear = newNode;
  }
  else
  {
    rear->next = newNode;
    rear = newNode;
  }
}

int dequeue()
{

  if (front == NULL)
  {
    printf("Queue is empty");
    return -1;
  }

  struct Node *temp;
  int value = front->data;
  temp = front;
  front = front->next;
  free(temp);

  return value;
}

int isEmpty()
{
  return front == NULL;
}

#endif /*Queue_h*/