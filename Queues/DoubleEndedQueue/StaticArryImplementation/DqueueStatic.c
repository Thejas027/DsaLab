#include <stdio.h>
#define MAX_SIZE 5

struct Queue
{
  int front;
  int rear;
  int Q[MAX_SIZE];
} q;

void insertAtRear(int value)
{
  if (q.rear == MAX_SIZE - 1)
  {
    printf("Queue is overflow\n");
    return;
  }
  if (q.front == -1)
  {
    q.front = 0;
  }
  q.rear++;
  q.Q[q.rear] = value;
}

void insertAtFront(int value)
{
  if (q.front == -1)
  {
    q.front = q.rear = 0;
    q.Q[q.front] = value;
  }
  else if (q.front != 0)
  {
    q.Q[--q.front] = value;
  }
  else
  {
    printf("Element cannot be inserted at front\n");
  }
}

int deleteAtFront()
{
  if (q.front == -1)
  {
    printf("Queue is empty\n");
    return -1;
  }
  int x = q.Q[q.front++];
  if (q.front > q.rear)
  {
    // Reset front and rear when the queue becomes empty
    q.front = q.rear = -1;
  }
  return x;
}

int deleteAtRear()
{
  if (q.rear == -1)
  {
    printf("Queue is empty\n");
    return -1;
  }
  int x = q.Q[q.rear--];
  if (q.front > q.rear)
  {
    // Reset front and rear when the queue becomes empty
    q.front = q.rear = -1;
  }
  return x;
}

void display()
{
  printf("Queue elements: ");
  for (int i = q.front; i <= q.rear; i++)
  {
    printf("%d ", q.Q[i]);
  }
  printf("\n");
}

int main()
{
  // Initializing the queue
  q.front = q.rear = -1;

  int value, choice;
  do
  {
    printf("\nMENU\n");
    printf("1.Insert At Front\n");
    printf("2.Insert At Rear\n");
    printf("3.TO display elements\n");
    printf("4.Delete At Front\n");
    printf("5.Delete At REar\n");
    printf("6.To exit the program\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the value to be inserted at front : ");
      scanf("%d", &value);
      insertAtFront(value);
      break;

    case 2:
      printf("Enter the value to be inserted at Rear : ");
      scanf("%d", &value);
      insertAtRear(value);
      break;

    case 3:
      display();
      break;

    case 4:
      printf("Element deleted from front : %d", deleteAtFront());
      break;
    case 5:
      printf("Element deleted from Rear : %d", deleteAtRear());
      break;
    case 6:
      printf("To exit the program ...\n");
      return 1;
    default:
      printf("Inavlid choice..\n");
      break;
    }
  } while (choice != 7);
  return 0;
}
