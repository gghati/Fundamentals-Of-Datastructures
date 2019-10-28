/*
=====================================================================
Assignment : Sorting & Searching operations
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Accept Mobile user information (e.g. MobileNo, Name, BillAmount etc.).
	a) Display the data in descending order of Name (Quicksort, recursive)
	b) Display the data in ascending order of MobileNo (Quicksort nonrecursive)
	c) Display pivot position and its corresponding list in each pass.
	d) Display the number of passes and comparisons for different test cases (Worst, Average, Best case).
====================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Mobile{
	long long int mobno;
	char name[20];
	float bill;
} MOB;

MOB mob[50];

void swap(MOB* a, MOB* b){
	MOB r;
	r = *a;
	*a = *b;
	*b = r;
}

int partition(int l, int r){
	long long int pivot = mob[r].mobno;
	int flag = 1;
    int i = l;
    int j = r;
    while (flag) {
    	while (mob[i].mobno <= pivot && i<j) 
      		i++;
    	while (mob[j].mobno > pivot)
        	j--;
    	if (i < j)
        	swap(&mob[i], &mob[j]);
        else 
        	flag = 0;	
    }
	swap(&mob[l], &mob[j]);
	return j;
}

void quicksort(int l, int r){
	if(l<r){
  		int	j = partition(l, r);
		quicksort(l, j);
		quicksort(j+1, r);
	}
}

void acceptData(int t){			//Get Data
    printf("\nCustomer %d :",t+1);
    printf("\n");

    while(getc(stdin)!='\n');
	do
    {
        printf("Name : ");
        scanf("%s", mob[t].name);
        if(strlen(mob[t].name)==0)
            printf("\nName Cannot be Empty...!!\n");
    }while(strlen(mob[t].name)==0);

	do
	{
		printf("Mobile No. : ");
		scanf("%lld",&mob[t].mobno);
		if((mob[t].mobno<1000000000)||(mob[t].mobno>9999999999))
			printf("Enter CORRECT 10 Digit Mobile No. !!\n");
	}while((mob[t].mobno<1000000000)||(mob[t].mobno>9999999999));   //Validation of Mobile Number
	
	printf("Bill Amount : ");
    scanf("%f",&mob[t].bill);
}

void displayData(int j)			//Displaying Data
{
	printf("\n %5d\t\t%s\t\t%lld\t%2f", j+1, mob[j].name, mob[j].mobno, mob[j].bill);
}

int main(){
	int t, i=0;
	printf("\nEnter no. of records : ");
	scanf("%d",&t);
	for(i=0;i<t;i++)
		acceptData(i);
		
	for(i=0;i<t;i++)
		displayData(i);
		
	quicksort(0,t-1);
	
	printf("\n\nAfter Quicksort: \n");
	
	for(i=0;i<t;i++)
		displayData(i);
	return 0;
}


