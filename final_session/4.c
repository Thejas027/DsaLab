/*
. Implement circular single linked list to perform the following operations
i) Insert by order ii ) Delete by position iii) Search for an item by key iv) Delete by key  Display the list
contents after each operatio
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

void insertByOrder(struct CLL *list, int value)
{
    struct Node *newnode = createNode(value);
    struct Node *current = list->head->next;

    if (list->head->next == NULL || value < list->head->next->data)
    {
        insertAtStart(list, value);
        return;
    }
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

    prev->next = newnode;
    newnode->next = current;
    list->count++;
}

// supporting function for DLETE BY POS
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

// function to search for a item

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

void display(struct CLL *list)
{
    struct Node *current = list->head->next;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head->next);
}

int main()
{
    int choice, value, key, pos;
    struct CLL *list = (struct CLL *)malloc(sizeof(struct CLL));
    createList(list, 10);

    do
    {
        printf("\nMENU\n");

        printf("1.Insert In order\n");
        printf("2.delete by pos\n");
        printf("3.search by key\n");
        printf("4.delete by key\n");
        printf("5. to display\n");
        printf("6. to exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert in order : ");
            scanf("%d", &value);
            insertByOrder(list, value);
            break;

        case 2:
            printf("Enter the position in a LL to be deleted\n");
            scanf("%d", &pos);
            printf("deleted element at given position is : %d\n", deleteByPos(list, pos));
            break;

        case 3:
            printf("Enter the key element to find :");
            scanf("%d", &key);
            printf("\nKey element found at index(0-based) : %d \n", searchByKey(list, key));
            break;

        case 4:
            printf("Enter the key element to delete \n");
            scanf("%d", &key);
            printf("deleted element : %d\n", deleteByKey(list, key));
            break;

        case 5:
            display(list);
            break;

        case 6:
            free(list);
            printf("program exited...\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 6);
    return 0;
}
