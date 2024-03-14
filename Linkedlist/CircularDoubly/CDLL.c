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
struct Node *
createNode(int value)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    printf("Memory Allocation Failed...\n");
    exit(1);
  }
  newnode->data = value;
  newnode->prev = newnode->next = newnode;
  return newnode;
}
void createList(struct CDLL *mylist)
{
  mylist->head = createNode(0);
  mylist->head->next = mylist->head->prev = NULL;
  mylist->count = 0;
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
    // If the list is empty
    list->head->next = newnode;
  }
  else
  {
    // Insert at the start
    newnode->next = current;
    newnode->prev = current->prev;
    current->prev->next = newnode;
    current->prev = newnode;
  }
  list->count++;
}
void insertAtEnd(struct CDLL *list, int value)
{
  struct Node *newnode = createNode(value);
  if (list->head->next == NULL)
  {
    // If the list is empty
    list->head->next = newnode;
  }
  else
  {
    list->head->next->prev->next = newnode;
    newnode->prev = list->head->next->prev;
    newnode->next = list->head->next;
    list->head->next->prev = newnode;
  }
  list->count++;
}
void insertAtpos(struct CDLL *list, int value, int pos)
{
  if (pos < 0 || pos > list->count)
  {
    printf("Invalid position. Position is out of range\n");
  }
  else if (pos == 0)
  {
    insertAtStart(list, value);
  }
  else if (pos == list->count)
  {
    insertAtEnd(list, value);
  }
  else
  {
    struct Node *newnode = createNode(value);
    struct Node *current = list->head->next;
    for (int i = 0; i < pos - 1; i++)
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
int deleteAtStart(struct CDLL *list)
{
  int x = -1;
  struct Node *current = list->head->next;
  struct Node *last = list->head->next->prev;
  if (list->head->next == NULL)
  {
    printf("List is empty\n");
    return -1;
  }
  current->next->prev = last;
  last->next = current->next;
  list->head->next = current->next;
  x = current->data;
  free(current);
  list->count--;
  return x;
}
int deleteAtEnd(struct CDLL *list)
{
  int x = -1;
  struct Node *last = list->head->next;
  if (list->head->next == NULL)
  {
    printf("list is empty\n");
    return -1;
  }
  while (last->next != list->head->next)
  {
    last = last->next;
  }
  last->prev->next = list->head->next;
  list->head->prev = last->prev;
  x = last->data;
  free(last);
  list->count--;
  return x;
}
int deleteAtPos(struct CDLL *list, int pos)
{
  if (pos < 0 || pos > list->count)
  {
    printf("\ninvalid position. cannot delete the element\n");
    return -1;
  }
  else if (pos == 0)
  {
    deleteAtStart(list);
  }
  else if (pos == list->count)
  {
    deleteAtEnd(list);
  }
  else
  {
    struct Node *current = list->head->next;
    struct Node *prev = NULL;
    for (int i = 0; i < pos && current->next != list->head->next; i++)
    {
      prev = current;
      current = current->next;
    }
    current->next->prev = current->prev;
    prev->next = current->next;
    int x = current->data;
    free(current);
    list->count--;
    return x;
  }
}
int searchByKey(struct CDLL *list, int key)
{
  struct Node *current = list->head->next;
  int pos = 0;
  if (list->head->next == NULL)
  {
    printf("\nlist is empty\n");
    return -1;
  }
  do
  {
    if (key == current->data)
      return pos;
    pos++;
    current = current->next;
  } while (current != list->head->next);
  printf("Key not found\n");
  return -1;
}
int deleteByKey(struct CDLL *list, int key)
{
  int pos = searchByKey(list, key);
  if (pos == -1)
  {
    printf("\nelement cannot be deleted\n");
    return -1;
  }
  else
  {
    deleteAtPos(list, pos);
  }
}

void insertInOrder(struct CDLL *list, int value)
{
  struct Node *newnode = createNode(value);
  if (list->head == NULL || value < list->head->next->data)
  {
    insertAtStart(list, value);
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
  }
  else
  {
    prev->next = newnode;
    newnode->next = current;
    list->count++;
  }
}

int main()
{
  struct CDLL *list = (struct CDLL *)malloc(sizeof(struct CDLL));
  createList(list);
  insertAtEnd(list, 90);
  insertAtEnd(list, 20);
  insertInOrder(list, 55);
  display(list);
  return 0;
}