/*
=====================================================================
Assignment : Sorting & Searching operations
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Accept student information (e.g. RollNo, Name, Percentage etc.)
a) Display the data in ascending order of name (Bubble Sort)
b) Display the data in descending order of name(Selection sort)
c) Display data for RollNo specified by user (Binary search)
d) Display the number of passes and comparisons for different test cases (Worst, Average, Best case).
====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define false 0
#define true 1

typedef struct Student{
//	int rollno;
	char name[50];
//	int percentage;
}Stu;

void display(Stu st[], int noOfStu);
void displayMenu();
void bubbleSort(Stu st[], int noOfStu);
void selectionSort(Stu st[], int noOfStu);
void swap(Stu *s1, Stu *s2);

int i, j;

int main(void) {
	int noOfStu;
	printf("\nEnter the number of Students you want to Add: ");
	scanf("%d", &noOfStu);

	Stu st[noOfStu];

	for(i=0; i<noOfStu; i++){
		printf("\nEnter Details of Student %d", i+1);
//		printf("\nRoll No: ");
//		scanf("%d", &st[i].rollno);
		printf("\nName: ");
		scanf("%s", st[i].name);
//		printf("\nPercentage: ");
//		scanf("%d", &st[i].percentage);
	}

	selectionSort(st, noOfStu);
	display(st, noOfStu);

	return EXIT_SUCCESS;
}

void display(Stu st[], int noOfStu){
	printf("\n<-------------Student Data---------------->");
	printf("\nRollNo\tName\tPercentage");
	for(i=0; i<noOfStu; i++){
		printf("\n%d\t%s\t%d", 0 /* st[i].rollno */, st[i].name,  0 /* st[i].percentage */);
	}
	printf("\n------------------------------------------");
}

void displayMenu(){
	printf("1) Display the data in ascending order of name (Bubble Sort)");
	printf("2) Display the data in descending order of name(Selection sort)");
	printf("3) Display data for RollNo specified by user (Binary search)");
}

void bubbleSort(Stu st[], int no){								//DONE
	for(i=0;i<no; i++){
		for(j=0; j<no-1; j++){
			if(strcmp(st[j].name, st[j+1].name) > 0){
				swap(&st[j], &st[j+1]);
			}
		}
	}
}

void selectionSort(Stu st[], int no){
	for(i=0; i<no-1; i++){
		int min = i;
		for(j=i+1; j<no; j++){
			if(strcmp(st[min].name, st[j].name) < 0){
				min = j;
		    }
			swap(&st[min], &st[i]);
		}
	}
}

void binarySearch(Stu st[], int no){

}

void swap(Stu *s1, Stu *s2){
    Stu *temp;
    *temp = *s1;
    *s1 = *s2;
    *s2 = *temp;
}

