// progarm for dynamic implemantaitoin of stack using array

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10

typedef struct Stack
{
  int *arr;
  int top;
  int size;
  int capacity;
} S;

void createStack(S *s, int maxCapacity)
{
  s->arr = (int *)malloc(sizeof(int) * maxCapacity);
  if (s->arr == NULL)
  {
    printf("memory allocaion failed..\n");
    exit(1);
  }
  s->top = -1;
  s->size = 0;
  s->capacity = maxCapacity;
}

int isEmpty(S *s)
{
  return s->size == 0;
}

int isFull(S *s)
{
  return s->size == s->capacity;
}

void push(S *s, int value)
{
  if (isFull(s))
  {
    printf("stack is fulll underfolw condition..\n");
    return;
  }
  s->arr[++s->top] = value;
  s->size++;
}

int pop(S *s)
{
  if (isEmpty(s))
  {
    printf("stack is empty no element to pop.\n");
    return -1;
  }

  int val = s->arr[s->top--];
  s->size--;
  return val;
}

int peek(S *s)
{
  if (isEmpty(s))
  {
    printf("stack is empty no element to peek at top.\n");
    return -1;
  }
  return s->arr[s->top];
}

void display(S *s)
{
  if (isEmpty(s))
  {
    printf("stack is empty no element to display.\n");
    return;
  }
  for (int i = s->top; i >= 0; i--)
    printf("%d ", s->arr[i]);
}

int main()
{
  S *s = (S *)malloc(sizeof(S));
  createStack(s, MAX_CAPACITY);
  push(s, 10);
  push(s, 20);
  push(s, 30);

  printf("\nPoped element : %d \n\n", pop(s));
  display(s);

  return 0;
}