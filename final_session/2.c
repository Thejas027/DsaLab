/*
Develop a menu driven program to implement the following operations on an array of integers with dynamic
memory allocation. Display the array contents after each operation.
i) Insert by position ii) Delete by key iii) Search by position iv) Reverse the contents.
*/

#include <stdio.h>
#include <stdlib.h>

void read(int *arr, int n)
{
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
}

void display(int *arr, int n)
{
    printf("array elements are : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}

void insertByPos(int *arr, int *n, int pos, int val)
{
    if (pos >= 0 && pos <= *n)
    {
        for (int i = *n - 1; i >= pos; i--)
        {
            *(arr + i + 1) = *(arr + i);
        }
        *(arr + pos) = val;
        (*n)++;
    }
    else
    {
        printf("Invalid position to insert");
    }
}

int deleteByPos(int *arr, int *n, int pos)
{
    int val;
    if (pos >= 0 && pos <= *n)
    {
        val = *(arr + pos);
        for (int i = pos; i < *n - 1; i++)
        {
            *(arr + i) = *(arr + i + 1);
        }
        (*n)--;
    }
    return val;
}

int searchByEle(int *arr, int *n, int key)
{
    for (int i = 0; i < *n; i++)
    {
        if (*(arr + i) == key)
            return i;
    }
    return -1;
}

void deleteByKey(int *arr, int *n, int key)
{
    int pos = searchByEle(arr, n, key);
    if (pos != -1)
        deleteByPos(arr, n, pos);
    else
        printf("Invalid key..");
}

int searchByPos(int *arr, int *n, int pos)
{
    if (pos < 0 || pos > *n)
    {
        printf("inavlid position to search the element\n");
        return -1;
    }
    return *(arr + pos);
}

void Rev(int *arr, int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int temp = *(arr + start);
        *(arr + start) = *(arr + end);
        *(arr + end) = temp;
        start++;
        end--;
    }
}

int main()
{
    int n, pos, key, choice, val;
    printf("Enter the size of an array : ");
    scanf("%d", &n);

    int *arr;
    arr = (int *)malloc(n * sizeof(int)); // dynamically allocating memory in main function only

    do
    {
        printf("\nMenu\n");
        printf("1.to read\n");
        printf("2.to dispaly\n");
        printf("3.Insert by position\n");
        printf("4.delete by key\n");
        printf("5.search by pos\n");
        printf("6.to reverse\n");
        printf("7.to exit\n");
        printf("enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            read(arr, n);
            break;

        case 2:
            display(arr, n);
            break;
        case 3:
            printf("Enter the position to insert the element : ");
            scanf("%d", &pos);
            printf("Enter the value to be in the above specified position : ");
            scanf("%d", &val);
            insertByPos(arr, &n, pos, val);
            break;

        case 4:
            printf("enter the key val to delete : ");
            scanf("%d", &key);
            deleteByKey(arr, &n, key);
            // display(arr, n);
            break;

        case 5:
            printf("Enter the position value : ");
            scanf("%d", &pos);
            printf("The element at %d : %d ", pos, searchByPos(arr, &n, pos));
            break;

        case 6:
            // printf("The reversed array : ");
            Rev(arr, n);
            display(arr, n);
            break;

        case 7:
            free(arr);
            printf("exiting program...\n");
            return 0;
        default:
            printf("Invalid choice");
            break;
        }
    } while (choice != 7);
    return 1;
}