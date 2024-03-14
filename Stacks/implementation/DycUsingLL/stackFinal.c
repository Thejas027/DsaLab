#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *createNode(int data)
{
	node *newNode = (node *)malloc(sizeof(node));
	if (newNode == NULL)
	{
		printf("Memory allcocationfailed.\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

typedef struct
{
	node *Top;
	int Count;
} Stack;

#define top stack->Top
#define count stack->Count

Stack *initStack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if (!stack)
	{
		printf("Memory allcoation failed.\n");
		exit(1);
	}
	top = NULL; // stack->Top
	count = 0;	// stack->Count
	return stack;
}

bool isEmpty(Stack *stack)
{
	return !(top && count);
}

void push(Stack *stack, int data)
{
	node *newNode = createNode(data);
	if (isEmpty(stack))
		top = newNode;
	else
	{
		newNode->next = top;
		top = newNode;
	}
	count++;
}

int pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("STack underflow, popping faiel.d\n");
		return -1;
	}
	node *toDelete = top;
	int data = top->data;
	top = top->next;
	count--;
	free(toDelete);
	return data;
}

int peek(Stack *stack)
{
	return isEmpty(stack) ? -1 : top->data;
}

void display(Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("STack underflow, popping faiel.d\n");
		return;
	}
	node *temp = top;
	printf("Elemnets of the stack are, \n");
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void freeList(Stack *stack)
{
	if (isEmpty(stack))
	{
		free(stack);
		return;
	}
	node *temp = top;
	while (temp)
	{
		node *next = temp->next;
		free(temp);
		temp = next;
	}
	free(stack);
}

int main()
{
	Stack *stack = initStack();
	int data;
	int choice;
	do
	{
		printf("Menu.\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
		printf("Enter choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter data : ");
			scanf("%d", &data);
			push(stack, data);
			display(stack);
			break;
		case 2:
			printf("poppedelel is %d\n", pop(stack));
			display(stack);
			break;
		case 3:
			printf("peeked ele is %d\n", pop(stack));
			break;
		case 4:
			display(stack);
			break;
		case 5:
			printf("Exiting...\n");
			break;
		default:
			printf("Enter valid coice onlyl.\n");
			break;
		}
		printf("\n\n");
	} while (choice != 5);

	freeList(stack);
	return 0;
}