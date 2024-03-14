/*Create a pointer to an integer array and pass this as parameter to a 
function called Reverse which reverses the array contents using pointer. 
Write different functions called Read (P) to read the array elements 
using pointer P and Display (P) to display the array contents using P 
before and after reverse.*/

#include<stdio.h>

void read(int *a,int n){
  printf("enter the elements to array\n");
  for(int i=0; i<n; i++){
    scanf("%d",(a+i));
  }
}

void reverse(int *a,int n){
  int s= 0;
  int e = n-1;
  while (s<e)
  {
    int temp = *(a+s);
    *(a+s) = *(a+e);
    *(a+e) = temp;
    s++;
    e--;
  }
  
}

void display(int *a,int n){
  printf("the reversed arry elements are:");
  for(int i=0; i<n; i++){
    printf("%d",*(a+i));
  }
  printf("\n");
}

int main()
{
  int n;
  printf("enter the size of an array\n");
  scanf("%d",&n);
int arr[n];
int * ptr;
ptr = arr;

read(ptr,n);

reverse(ptr,n);
display(ptr,n);
  return 0;
}