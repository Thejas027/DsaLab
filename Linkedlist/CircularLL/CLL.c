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
            printf("memory allocation failed..\n");
            exit(1);
      }
      newnode->data = value;
      newnode->next = NULL;

      return newnode;
}

void createList(struct CLL *list, int value)
{
      list->head = createNode(value);
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
            current = current->next;
      current->next = newnode;
      newnode->next = list->head->next;
      list->head->next = newnode;
      list->count++;
}

void insertAtPos(struct CLL *list, int value, int pos)
{
      struct Node *current = list->head->next;
      if (pos < 0 || pos > list->count - 1)
      {
            printf("Invalid position. element cannot be inserted\n");
            return;
      }
      else if (pos == 0)
      {
            insertAtStart(list, value);
      }
      else if (pos < list->count - 1)
      {
            insertAtEnd(list, value);
      }
      else
      {
            struct Node *newnode = createNode(value);
            for (int i = 0; i < pos - 1 && current->next != list->head->next; i++)
            {
                  current = current->next;
            }
            if (current->next == list->head->next)
            {
                  printf("invalid position to insert the element\n");
                  return;
            }
            newnode->next = current->next;
            current->next = newnode;
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

int deleteAtStart(struct CLL *list)
{
      int x = -1;
      struct Node *current = list->head->next;
      struct Node *tail = list->head->next;
      if (list->head->next == NULL)
      {
            printf("No element to delete\n");
            return -1;
      }
      while (tail->next != list->head->next)
      {
            tail = tail->next;
      }
      tail->next = current->next;
      list->head->next = current->next;
      x = current->data;
      free(current);
      list->count--;
      return x;
}

int deleteAtEnd(struct CLL *list)
{
      int x = -1;
      struct Node *current = NULL;
      struct Node *tail = list->head->next;
      if (list->head->next == NULL)
      {
            printf("No element to delete \n");
            return -1;
      }
      while (tail->next != list->head->next)
      {
            current = tail;
            tail = tail->next;
      }
      current->next = tail->next;
      x = tail->data;
      free(tail);
      list->count--;
      return x;
}

int deleteAtPos(struct CLL *list, int pos)
{
      struct Node *current = list->head->next;
      struct Node *prev = NULL;
      int x = -1;
      if (pos < 0 || pos >= list->count)
      {
            printf("invalid position to delete the element\n");
            return -1;
      }
      if (pos == 0)
      {
            x = deleteAtStart(list);
      }
      else if (pos == list->count - 1)
      {
            x = deleteAtEnd(list);
      }
      else
      {

            for (int i = 0; i < pos && current->next != list->head->next; i++)
            {
                  prev = current;
                  current = current->next;
            }
            prev->next = current->next;
            x = current->data;
            free(current);
            list->count--;
            return x;
      }
}

int searchByKey(struct CLL *list, int key)
{
      if (list->head->next == NULL)
      {
            printf("List is Empty\n");
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
            pos++;
            current = current->next;
      } while (current != list->head->next);
      printf("\nkey not found\n");
      return -1; // indicates key not found
}

int searchByPos(struct CLL *list, int pos)
{
      if (list->head->next == NULL)
      {
            printf("List is empty\n");
            return -1;
      }
      struct Node *current = list->head->next;
      int curpos = 0;
      do
      {
            if (curpos == pos)
            {
                  return current->data;
            }
            curpos++;
            current = current->next;
      } while (current != list->head->next);

      printf("invalid position \n");
      return -1;
}

int deleteByKey(struct CLL *list, int key)
{
      int pos = searchByKey(list, key);
      if (pos == -1)
      {
            printf("invalid pos to delete the key element\n");
            return -1;
      }
      else
      {
            deleteAtPos(list, pos);
      }
}

void reverse(struct CLL *list)
{
      struct Node *current = list->head->next;
      struct Node *nextNode = NULL;
      struct Node *prev = NULL;

      if (list->head->next == NULL)
      {
            printf("List is empty. Cannot reverse.\n");
            return;
      }

      do
      {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
      } while (current != list->head->next);

      list->head->next = prev;
}

void copyList(struct CLL *list, struct CLL *newList)
{
      if (list->head->next == NULL)
      {
            printf("source list is empty.nothing to copy\n");
            return;
      }
      struct Node *orginal = list->head->next;
      do
      {
            insertAtEnd(newList, orginal->data);
            orginal = orginal->next;

      } while (orginal != list->head->next);
      printf("\nlist copied -> ");
}

void insertInOrder(struct CLL *list, int value)
{
      struct Node *newNode = createNode(value);

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
      }
      else
      {
            prev->next = newNode;
            newNode->next = current;
            list->count++;
      }
}

int main()
{

      struct CLL *list = (struct CLL *)malloc(sizeof(struct CLL));
      // struct CLL *newlist = (struct CLL *)malloc(sizeof(struct CLL));
      createList(list, 10);
      insertAtStart(list, 5);
      insertAtEnd(list, 10);
      insertAtEnd(list, 20);
      insertAtEnd(list, 30);
      insertAtStart(list, 2);
      insertInOrder(list, 25);
      display(list);
      printf("\nElement at pos : %d", searchByPos(list, 1));
      return 0;
}