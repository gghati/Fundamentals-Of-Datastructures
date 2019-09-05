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
	int rollno;
	char name[50];
	int percentage;
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
		printf("\nRoll No: ");
		scanf("%d", &st[i].rollno);
		printf("\nName: ");
		scanf("%s", st[i].name);
		printf("\nPercentage: ");
		scanf("%d", &st[i].percentage);
	}

	selectionSort(st, noOfStu);
	display(st, noOfStu);

	return EXIT_SUCCESS;
}

void display(Stu st[], int noOfStu){
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

void bubbleSort(Stu st[], int no){
	int sorted = false;
	int last = no - 1;
	for(int i=0; (i<last) && !sorted; i++){
		sorted = true;
		for(j=last; j>i; j--){
			if(strcmp(st[j].name, st[j-1].name) < 0){
				swap(&st[j], &st[j-1]);
				sorted = false;
			}
		}
	}
}

void selectionSort(Stu st[], int no){
	Stu *min = &st[0];
	for(i=0; i<no; i++){
		for(j=i+1; j<no-1; j++){
			if(strcmp(min->name, st[j].name) < 0){
				swap(min, &st[j]);
			}
		}
	}
}

void binarySearch(Stu st[], int no){

}

void swap(Stu *s1, Stu *s2){
    Stu *temp = NULL;
    *temp = *s1;
    *s1 = *s2;
    *s2 = *temp;
}

