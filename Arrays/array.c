#include <stdio.h>

void read(int arr[], int n)
{
  printf("enter the array elements\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void search(int arr[], int n)
{
  int key;
  printf("enter the key element to search\n");
  scanf("%d", &key);
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      printf("%d element found at %d", key, i);
      return;
    }
  }
}

void reverse(int arr[], int n)
{
  int s = 0;
  int e = n - 1;
  while (s < e)
  {
    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;
    s++;
    e--;
  }
  printf("the reversed array is :");
  for (int i = 0; i < n; i++)
  {
    printf("%d", arr[i]);
  }
}

void insertAtPosition(int arr[], int *n)
{
  int key;
  printf("enter the value to be inserted to array\n");
  scanf("%d", &key);
  int j;
  printf("enter the array position to be inserted\n");
  scanf("%d", &j);

  if (j < 0 || j > *n)
  {
    printf("element cannot be inserted\n");
    return;
  }

  for (int i = *n; i > j; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[j] = key;
  (*n)++;

  printf("The array element after insertion :");
  for (int i = 0; i < *n; i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");
}

void searchByPosition(int arr[], int *n)
{
  printf("enter the position to be searched\n");
  int j;
  scanf("%d", &j);

  if (j < 0 || j >= *n)
  {
    printf("invalid position \n");
    return;
  }
  else
  {
    printf("the element at index %d is %d", j, arr[j]);
  }
}

void insertByKey(int arr[], int *n)
{
  printf("Enter the key element to check if it is in range: ");
  int key;
  scanf("%d", &key);

  // Check if the key is within the valid range
  if (key < 0 || key > *n)
  {
    printf("Invalid key. Please enter a key within the range.\n");
    return;
  }

  printf("Enter the new element to be inserted: ");
  int newElement;
  scanf("%d", &newElement);

  // Shift elements to the right to make space for the new element
  for (int i = *n; i > key; i--)
  {
    arr[i] = arr[i - 1];
  }

  arr[key] = newElement; // Insert new element at the key position
  (*n)++;                // Increment the size of the array

  printf("The array elements after insertion: ");
  for (int i = 0; i < *n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void greatestInArray(int arr[], int n)
{
  int big = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (big < arr[i])
    {
      big = arr[i];
    }
  }
  printf("The greatest ele in an array: %d\n", big);
}

int main()
{

  int n;
  printf("enter the size of array\n");
  scanf("%d", &n);
  int arr[n];
  read(arr, n);
  int choice;

  do
  {
    printf("Array operations\n");
    printf("1.Search the key element\n");
    printf("2.Reverse an array\n");
    printf("3.insert by position\n");
    printf("4.Search by position\n");
    printf("5.insertBykey\n");
    printf("6.Greatest in an array\n");
    printf("Enter the choice\n");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
      search(arr, n);
      break;

    case 2:
      reverse(arr, n);
      break;

    case 3:
      insertAtPosition(arr, &n);
      break;

    case 4:
      searchByPosition(arr, &n);
      break;
    case 5:
      insertByKey(arr, &n);
      break;
    case 6:
      greatestInArray(arr, n);
      break;
    default:
      printf("invalid choice\n");
      break;
    }

  } while (choice != 6);
}