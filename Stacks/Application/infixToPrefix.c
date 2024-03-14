#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct Stack
{
    char stack[MAX_SIZE];
    int top;
} st;

void push(char ch)
{
    if (st.top == MAX_SIZE - 1)
    {
        printf("Stack is Full\n");
        return;
    }
    st.stack[++st.top] = ch;
}

char pop()
{
    if (st.top == -1)
    {
        printf("stack is empty\n");
        return '\0';
    }
    return st.stack[st.top--];
}

int isOperend(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPrefix(char *infix, char *prefix)
{
    int len = strlen(infix);
    strrev(infix);
    int i, index = 0;

    for (i = 0; i < len; i++)
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

    for (i = 0; i < len; i++)
    {
        if (isOperend(infix[i]))
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
            pop();
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
    strrev(prefix);
}

int main()
{
    char infix[100];
    char prefix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}
