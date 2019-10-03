/* 
=====================================================================
Assignment : String Operations ( With pointers )
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Perform following String operations with and without pointers to arrays (without using the library functions):
	a) substring
	b) palindrome
	c) compare
	d) copy
	e) Reverse.

====================================================================
*/

#include<stdio.h>
#include<stdlib.h>

int length(char *ptr);
void compare(char *ptr,char *ptr2);
void palindrom(char *ptr);
void substring(char *ptr, char *ptr2);
void copy(char *ptr,char *ptr2);     //Copy second into first
void reverse(char *ptr);

int i,j;

int main(){
  
  int choice;
  char *ptr = (char*)malloc(50*sizeof(char));
  char *ptr2 = (char*)malloc(50*sizeof(char));
  int exit = 0;
  
  displayMenu();
  do{
    printf("ENTER CHOICE (7 for Display Menu) :\n");
    scanf("%d", &choice);
    
    if(!(choice==7 || choice==8)){
      printf("Enter String:");
      scanf("%s", ptr);
    }
    switch(choice){
      case 1:
          printf("Length of the String is %d\n\n",length(ptr));
          break;
      
      case 2:
          printf("Enter second String: ");
          scanf("%s", ptr2);
          copy(ptr,ptr2);
          break;
      
      case 3:        
          reverse(ptr);
          break;
      
      case 4:
          palindrom(ptr);
          break;
      
      case 5: 
          printf("Enter substring String:");
          scanf("%s", ptr2);
          substring(ptr,ptr2);
          break;
          
      case 6:
          printf("Enter second String:");
          scanf("%s", ptr2);
          compare(ptr, ptr2);
          break;
          
      case 7:
          displayMenu();
          break;
      
      case 8:
          exit = 1;        
    }
  }while(exit==0);
  
  return 0;
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

int length(char *ptr){
  int len = 0;
  
  for(i=0; i<50; i++){
     if(*(ptr+i) == '\0'){
        return i;
     }
  }
  return 0;
}

void compare(char *ptr, char *ptr2){  
  int flag = 0;
  i=0;
  
  if(length(ptr)!=length(ptr2)){
    printf("The two strings are not similar.\n");
  }
  
  while(*(ptr+i)!='\0' || *(ptr2+i)!='\0'){
    if(*(ptr+i) != *(ptr2+i)){
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

void palindrom(char *ptr){
  int l = length(ptr);
  int flag = 0;
  
  for(i=0; i<l/2; i++){
    if(*(ptr+i) != *(ptr+l-i-1)){
       flag = 1;
    }
  }
  if(flag==0)
     printf("The String is palindrom!\n\n");
  else   
     printf("The String is not Palindrom!\n\n");
}

void substring(char *ptr, char *ptr2){        // b is substring of a
  
  int al = length(ptr);
  int bl = length(ptr2);
  int flag = 0;
  int count = 0;
  
  if(al > bl){
    for(i=0; i<al-bl+1; i++){
       for(j=0; j<bl; j++){
          if(*(ptr+i+j)==*(ptr2+j)){
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
      printf("The String B is not substring of A\n\n");
    }else{
      printf("The String B is substring of A and it occur %d times\n\n",flag);
    }
      
  } else {printf("The String B Is not subString of A\n\n");}
}

void copy(char *ptr, char *ptr2){
  int al = length(ptr);
  int bl = length(ptr2);
  char *ptr3 = (char*)malloc(50*sizeof(char));
  
  for(i=0;i<al;i++){
    *(ptr3+i) = *(ptr+i);       
  }  
  
  for(i=0; i<bl; i++){
    *(ptr3+i+al) = *(ptr2+i);
  }
  printf("The Copied String is: ");
  for(i=0;i<bl+al;i++){
    printf("%c", *(ptr3+i));
  }
  printf("\n\n");  
}

void reverse(char *ptr){
  int al = length(ptr);
  printf("The Reversed String is: ");
  for(i=al-1;i>=0;i--){
    printf("%c",*(ptr+i));    
  } 
  printf("\n\n");
}
