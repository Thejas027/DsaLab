/*
7. Implement circular double linked list to perform the following operations
i) Insert front ii) Insert rear iii) Delete by position iv) Search by keyDisplay the list
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

int deleteBypos(struct CDLL *list, int pos)
{
    struct Node *current = list->head->next;
    struct Node *curPrev = NULL;
    if (pos < 0 || pos > list->count - 1)
    {
        printf("invalid position to delete the element");
        return -1;
    }
    else if (pos == 0)
        deleteAtstart(list);
    else if (pos == list->count)
        deleteAtEnd(list);
    else
    {
        for (int i = 0; i < pos; i++)
        {
            curPrev = current;
            current = current->next;
        }
        curPrev->next = current->next;
        current->next->prev = curPrev;
        int val = current->data;
        free(current);
        list->count--;
        return val;
    }
}

int searchByKey(struct CDLL *list, int key)
{
    struct Node *current = list->head->next;
    int curPos = 0;
    do
    {
        if (key == current->data)
            return curPos;
        curPos++;
        current = current->next;
    } while (current != list->head->next);
    printf("Key not found\n");
    return -1;
}

int main()
{
    struct CDLL *list = (struct CDLL *)malloc(sizeof(struct CDLL));
    craeteList(list);

    // develop a menu driven as reqired
    insertAtStart(list, 5);
    insertAtStart(list, 1);
    insertAtEnd(list, 20);
    insertAtEnd(list, 38);
    insertAtEnd(list, 40);

    display(list);

    printf("\n%d\n", searchByKey(list, 40));
    printf("\n%d\n", deleteBypos(list, 2));
    return 0;
}