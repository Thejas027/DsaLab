#include <stdio.h>
#include "Queue.h" // queue header file included to access the enqueue and dequeue opereations

// function to find the  BREADTH FIRST SEARCH OF A Graph
void BFS(int G[][7], int start, int n)
{
  int visited[7] = {0}; // keeps the track of visited vertex of a graph

  printf("%d ", start);
  visited[start] = 1;
  enqueue(start);

  while (!isEmpty())
  {
    int i = dequeue();
    for (int j = 1; j < n; j++)
    {
      if (G[i][j] == 1 && visited[j] == 0)
      {
        printf("%d ", j);
        visited[j] = 1;
        enqueue(j);
      }
    }
  }
}

// Recursive function to find the DEPTH FIRST OF A Graph
void DFS(int G[][7], int start, int n)
{
  static int visited[7] = {0}; // this visited array must be static in dfs since for recursively calling function its value chnages continously so need to be kept static only(if it is not static then desired output is not obtained)
  int j;
  if (visited[start] == 0)
  {
    printf("%d ", start);
    visited[start] = 1;
    for (j = 1; j < n; j++)
    {
      if (G[start][j] == 1 && visited[j] == 0)
        DFS(G, j, n); // RECURSIVELY CALLING THE FUNCTION
    }
  }
}
int main()
{
  int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 1, 1, 0, 0, 0},
                 {0, 1, 0, 0, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0, 0},
                 {0, 0, 1, 1, 0, 1, 1},
                 {0, 0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0, 0}};
  printf("DFS of a Graph :");
  DFS(G, 1, 7);
  printf("\nBFS of a Graph : ");
  BFS(G, 1, 7);
  return 0;
}
