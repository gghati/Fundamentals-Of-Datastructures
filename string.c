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
void compare(char[]);
void palindrom(char[]);
void substring(char[]);
void copy(char[]);
void reverse(char[], char[]);

int i,j;

int main(){
  
  char str[50];
  printf("Enter the String A:\n");
  scanf("%s", &str);
  
  printf("Length of string A is :%d\n",length(str));
  palindrom(str);
}

int length(char a[]){
  int len = 0;
  for(i=0; i<50; i++){
     if(a[i] == '\0'){
        return i;
     }
  }
  printf("Length of the Array is :%d\n", len);
}

void compare(char str[50]){  
  char str2[50];
  printf("Enter the second String to compare : \n");
  scanf("%s", &str2);
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

void substring(char a[]){
  char b[50];
  printf("Enter The string B to check it is substring of A or not:\n");
  scanf("%s",&b);
  
  if(length(a) > length(b)){
    
    //Start from here check for substring
    for()
    
  
  } else {printf("The String B Is not subString of A")}
}

void displayMenu(){
   printf("<<-----------Menu------------->>\n");
   printf("1. Length of String A\n");
   printf("2. Copy any String in String A\n");
   printf("3. Reverse String A\n");
   printf("4. Check for Palindrom\n");
   printf("5. Check for substring\n");
   printf("6. compare Any String with A\n");
   printf("7. Display menu\n");
   printf("8. Exit\n");
}
