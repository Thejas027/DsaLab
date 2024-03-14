//Crate a pointer to an integer array, Read and display the contents using 
//pointer and also display the contents in reverse order using pointer

#include<stdio.h>


void read(int *a,int n){
  for(int i=0; i<n; i++){
    scanf("%d",(a+i));
  }
}


int main()
{
int n;
printf("enter the size of array\n");
scanf("%d" , &n);
int arr[n];
int *ptr;
ptr = arr;
read(ptr,n);

for(int i=n-1; i>=0; i--){
  printf("%d", *(ptr+i));
}

  return 0;
}