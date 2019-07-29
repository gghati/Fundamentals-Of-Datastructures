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

struct Student{
   int stuRoll;
   char name[20];
   int marks[2];
   char city[20];
   int mobNo;
};

//void add(struct Student students[50], int num);      //num = total number of students  
//void display(struct Student students[50], int num);
//void modify(struct Student students[50], int roll);  //roll = index of the array
//void delete(struct Student students[50], int num, int roll);
//void search(struct Student students[50], int roll);
//void displayMenu();


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
           add(stu, num);     
           num++;
           break;
           
       case 2:
           printf("Which Roll No you want to modify:");
           scanf("%d", &roll);
           modify(stu, roll);
           break;
           
       case 3:
           printf("Which field you want to modify:");
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
      if(roll>=(BASEROLL+i)){
         for(int j=0; j<20; j++){
            students[i].name[j] = students[i+1].name[j];
            students[i].city[j] = students[i+1].city[j];
            if(j<2){
              students[i].marks[j] = students[i+1].marks[j];
            }
         }
         students[i].mobNo;
      }
   }
   students[num-1].stuRoll = 0;
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
   printf("\n<----------------------------------STUDENT DATABASE------------------------------------->");
   printf("\nRollNo.\tName\tCity\tMob Number\tMarks 1\tMarks 2");
   printf("\n---------------------------------------------------------------------------------------------");
   for(i=0; i<num; i++){
     printf("\n%d\t%s\t%s\t%d\t%d\t%d",students[i].stuRoll, students[i].name, students[i].city, students[i].mobNo, students[i].marks[0],students[i].marks[0]);
   }  
   printf("\n---------------------------------------------------------------------------------------------");   
}

void search(struct Student students[50], int roll){   //Done
    i = roll-BASEROLL;   
    printf("\nDetails of Student:");
    printf("\n%d\t%s\t%s\t%d\t%d\t%d",students[i].stuRoll, students[i].name, students[i].city, students[i].mobNo, students[i].marks[0],students[i].marks[0]);
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
               scanf("%d",&students[i].mobNo);
               break;
               
       case 4: printf("\nUPDATE the Marks of students of previous year:");
               scanf("%d %d",&students[i].marks[0], &students[i].marks[1]);  
               break;
       default: printf("\nEnter Valid Choice...");               
     }
}


void add(struct Student students[50], int num){     // num = total number of student present in database  //Done
   students[num].stuRoll = BASEROLL + num;
   printf("\nEnter the Name of Student:");
   scanf("%s",students[num].name);
   printf("\nEnter the City:");
   scanf("%s",students[num].city);
   printf("\nEnter the Mobile NUmber:");
   scanf("%d",&students[num].mobNo);
   printf("\nEnter the Marks of students of previous year:");
   scanf("%d %d",&students[num].marks[0], &students[num].marks[1]);  
} 
