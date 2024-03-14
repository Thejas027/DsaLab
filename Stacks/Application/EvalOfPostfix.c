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
void push(char ch)
{
    if (st.top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }
    st.stack[++st.top] = ch;
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
    return 0;
}

char *infixToPost(char *infix)
{
    char postfix[MAX_SIZE];
    int len = strlen(infix);
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (isOperand(infix[i]))
        {
            postfix[index++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (st.top != -1 && st.stack[st.top] != '(')
            {
                postfix[index++] = pop();
            }
            pop(); // Pop the '('
        }
        else // Operator
        {
            while (st.top != -1 && precedence(st.stack[st.top]) >= precedence(infix[i]))
            {
                postfix[index++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (st.top != -1)
    {
        postfix[index++] = pop();
    }

    postfix[index] = '\0';

    return strdup(postfix);
}
int evalPostfix(char *expression)
{
    st.top = -1; // Initialize the global stack variable

    int len = strlen(expression);

    for (int i = 0; i < len; i++)
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
                push(pow(op1, op2));
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

    char *postfixExpression = infixToPost(infix);
    printf("\nPostfix Expression : %s", postfixExpression);

    int result = evalPostfix(postfixExpression);
    printf("\nEvaluation of postfix : %d\n", result);

    free(postfixExpression);

    return 0;
}
