// it just contains just a recurssive functions no main function is written


#include <stdio.h>

// recursive code to find the fibbonacii series of a given n numbers
int fib(int n)
{
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

// recursive code to find the factroial of a given n number
int factroial(int n)
{
  if (n == 1)
    return 1;

  return n * factroial(n - 1);
}

// recursive code to find the greatest common divisor

int GCD(int m, int n)
{
  if (n == 0)
    return m;
  return GCD(n, (m % n));
}

// recursive code to find the sum of an array elements

int sum(int arr[], int n)
{
  if (n == 1)
    return arr[n - 1];
  return arr[n - 1] + sum(arr, n);
}

// recursive code to find the max element in an a given array

int max(int arr[], int n)
{
  if (n == 1)
    return arr[n - 1];

  int largest = max(arr, n - 1);
  if (largest > arr[n - 1])
    return largest;

  return arr[n - 1];
}
