#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define EMPTY_STACK -1
struct Stack
{
  int top;
  int S[STACK_SIZE];
} st;

void push(int value)
{
  if (st.top == STACK_SIZE - 1)
  {
    printf("stack is full(OVERFLOW)\n");
    return;
  }
  st.S[++st.top] = value;
}

int pop()
{
  int x = -1;
  if (st.top == -1)
  {
    printf("Stack is empty . No element to pop\n");
    return -1;
  }
  x = st.S[st.top--];
  // st.top--;
  return x;
}

void display()
{
  if (st.top == EMPTY_STACK)
  {
    printf("Stack is empty.\n");
    return;
  }

  printf("Stack Elements: ");
  for (int i = st.top; i >= 0; i--)
  {
    printf("%d ", st.S[i]);
  }
  printf("\n");
}

int peek()
{
  if (st.top == -1)
  {
    printf("\nStack is empty . No top element\n");
    return -1;
  }
  return st.S[st.top];
}

int main()
{
  st.top = -1;
  push(10);
  push(50);
  push(60);
  push(70);
  push(80);
  push(90);
  display();
  printf("\n\nThe top element in stack : %d\n", peek());
  printf("\npoped element : %d", pop());
  printf("\npoped element : %d\n\n", pop());

  display();

  printf("\n\nThe top element in stack : %d \n", peek());
  return 0;
}