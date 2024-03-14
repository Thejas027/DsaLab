#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Stack
{
  struct Node *top;
};

struct Node *craeteNode(int value)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    printf("Memory Allocation Failed..\n");
    exit(1);
  }
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}

void intializeStack(struct Stack *s)
{
  s->top = NULL;
}

int isEmpty(struct Stack *s)
{
  return s->top == NULL;
}

// Function to display the elements of the stack
void display(struct Stack *s)
{
  struct Node *current = s->top;
  if (current == NULL)
  {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack elements: ");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void push(struct Stack *s, int value)
{
  struct Node *newnode = craeteNode(value);
  if (isEmpty(s))
    s->top = newnode;
  else
  {
    newnode->next = s->top;
    s->top = newnode;
  }
}

int pop(struct Stack *s)
{
  if (s->top == NULL)
  {
    printf("Stack is empty\n");
    return -1;
  }
  struct Node *current = s->top;
  s->top = current->next;
  int x = current->data;
  free(current);
  return x;
}

int main()
{

  struct Stack *myStack = (struct Stack *)malloc(sizeof(struct Stack));
  if (myStack == NULL)
  {
    printf("Memory Allocation failed..\n");
    return -1;
  }
  intializeStack(myStack);

  push(myStack, 10);
  push(myStack, 20);
  push(myStack, 30);
  push(myStack, 40);
  push(myStack, 50);
  push(myStack, 60);
  display(myStack);
  printf("\nPoped element : %d", pop(myStack));
  printf("\n\n");
  display(myStack);
  return 0;
}