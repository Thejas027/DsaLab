/*
  Implement circular single linked list to perform the following operations
i) Insert front ii) Insert rear iii) Delete a node with the given key iv) Search for an item byposition
Display the list contents after each operation
 */

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

// function to return the value at givne position
int searchByPos(struct CLL *list, int pos)
{
    struct Node *current = list->head->next;
    int curpos = 0;
    if (list->head->next == NULL)
    {
        printf("list is empty..\n");
        return -1;
    }
    do
    {
        if (curpos == pos)
            return current->data;

        current = current->next;
        curpos++;
    } while (current != list->head->next);
    printf("Invalid pos to search the key");
    return -1;
}

void display(struct CLL *list)
{
    struct Node *current = list->head->next;

    if (list->head->next == NULL)
    {
        printf("list is empty\n");
        return;
    }
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head->next);
}

// supporting function for DELETE BY KEY
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

int deleteByPos(struct CLL *list, int pos)
{
    struct Node *current = list->head->next;
    struct Node *prev = NULL;
    int val = -1;
    if (pos < 0 || pos > list->count)
    {
        printf("invalid position to delete the element\n");
        return -1;
    }
    if (pos == 0)
        deleteAtStart(list);
    else if (pos == list->count)
        deleteAtEnd(list);
    else
    {
        for (int i = 0; i < pos; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        val = current->data;
        free(current);
        list->count--;
    }
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

int deleteByKey(struct CLL *list, int key)
{
    int pos = searchByKey(list, key);

    if (pos >= 0 && pos <= list->count)
    {
        deleteByPos(list, pos);
    }
    else
    {
        printf("Key not found to delete the element\n");
        return -1;
    }
}

// main function do as required