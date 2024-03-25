/*

*8. Implement circular single linked list to perform the following operations
i) Insert by position ii) Delete rear iii) Delete Front iv) Search for an item by value Display the list contents
after each operation */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct CLL
{
    struct Node *head;
    int count;
};

struct Node *createNode(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation falied..\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

void createList(struct CLL *list, int value)
{
    list->head = createNode(value);
    list->count = 0;
}

// supporting functioons used for   INSERT BY ORDER FUNCTION
void insertAtEnd(struct CLL *list, int value)
{
    struct Node *newnode = createNode(value);
    struct Node *current = list->head->next;
    if (list->head->next == NULL)
    {
        list->head->next = newnode;
        newnode->next = newnode;
        list->count++;
        return;
    }
    while (current->next != list->head->next)
    {
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
    list->count++;
}

void insertAtStart(struct CLL *list, int value)
{
    struct Node *newnode = createNode(value);
    struct Node *current = list->head->next;
    if (list->head->next == NULL)
    {
        list->head->next = newnode;
        newnode->next = newnode;
        list->count++;
        return;
    }
    while (current->next != list->head->next)
    {
        current = current->next;
    }
    current->next = newnode;
    newnode->next = list->head->next;
    list->head->next = newnode;
    list->count++;
}

void insertAtPos(struct CLL *list, int value, int pos)
{
    struct Node *current = list->head->next;
    struct Node *newnode = createNode(value);
    if (pos < 0 || pos > list->count)
    {
        printf("Invalid position to insert the value");
        return;
    }
    if (pos == 0)
        insertAtStart(list, value);
    else if (pos == list->count)
        insertAtEnd(list, value);
    else
    {
        for (int i = 0; i < pos && current->next != list->head->next; i++)
        {

            current = current->next;
        }
        if (list->head->next == NULL)
        {
            printf("Invalid position..\n");
            return -1;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

int deleteAtEnd(struct CLL *list)
{
    struct Node *current = list->head->next;
    struct Node *prev = NULL;
    int val = -1;
    if (list->head->next == NULL)
    {
        printf("list is empty..\n");
        return -1;
    }
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    val = current->data;
    prev->next = current->next;
    free(current);
    list->count--;
    return val;
}

int deleteAtStart(struct CLL *list)
{
    struct Node *current = list->head->next;
    struct Node *last = list->head->next;
    int val = -1;
    if (list->head->next == NULL)
    {
        printf("list is empty..\n");
        return -1;
    }
    while (last->next != list->head->next)
    {
        last = last->next;
    }
    last->next = current->next;
    list->head->next = current->next;
    val = current->data;
    free(current);
    list->count--;
    return val;
}

int searchByKey(struct CLL *list, int key)
{
    if (list->head->next == NULL)
    {
        printf("list is empty..\n");
        return -1;
    }
    struct Node *current = list->head->next;
    int pos = 0;
    do
    {
        if (key == current->data)
        {
            return pos;
        }
        current = current->next;
        pos++;
    } while (current->next != list->head->next);

    printf("Key not found\n");
    return -1;
}

// develop a menu driven function as required