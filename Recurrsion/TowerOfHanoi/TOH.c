// simple program of recurssion [TOWER OF HANOI]

#include <stdio.h>

// fuction of tower of hanoi

void TOH(int n, char src, char temp, char dest)
{
  if (n == 1)
  {
    printf("Move % d from %c to %c\n", n, src, dest);
    return;
  }

  TOH(n - 1, src, dest, temp);
  printf("Move %d from %c to %c\n", n, src, dest);
  TOH(n - 1, temp, src, dest);
}

int main()
{
  char src = 'A', temp = 'B', dest = 'C';
  TOH(3, src, temp, dest);
  return 0;
}