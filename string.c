/*
=====================================================================
Assignment : String Operations ( Without pointers )
Name : Gaurav Ghati
class : SE 10
Batch : F 10
Description : Assingment 2 in C
====================================================================
*/

#include<stdio.h>

int length(char[]);
void compare(char[],char[]);
void palindrom(char[]);
void substring(char[], char[]);
void copy(char[],char[]);     //Copy second into first
void reverse(char[]);

int i,j;

int main(){

  int choice;
  char str[50];
  char str2[50];

  printf("Enter String :");
  scanf("%s", &str);

  printf("Enter String :");
  scanf("%s", &str2);

  copy(str,str2);

  /*int len = length(str);
  printf("Length of the Array is :%d\n", len);
  /*displayMenu();
  do{
    printf("ENTER CHOICE (7 for Display Menu) :\n");
    scanf("%d", &choice);

    switch(choice){
      case 1:
          printf("Enter String :");
          scanf("%s", &str);
          length(str);
          break;

      case 2:



    }
  }*/
}

void displayMenu(){
   printf("<<-----------Menu------------->>\n");
   printf("1. Length\n");
   printf("2. Copy String in another String\n");
   printf("3. Reverse String\n");
   printf("4. Check for Palindrom\n");
   printf("5. Check for substring\n");
   printf("6. compare Any String with another\n");
   printf("7. Display menu\n");
   printf("8. Exit\n");
}

int length(char a[]){
  int len = 0;

  for(i=0; i<50; i++){
     if(a[i] == '\0'){
        return i;
     }
  }
  return 0;
}

void compare(char str[50], char str2[50]){
  int flag = 0;
  i=0;

  while(str[i]!='\0' || str2[i]!='\0'){
    if(str[i] != str2[i]){
       flag = 1;
       break;
    }
    i++;
  }
  if(flag == 0){
    printf("The two strings are same!\n");
  }else{
    printf("The two strings are not similar.\n");
  }
}

void palindrom(char a[]){
  int l = length(a);
  int flag = 0;

  for(i=0; i<l/2; i++){
    if(a[i] != a[l-i-1]){
       flag = 1;
    }
  }
  if(flag==0)
     printf("The String is palindrom!\n");
  else
     printf("The String is not Palindrom!\n");
}

void substring(char a[50], char b[50]){        // b is substring of  a

  int al = length(a);
  int bl = length(b);
  int flag = 0;
  int count = 0;

  if(al > bl){
    for(i=0; i<al-bl+1; i++){
       for(j=0; j<bl; j++){
          if(a[i+j]==b[j]){
             count++;
          }
          if(count==bl){
            flag++;
            printf("%d substring B of A is from %d to %d position.\n",flag,i,i+bl-1);
            count=0;
          }
       }
    }

    if(flag==0){
      printf("The String B is not substring of A\n");
    }else{
      printf("The String B is substring of A and it occur %d times\n",flag);
    }

  } else {printf("The String B Is not subString of A\n");}
}

void copy(char a[], char b[]){
  int al = length(a);
  int bl = length(b);
  char str3[50];

  for(i=0;i<al;i++){
    str3[i] = a[i];
  }

  for(i=al-1; i<bl+al; i++){
    str3[i] = b[i-(al-1)];
  }

  for(i=0;i<bl+al;i++){
    printf("%c", str3[i]);
  }
}
