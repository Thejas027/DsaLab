/*Another method for desiging the prirority queue
 where the insertion of prirored data is inserted based on the data's prirority
and the element is dequeued similar to queue.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct PQueue
{
  int front;
  int rear;
  int Q[MAX_SIZE];
} q;

void enqueue(int value)
{
  if (q.rear == MAX_SIZE - 1)
  {
    printf("queue is full cannot insert the element\n");
    return;
  }
  int pos = q.rear;
  while (pos >= q.front && value <= q.Q[pos])
  {
    q.Q[pos + 1] = q.Q[pos--];
  }
  q.Q[pos + 1] = value;
  q.rear++;
}

int dequeue()
{
  if (q.front > q.rear)
  {
    printf("queue is empty no element to delete from queue");
    return -1;
  }
  int value = q.Q[q.rear++];       // this gives the element form the front end side where the prirority higher from this side
  //int value = q.Q[q.rear--];     // use this to get the element from the rear side and if the priroirty is high form rear side 
  return value;
}

int main()
{
  q.front = 0;
  q.rear = -1;

  enqueue(2);
  enqueue(10);
  enqueue(5);
  enqueue(1);

  printf("Dequeued element :  %d\n ", dequeue());
  printf("Dequeued element :  %d\n ", dequeue());
  return 0;
}