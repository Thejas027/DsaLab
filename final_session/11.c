/*
develop a menu driven program to convert the infix exp to prefix and evulate the expression
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10
struct Stack
{
    int top;
    int stack[MAX_SIZE];
} st;

void push(char value)
{
    if (st.top == MAX_SIZE - 1)
    {
        printf("stack is full \n");
        return;
    }
    st.stack[++st.top] = value;
}

int pop()
{
    if (st.top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    return st.stack[st.top--];
}

int isOperend(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char symbol)
{
    if (symbol == '^' || symbol == '$')
        return 3;
    if (symbol == '%' || symbol == '/' || symbol == '*')
        return 2;
    if (symbol == '+' || symbol == '-')
        return 1;
    return 0;
}

void Rev(char *infix)
{
    int len = strlen(infix);
    int start = 0;
    int end = len - 1;
    while (start < end)
    {
        int temp = infix[start];
        infix[start] = infix[end];
        infix[end] = temp;
        start++;
        end--;
    }
}

char *infixToPrefix(char *infix, char *prefix)
{
    int len = strlen(infix);
    int index = 0;
    Rev(infix);
    for (int i = 0; i < len; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (int i = 0; i < len; i++)
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
                prefix[index++] = pop();
            pop();
        }
        else
        {
            while (st.top != -1 && precedence(st.stack[st.top]) > precedence(infix[i]))
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
    Rev(prefix);

    return prefix;
}

int evalPrefix(char *expression)
{
    st.top = -1;

    int len = strlen(expression);

    for (int i = len - 1; i >= 0; i--)
    {
        if (isOperend(expression[i]))
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
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];
    printf("enter the infix expression : ");
    scanf("%s", infix);
    char *PrefixExp;
    int result;
    int choice;
    do
    {
        printf("\n\nMenu\n\n");
        printf("1.to convert to prefix\n");
        printf("2.to evulate it \n"); // note convert the expression to postfix first to evalute
        printf("3.to exit\n");
        printf("enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PrefixExp = infixToPrefix(infix, prefix);
            printf("postfix exp : %s", PrefixExp);
            break;

        case 2:
            result = evalPrefix(PrefixExp);
            printf("eval :  %d", result);
            break;

        case 3:
            free(PrefixExp);
            printf("program exited...\n");
            break;
        default:
            printf("invalid choice..\n");
            break;
        }
    } while (choice != 3);
    return 0;
}