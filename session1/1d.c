//Create a pointer to two dimensional array of integers. Write functions 
//Read (P) and Display (P) to read and display the contents using pointer

#include<stdio.h>

void read(int *a,int n){
printf("enter the array elemnts\n");
for(int i=0; i<n; i++){
  for(int j=0; j<n; j++){
    scanf("%d",(a+i*n+j));
  }
}
}


void display(int *a,int n){
  printf("the array elements are (displyaing through pointer) \n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d",*(a+i*n+j));
    }
    printf("\n");
  }
}

int main()
{
  int n;
  printf("enter the size of array\n");
  scanf("%d",&n);
  int arr[n][n];
  int *ptr;
  ptr = &arr[0][0];
  read(ptr,n);
 display(ptr,n);
  return 0;
}