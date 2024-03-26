/*
Develop a menu driven program to implement the following operations on an array of integers with dynamic
memory allocation. Display the array contents after each operation.
i) Insert by order ii) Delete by position iii) Search by key iv) Reverse the contents.
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
        printf("invalid position to insert the element \n");
    }
}

void insertByOrder(int *arr, int *n, int val)
{
    int pos = 0;
    while (pos < *n && val > *(arr + pos))
        pos++;
    insertByPos(arr, n, pos, val);
}

int deleteByPos(int *arr, int *n, int pos)
{
    int val;
    if (pos >= 0 && pos <= *n)
    {
        val = *(arr + pos);
        for (int i = pos; i < *n - 1; i++)
            *(arr + i) = *(arr + i + 1);
        (*n)--;
        return val;
    }
    printf("invalid choice \n");
    return -1;
}

int searchBykey(int *arr, int *n, int key)
{
    for (int i = 0; i < *n; i++)
    {
        if (*(arr + i) == key)
            return i;
    }
    return -1;
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
        printf("3.Insert by order\n");
        printf("4.delete by pos\n");
        printf("5.search by key\n");
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

            printf("Enter the value to be inserted in order : ");
            scanf("%d", &val);
            insertByOrder(arr, &n, val);
            break;

        case 4:
            printf("enter the position to delete the element : ");
            scanf("%d", &pos);
            printf("deleted element at pos %d : %d ", pos, deleteByPos(arr, &n, pos));
            break;

        case 5:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            printf("The key %d is at pos : %d ", key, searchBykey(arr, &n, key));
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