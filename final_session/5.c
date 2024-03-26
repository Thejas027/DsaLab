/*5. Implement circular double linked list to perform the following operations
i) Insert by order ii ) Delete by position iii ) Delete by key iv) Search by positionDisplay the list contents
after each operation*/

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
}

void deleteByKey(struct CDLL *list, int key)
{
    int pos = searchByKey(list, key);

    if (pos != -1)
        deleteBypos(list, pos);
    else
        printf("Key not found to delete\n");
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
int main()
{
    struct CDLL *list = (struct CDLL *)malloc(sizeof(struct CDLL));
    craeteList(list);

    // develop a menu driven as reqired
    insertByOrder(list, 50);
    insertByOrder(list, 10);
    insertByOrder(list, 30);
    display(list);

    printf("\n%d\n", deleteBypos(list, 0));

    return 0;
}