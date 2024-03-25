/*
develop a menu driven program to convert the infix expression to postfix and evulate the postfix expression
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
        printf("stack is full\n");
        return;
    }
    st.stack[++st.top] = value;
}

int pop()
{
    if (st.top == -1)
    {
        printf("stack if empty..\n");
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

char *infixToPostfix(char *infix, char *postfix)
{
    // char *postfix[MAX_SIZE];
    int len = strlen(infix);
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        if (isOperend(infix[i]))
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
                postfix[index++] = pop();
            pop();
        }
        else
        {
            while (st.top != -1 && precedence(st.stack[st.top]) > precedence(infix[i]))
            {
                postfix[index++] = pop();
            }
            push(infix[i]);
        }
    }

    while (st.top != -1)
    {
        postfix[index++] = pop();
    }

    postfix[index] = '\0';

    // char *result = postfix;
    return postfix;
}

int eval(char *exp)
{
    int len = strlen(exp);
    st.top = -1;

    for (int i = 0; i < len; i++)
    {
        if (isOperend(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            int op2 = pop();
            int op1 = pop();

            switch (exp[i])
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

            case '^':
                push(pow(op1, op2));
                break;

            default:
                printf("\ninvlid symbol in expression\n");
                break;
            }
        }
    }
    return pop();
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("enter the infix expression : ");
    scanf("%s", infix);
    char *PostfixExp;
    int result;
    int choice;
    do
    {
        printf("\n\nMenu\n\n");
        printf("1.to convert to postfix\n");
        printf("2.to evulate it \n"); // note convert the expression to postfix first to evalute
        printf("3.to exit\n");
        printf("enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PostfixExp = infixToPostfix(infix, postfix);
            printf("postfix exp : %s", PostfixExp);
            break;

        case 2:
            result = eval(PostfixExp);
            printf("eval :  %d", result);
            break;

        case 3:
            free(PostfixExp);
            printf("program exited...\n");
            break;
        default:
            break;
        }
    } while (choice != 3);
    return 0;
}