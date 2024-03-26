/*
9. Implement circular double linked list to perform the following operations
i) Insert by order ii) Delete rear iii) Delete Front iv) Search for an item by positionDisplay the list
contents after each operation
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct CDLL
{
    struct Node *head;
    int count;
};

struct Node *createNode(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed..\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = newnode->prev = newnode;
    return newnode;
}

void craeteList(struct CDLL *list)
{
    list->head = createNode(0);
    list->head->next = list->head->prev = NULL;
    list->count = 0;
}

void display(struct CDLL *list)
{
    struct Node *current = list->head->next;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head->next);
    printf("\n");
}

void insertAtStart(struct CDLL *list, int value)
{
    struct Node *newnode = createNode(value);
    struct Node *current = list->head->next;
    if (current == NULL)
    {
        list->head->next = newnode;
        list->count++;
        return;
    }

    newnode->next = current;
    newnode->prev = current->prev;
    current->prev->next = newnode;
    current->prev = newnode;
    list->head->next = newnode;
    list->count++;
}

void insertAtEnd(struct CDLL *list, int value)
{
    struct Node *newnode = createNode(value);
    struct Node *current = list->head->next;
    if (current == NULL)
    {
        list->head->next = newnode;
        list->count++;
        return;
    }
    newnode->next = current;
    newnode->prev = current->prev;
    current->prev->next = newnode;
    current->prev = newnode;
    list->count++;
}

void insertByPos(struct CDLL *list, int value, int pos)
{
    struct Node *newnode = createNode(value);
    struct Node *current = list->head->next;

    if (pos < 0 || pos > list->count - 1)
    {
        printf("invalid position to insert the element\n");
        return;
    }
    else if (pos == 0)
        insertAtStart(list, value);
    else if (pos == list->count)
        insertAtEnd(list, value);
    else
    {
        for (int i = 0; i < pos - 1 && current->next != list->head->next; i++)
        {
            current = current->next;
        }
        newnode->next = current->next;
        newnode->prev = current;
        current->next->prev = newnode;
        current->next = newnode;
        list->count++;
    }
}

void insertByOrder(struct CDLL *list, int value)
{
    struct Node *newnode = createNode(value);
    while (list->head->next == NULL || value < list->head->next->data)
    {
        insertAtStart(list, value);
        return;
    }

    struct Node *current = list->head->next;
    struct Node *CurrPrev = NULL;
    while (value >= current->data && current->next != list->head->next)
    {
        CurrPrev = current;
        current = current->next;
    }
    if (value > current->data)
    {
        insertAtEnd(list, value);
        return;
    }
    newnode->next = current;
    newnode->prev = CurrPrev;
    current->prev = newnode;
    CurrPrev->next = newnode;
    list->count++;
}

int deleteAtstart(struct CDLL *list)
{
    if (list->head->next == NULL)
    {
        printf("no element to delete at start\n");
        return -1;
    }

    struct Node *current = list->head->next;
    int val = current->data;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    list->head->next = current->next;
    free(current);
    list->count--;
    return val;
}

int deleteAtEnd(struct CDLL *list)
{
    if (list->head->next == NULL)
    {
        printf("no element to delete at start\n");
        return -1;
    }

    struct Node *current = list->head->next;
    struct Node *last = current->prev;
    int val = last->data;
    last->prev->next = current;
    current->prev = last->prev;
    free(last);
    list->count--;
    return val;
}

int searchByPos(struct CDLL *list, int pos)
{
    struct Node *current = list->head->next;
    // if (pos < 0 || pos > list->count - 1)
    // {
    //     printf("invalid position\n");
    //     return -1;
    // }
    int curPos = 0;
    do
    {
        if (curPos == pos)
            return current->data;
        curPos++;
        current = current->next;
    } while (current != list->head->next);
    printf("Invalid postion to delete the element\n");
    return -1;
}

// develop a menu driven as required
int main()
{
    struct CDLL *list = (struct CDLL *)malloc(sizeof(struct CDLL));
    craeteList(list);

    return 0;
}