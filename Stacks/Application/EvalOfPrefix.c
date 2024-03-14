#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

struct Stack
{
  int top;
  char stack[MAX_SIZE];
};

struct Stack st;

void push(int value)
{
  if (st.top == MAX_SIZE - 1)
  {
    printf("Stack is full\n");
    return;
  }
  st.stack[++st.top] = value;
}

int pop()
{
  if (st.top == -1)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return st.stack[st.top--];
}

int isOperand(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char symbol)
{
  if (symbol == '^')
    return 3;
  if (symbol == '*' || symbol == '/')
    return 2;
  if (symbol == '+' || symbol == '-')
    return 1;
  return 0; // Assuming all other characters have lower precedence
}

void reverseString(char *str)
{
  int length = strlen(str);
  int start = 0;
  int end = length - 1;

  while (start <= end)
  {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    start++;
    end--;
  }
}

char *infixToPrefix(char *infix)
{
  char prefix[MAX_SIZE];
  int len = strlen(infix);
  reverseString(infix);
  int i, index = 0;

  for (i = 0; i <= len; i++)
  {
    if (infix[i] == '(')
    {
      infix[i] = ')';
    }
    else if (infix[i] == ')')
    {
      infix[i] = '(';
    }
  }

  for (i = 0; i <= len; i++)
  {
    if (isOperand(infix[i]))
    {
      prefix[index++] = infix[i];
    }
    else if (infix[i] == '(')
    {
      push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (st.top != -1 && st.stack[st.top] != '(')
      {
        prefix[index++] = pop();
      }
      pop(); // Remove '(' from stack
    }
    else if (precedence(infix[i]) > 0)
    {
      while (st.top != -1 && precedence(st.stack[st.top]) >= precedence(infix[i]))
      {
        prefix[index++] = pop();
      }
      push(infix[i]);
    }
  }
  while (st.top != -1)
  {
    prefix[index++] = pop();
  }

  prefix[index] = '\0';
  reverseString(prefix);
  return strdup(prefix);
}

int evalPrefix(char *expression)
{
  st.top = -1;

  int len = strlen(expression);

  for (int i = len - 1; i >= 0; i--)
  {
    if (isOperand(expression[i]))
    {
      push(expression[i] - '0');
    }
    else
    {
      int op2 = pop();
      int op1 = pop();

      switch (expression[i])
      {
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op1 - op2);
        break;
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op1 / op2);
        break;
      case '%':
        push(op1 % op2);
        break;
      case '^':
        push((int)pow(op1, op2));
        break;
      }
    }
  }

  return pop();
}

int main()
{
  char infix[100];
  printf("Enter Infix expression : ");
  scanf("%s", infix);

  char *prefixExpression = infixToPrefix(infix);
  printf("\nPrefix Expression : %s\n", prefixExpression);

  int result = evalPrefix(prefixExpression);   
  printf("Evaluation of prefix : %d\n", result); 

  free(prefixExpression);

  return 0;
}
