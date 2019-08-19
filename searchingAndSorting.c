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

struct Student{
	int rollno;
	char name[50];
	int percentage;
};

void display(struct Student st[], int noOfStu);
void displayMenu();
void bubbleSort(struct Student st[], int noOfStu);
void selectionSort(struct Student st[], int noOfStu);

int i;

int main(void) {
	int noOfStu;
	printf("\nEnter the number of Students you want to Add: ");
	scanf("%d", &noOfStu);

	struct Student st[noOfStu];

	for(i=0; i<noOfStu; i++){
		printf("\nEnter Details of Student %d", i+1);
		printf("\nRoll No: ");
		scanf("%d", &st[i].rollno);
		printf("\nName: ");
		scanf("%s", st[i].name);
		printf("\nPercentage: ");
		scanf("%d", &st[i].percentage);
	}

	display(st, noOfStu);

	return EXIT_SUCCESS;
}
void display(struct Student st[], int noOfStu){
	printf("\n<---------------------Student Data--------------------->");
	printf("\nRollNo\tName\tPercentage");
	for(i=0; i<noOfStu; i++){
        printf("\n%d\t%s\t%d", st[i].rollno, st[i].name, st[i].percentage);
	}
	printf("\n------------------------------------------------------");
}

void displayMenu(){
	printf("1) Display the data in ascending order of name (Bubble Sort)");
	printf("2) Display the data in descending order of name(Selection sort)");
	printf("3) Display data for RollNo specified by user (Binary search)");
}

void bubbleSort(struct Student st[], int noOfStu){

}

void selectionSort(struct Student st[], int noOfStu){

}
