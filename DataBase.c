/*
=====================================================================
Assignment : DataBase of Students
Name : Gaurav Ghati
class : SE 10
Batch : F 10
=====================================================================
*/

int i=0;
const int BASEROLL = 23201; 

void add(struct Student &students[50], int num);      //num = total number of students  
void display(struct Student &students[50], int num);
void modify(struct Student &students[50], int roll);  //roll = index of the array
void delete(struct Student &students[50], int roll);
void search(struct Student &students[50], int roll);
void displayMenu();

struct Student{
   int stuRoll;
   char name[20];
   int marks[2];
   char city[20];
   int mobNo;
};

void delete(struct Student &students[50], int roll){
   i =  
}

void main(){
       
}







void displayMenu(){   //Done
  printf("\n<-------DataBase Operations------->");
  printf("\n1) Add Student.");
  printf("\n2) Modify Details");
  printf("\n3) Delete Student");
  printf("\n4) Display Menu");
  printf("\n5) Exit");
}

void display(struct Student &students[50], int num){       //Done
   printf("\n<----------------------------------STUDENT DATABASE------------------------------------->");
   printf("\nRollNo.\tName\tCity\tMob Number\tMarks 1\tMarks 2");
   printf("\n---------------------------------------------------------------------------------------------");
   for(i=0; i<num; i++){
     printf("%d\t%s\t%s\t%d\t%d\t%d",students[i].stuRoll, students[i].name, students[i].city, students[i].mobNo, students[i].marks[0],students[i].marks[0]);
   }  
   printf("\n---------------------------------------------------------------------------------------------");   
}

void search(struct Student &students[50], int roll){   //Done
    i = roll-BASEROLL;   
    printf("\nDetails of Student:");
    printf("\n%d\t%s\t%s\t%d\t%d\t%d",students[i].stuRoll, students[i].name, students[i].city, students[i].mobNo, students[i].marks[0],students[i].marks[0]);
}

void modify(struct Student &students[50], int roll){         //Done
     i = roll-BASEROLL;
     int ch = 0;
     printf("what you wannna Update:\n1)Name\n2)City\n3)Mobile Number\n4)Marks 1");
     scanf("%d",&ch);
     
     switch(ch){
       case 1: printf("\nUPDATE the Name of Student:");
               scanf("%s",&students[i].name);
               break;
               
       case 2: printf("\nUPDATE the City:");
               scanf("%s",&students[i].city);
               break;
               
       case 3: printf("\nUPDATE the Mobile NUmber:");
               scanf("%s",&students[i].mobNo);
               break;
               
       case 4: printf("\nUPDATE the Marks of students of previous year:");
               scanf("%d %d",&students[i].marks[0], &students[i].marks[1]);  
               break;
       default: printf("\nEnter Valid Choice...");               
     }
}


void add(struct Student &students[50], int num){     // num = total number of student present in database  //Done
   printf("\nEnter the Name of Student:");
   scanf("%s",&students[num-1].name);
   printf("\nEnter the City:");
   scanf("%s",&students[num-1].city);
   printf("\nEnter the Mobile NUmber:");
   scanf("%s",&students[num-1].mobNo);
   printf("\nEnter the Marks of students of previous year:");
   scanf("%d %d",&students[num-1].marks[0], &students[num-1].marks[1]);  
} 
