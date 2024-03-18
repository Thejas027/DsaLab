#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

int count = 0;
struct linkedlist
{
	struct Node *head;
};

struct Node *
createnode(int value)
{
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	if (newnode == NULL)
	{
		printf("memoery allocation failed\n");
		exit(1);
	}
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}

void createList(struct linkedlist *mylist, int value)
{
	mylist->head = createnode(value);
}

void insertAtEnd(struct linkedlist *list, int value)
{
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode = createnode(value);
	struct Node *current = list->head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
	count++;
}

void insertAtStart(struct linkedlist *list, int value)
{
	struct Node *newnode = createnode(value);
	struct Node *current = list->head;
	newnode->next = current->next;
	current->next = newnode;
	count++;
}

void insertAtpos(struct linkedlist *list, int pos, int value)
{
	struct Node *current = list->head->next;
	if (pos < 0 || pos > count)
	{
		printf("invalid position to insert the data\n");
		return;
	}

	if (pos == 0)
	{
		insertAtStart(list, value);
	}
	else if (pos == count - 1)
	{
		insertAtEnd(list, value);
	}
	else
	{
		for (int i = 1; i < pos - 1; i++)
		{
			current = current->next;
		}
		struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
		newnode->data = value;
		newnode->next = current->next;
		current->next = newnode;
		count++;
	}
}

void display(struct linkedlist *list)
{
	struct Node *current = list->head->next;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
}

int deleteAtstart(struct linkedlist *list)
{
	int x = -1;
	struct Node *current = list->head->next;

	if (current == NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	list->head->next = current->next;
	x = current->data;
	free(current);
	count--;
	return x;
}

int deleteAtEnd(struct linkedlist *list)
{
	int x = -1;
	struct Node *current = list->head->next;
	struct Node *prev = NULL;

	if (current == NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	x = current->data;
	prev->next = NULL;
	free(current);
	count--;
	return x;
}

int deleteAtPos(struct linkedlist *list, int pos)
{
	int x = -1;
	struct Node *current = list->head->next;
	struct Node *prev = NULL;
	if (pos < 0 || pos >= count)
	{
		printf("Invalid position\n");
		return -1;
	}
	if (pos == 0)
	{
		deleteAtstart(list);
	}
	else if (pos == count - 1)
	{
		deleteAtEnd(list);
	}
	else
	{
		for (int i = 1; i < pos && current != NULL; i++)
		{
			prev = current;
			current = current->next;
		}
		if (current == NULL)
		{
			printf("invalid postion element cannot be deleted\n");
			return -1;
		}
		prev->next = current->next;
		x = current->data;
		free(current);
		count--;
		return x;
	}
}

int deleteByKey(struct linkedlist *list, int key)
{
	int x = -1;
	if (list->head == NULL)
	{
		printf("List is empty no node to delete in ll\n");
		return -1;
	}
	struct Node *current = list->head->next;
	struct Node *prev = NULL;

	if (current != NULL && current->data == key)
	{
		list->head->next = current->next;
		x = current->data;
		free(current);
		count--;
		return x;
	}
	while (current != NULL && current->data != key)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
	{
		printf("key not found\n");
		return -1;
	}
	prev->next = current->next;
	x = current->data;
	free(current);
	count--;
	return x;
}

int searchByKey(struct linkedlist *list, int key)
{
	if (list->head->next == NULL)
	{
		printf("List is empty...\n");
		return -1;
	}
	struct Node *current = list->head->next;
	int i = 1;
	while (current != NULL && current->data != key)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
	{
		printf("Key not found\n");
		return -1;
	}
	printf("key found..");
	return i;
}

void searchByPos(struct linkedlist *list, int pos)
{
	if (list->head->next == NULL)
	{
		printf("List is empty\n");
		return;
	}

	if (pos < 0 || pos > count)
	{
		printf("Invalid position.. cannot be searched\n");
		return;
	}

	struct Node *current = list->head->next;
	for (int i = 1; i < pos; i++)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		printf("Invalid position\n");
		return;
	}
	printf("Element at pos %d : %d", pos, current->data);
}

void reverse(struct linkedlist *list)
{
	struct Node *current = list->head->next;
	struct Node *prev = NULL;
	struct Node *temp = NULL;

	while (current != NULL)
	{
		temp = prev;
		prev = current;
		current = current->next;
		prev->next = temp;
	}
	list->head->next = prev;
}

void copyList(struct linkedlist *list, struct linkedlist *newlist)
{
	if (list->head->next == NULL)
	{
		printf("List is empty...\n");
		return;
	}

	struct Node *original = list->head->next;
	struct Node *tail = NULL;

	while (original != NULL)
	{
		struct Node *newnode = createnode(original->data);

		if (newlist->head == NULL)
		{
			newlist->head = createnode(0);
			tail = newlist->head;
		}

		tail->next = newnode;
		tail = newnode;

		original = original->next;
	}

	printf("Copied list: ");
	display(newlist);
}

void insertInOrder(struct linkedlist *list, int value)
{
	struct Node *newnode = createnode(value);
	if (list->head == NULL || value < list->head->next->data)
	{
		insertAtStart(list, value);
		return;
	}

	struct Node *current = list->head->next;
	struct Node *prev = NULL;

	while (value > current->data && current->next != list->head->next)
	{
		prev = current;
		current = current->next;
	}
	if (value > current->data)
	{
		insertAtEnd(list, value);
		return;
	}
	else
	{
		prev->next = newnode;
		newnode->next = current;
		count++;
	}
}
int main()
{
	struct linkedlist *list = (struct linkedlist *)malloc(sizeof(struct linkedlist));
	struct linkedlist *newlist = (struct linkedlist *)malloc(sizeof(struct linkedlist));
	newlist->head = NULL;
	createList(list, 10);
	int choice, value, pos, key;
	do
	{
		printf("\nMENU\n");
		printf("1.Insert At End\n");
		printf("2.Insert At Start\n");
		printf("3.To know the number of nodes in linked list\n");
		printf("4.To insert at any position\n");
		printf("5.To display the LL elements\n");
		printf("6.To delete the element at first\n");
		printf("7.To delete the element at last\n");
		printf("8.Delete at given position\n");
		printf("9.Delte by key\n");
		printf("10.Search by key\n");
		printf("11.Search by Position\n");
		printf("12.To reverse the ll\n");
		printf("13.To create the copy of list\n");
		printf("14.Insert In order\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the data to be inserted at last\n");
			scanf("%d", &value);
			insertAtEnd(list, value);
			display(list);
			break;
		case 2:
			printf("Enter the data to be inserted at first\n");
			scanf("%d", &value);
			insertAtStart(list, value);
			display(list);
			break;
		case 3:
			printf("Total number of nodes in a LL : %d", count);
			break;
		case 4:
			printf("Enter the position value to insert the data\n");
			scanf("%d", &pos);
			printf("Enter the value to be inserted in a position given above\n");
			scanf("%d", &value);
			insertAtpos(list, pos, value);
			display(list);
			break;
		case 5:
			display(list);
			break;
		case 6:
			printf("deleted element at first position is : %d\n", deleteAtstart(list));
			break;
		case 7:
			printf("deleted element at last position is : %d\n", deleteAtEnd(list));
			break;
		case 8:
			printf("Enter the position in a LL to be deleted\n");
			scanf("%d", &pos);
			printf("deleted element at given position is : %d\n", deleteAtPos(list, pos));
			break;
		case 9:
			printf("Enter the key element to delete \n");
			scanf("%d", &key);
			printf("deleted element : %d\n", deleteByKey(list, key));
			display(list);
			break;
		case 10:
			printf("Enter the key element to find :");
			scanf("%d", &key);
			printf("\nKey element found at index(0-based) : %d \n", searchByKey(list, key));
			break;
		case 11:
			printf("\nEnter the position to search the element\n");
			scanf("%d", &pos);
			searchByPos(list, pos);
			break;
		case 12:
			printf("The Reversed the array : ");
			reverse(list);
			display(list);
			break;
		case 13:
			copyList(list, newlist);
			break;
		case 14:
			printf("Enter the value to insert in order : ");
			scanf("%d", &value);
			insertInOrder(list, value);
			display(list);
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	} while (choice != 15);

	free(list);
	return 0;
}