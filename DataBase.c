/*
=====================================================================
Assignment : DataBase of Students
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement: Create a Database using array of structures and perform
following operations on it:
	a) Create Database
	b) Display Database
	c) Add record
	d) Search a record
	e) Modify a record
	f) Delete a record
=====================================================================
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i=0;
const int BASEROLL = 23201;

struct Student{
   int stuRoll;
   char name[20];
   int marks[3];
   char city[20];
   char mobNo[10];
};

int add(struct Student students[50], int num);      //num = total number of students
void display(struct Student students[50], int num);
void modify(struct Student students[50], int roll);  //roll = index of the array
void delete(struct Student students[50], int num, int roll);
void search(struct Student students[50], int roll);
void displayMenu();
int avg(int arr[3]);

int main(){
   struct Student stu[50];
   int num = 0;
   int exit = 0;
   int roll = 0;
   int ch;

   do{
     displayMenu();
     printf("\nENTER CHOICE:");
     scanf("%d", &ch);

     switch(ch){
       case 1:
           if(add(stu, num)==0){
             num++;
             printf("Student Added!");
           }else{
             printf("Enter the Mobile Field Correctly!");
             delete(stu, num+1, stu[num].stuRoll);
           }
           break;

       case 2:
           printf("Which Roll No you want to modify:");
           scanf("%d", &roll);
           modify(stu, roll);
           break;

       case 3:
           printf("Enter Roll Number which you want to delete:");
           scanf("%d", &roll);
           delete(stu, num, roll);
           num--;
           break;

       case 4:
           display(stu, num);
           break;

       case 5:
          exit = 1;
     }
   }while(exit!=1);

   return 0;
}

void delete(struct Student students[50], int num, int roll){   //DONE
   for(int i=0; i<num-1; i++){
      if((BASEROLL+i)>=roll){
         for(int j=0; j<20; j++){
            students[i].name[j] = students[i+1].name[j];
            students[i].city[j] = students[i+1].city[j];
            if(j<3){
              students[i].marks[j] = students[i+1].marks[j];
            }if(j<10){
              students[i].mobNo[j] = students[i+1].mobNo[j];
            }
         }
      }
   }
   students[num-1].stuRoll = 0;
   printf("\nDeleted Student!");
}

void displayMenu(){   //Done
  printf("\n<-------DataBase Operations------->");
  printf("\n1) Add Student.");
  printf("\n2) Modify Details");
  printf("\n3) Delete Student");
  printf("\n4) Display Details");
  printf("\n5) Exit");
}

void display(struct Student students[50], int num){       //Done
   printf("\n<----------------------------------------------------------STUDENT DATABASE------------------------------------------------------------>");
   printf("\nRollNo.\t\tName\t\tCity\t\tMob Number\tMarks 1\t\tMarks 2\t\tMarks 3\t\tPercentage");
   printf("\n------------------------------------------------------------------------------------------------------------------------------------------");
   for(i=0; i<num; i++){
     int total = 0;
     total = avg(students[i].marks);
     printf("\n%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d",students[i].stuRoll, students[i].name, students[i].city,
                    students[i].mobNo, students[i].marks[0],students[i].marks[1], students[i].marks[2], (total/3));
   }
   printf("\n-----------------------------------------------------------------------------------------------------------------------------------------");
}

int avg(int arr[3]){
   return arr[0] + arr[1] + arr[2];
}

void search(struct Student students[50], int roll){   //Done
    i = roll-BASEROLL;
    printf("\nDetails of Student:");
    printf("\n%d\t%s\t%s\t%s\t%d\t%d\t%d",students[i].stuRoll, students[i].name, students[i].city, students[i].mobNo, students[i].marks[0], students[i].marks[1], students[i].marks[2]);
}

void modify(struct Student students[50], int roll){         //Done
     i = roll-BASEROLL;
     int ch = 0;
     printf("what you wannna Update:\n1)Name\n2)City\n3)Mobile Number\n4)Marks");
     scanf("%d",&ch);

     switch(ch){
       case 1: printf("\nUPDATE the Name of Student:");
               scanf("%s", students[i].name);
               break;

       case 2: printf("\nUPDATE the City:");
               scanf("%s", students[i].city);
               break;

       case 3: printf("\nUPDATE the Mobile NUmber:");
               scanf("%s", students[i].mobNo);
               break;

       case 4: printf("\nUPDATE the Marks of students of 3 Subjects:");
               scanf("%d %d %d",&students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
               break;
       default: printf("\nEnter Valid Choice...");
     }
     printf("\nUpdation Done!");
}

int add(struct Student students[50], int num){     // num = total number of student present in database  //Done
   students[num].stuRoll = BASEROLL + num;
   printf("\nEnter the Name of Student:");
   scanf("%s",students[num].name);
   printf("\nEnter the City:");
   scanf("%s",students[num].city);
   printf("\nEnter the Mobile NUmber:");
   scanf("%s",students[num].mobNo);
  if(strlen(students[num].mobNo) != 10){
    return 1;
  }
   for (i=0; students[num].mobNo[i]!= '\0'; i++){
       if(isdigit(students[num].mobNo[i] != 0)){
          return 1;
       }
   }
   printf("\nEnter the Marks of students of previous year:");
   scanf("%d %d %d",&students[num].marks[0], &students[num].marks[1], &students[num].marks[2]);
   return 0;
}
