/*Create two pointer called PS1 and PS2 to two strings, Read the contents 
using pointers and also write a function StrCat (PS1, PS2) which 
concatenates second string to the end of first string using pointers PS1 
and PS2.*/

#include<stdio.h>
#include<string.h>


void read(char *s){
  printf("enter the string value\n");
  scanf("%s",s);
}

void concat(char *s1,char *s2){
  int i=0;
  while (*s1 != '\0')
  {
    s1++;
    i++;
  }
  while(*s2 != '\0'){
    *s1 = *s2;
    s1++;
    s2++;
    i++;
  }
  *s1 = '\0';
  printf("the conacted string is %s",s1-i);
}
int main(){

  char str1[100], str2[100];
  read(str1);
  read(str2);
concat(str1,str2);

}