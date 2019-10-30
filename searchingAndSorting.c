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
int binarySearch(Stu st[], char arr[], int no);

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

	int ch, exit;
	exit = false;
	char arr[20];

	while(!exit){
		displayMenu();
		printf("\nEnter the choice: ");
		scanf("%d", &ch);

		switch(ch){
			case 1: bubbleSort(st, noOfStu);
					 break;
			case 2: selectionSort(st, noOfStu);
					 break;
			case 3:	printf("Enter the name to be Searched!");
				    scanf("%s", arr);
				    binarySearch(st, arr, noOfStu);
				    break;
			case 4: exit = true;
		}
	}
	return 0;
}

void display(Stu st[], int noOfStu){
	printf("\n<------------- Student Data ---------------->");
	printf("\nRollNo\tName\tPercentage");
	for(i=0; i<noOfStu; i++){
		printf("\n%d\t%s\t%d",st[i].rollno, st[i].name, st[i].percentage);
	}
	printf("\n------------------------------------------");
}

void displayMenu(){
	printf("\n<----------------- Menu ------------------>");
	printf("\n1) Display the data in ascending order of name (Bubble Sort)");
	printf("\n2) Display the data in descending order of name(Selection sort)");
	printf("\n3) Display data for RollNo specified by user (Binary search)");
	printf("\n4) Exit");
}

void bubbleSort(Stu st[], int no){								//DONE
	for(i=0;i<no; i++){
		for(j=no-1; j>i; j--){
			if(st[j-1].rollno > st[j].rollno){
				swap(&st[j-1], &st[j]);
			}
		}
	}
	display(st, no);
}

void selectionSort(Stu st[], int no){							//DONE
	for(i=0; i<no-1; i++){
		int max = i;
		for(j=i+1; j<no; j++){
			if(st[max].rollno < st[j].rollno)
				max = j;
		}
		swap(&st[max], &st[i]);
	}
	display(st, no);
}

// inary search not working properly
// refer SearchSort.cpp for correct binary search algo

int binarySearch(Stu st[], char arr[], int no){			// DONE
	int left;
	int right = no -1;
	int middle;
	while(left <= right){
		middle = (left + right)/2;
		switch(strcmp(st[middle].name, arr)){
			case -1: left = middle + 1;
			        break;
			case 0: printf("Element Found");
				    return middle;
			        break;
			case 1: right = right -1;
		}
	}
	printf("Element not Found");
	display(st, no);
	return -1;
}

void swap(Stu *s1, Stu *s2){
    Stu temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}


