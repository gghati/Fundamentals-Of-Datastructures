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

#define ll line(85);
#define nm 50
#define lim 80

void line(int n)		//For horizontal line of table
{
	int i;
	for(i=0;i<n;i++)
		printf("-");
	printf("\n");
}

struct Student
{
	int roll;
	char name[nm];
	int age;
	float percent;
}S[lim];

int checkRoll(int t)		//Check if Roll No. is Unique
{
	int i;
	for(i=0;i<t;i++)
		if(S[i].roll==S[t].roll)
			return 1;
	return 0;
}

void tabHead()
{
	ll
	printf("\nUnique Roll No.\t\tName of Student\t\tAge\tPercentage\n\n");
	ll
}

void acceptData(int t)			//Get Data
{
	printf("\nStudent %d :",t+1);
	do
	{
		printf("\nUnique Roll No. : ");
		scanf("%d",&S[t].roll);
		if(checkRoll(t))
			printf("\nEntered Roll No. Already Exists");
	}while(checkRoll(t));
	while(getc(stdin)!='\n');
	do
    {
        printf("Name : ");
        scanf("%s", S[t].name);
        if(strlen(S[t].name)==0)
            printf("\nName Cannot be Empty...!!\n");
    }while(strlen(S[t].name)==0);
	printf("Age : ");
	scanf("%s",&S[t].age);
	printf("Percentage : ");
	do
	{
		scanf("%f",&S[t].percent);
		if((S[t].percent<0)||(S[t].percent>100))
			printf("Enter CORRECT Percentage !!\n");
	}while((S[t].percent<0)||(S[t].percent>100));    //Validation of Percentage
}

void displayData(int j)			//Displaying Data
{
	printf("\n %5d\t\t\t%s\t\t\t%d\t%2f",S[j].roll,S[j].name,S[j].age,S[j].percent);
}

void swap(struct Student *S1,struct Student *S2)
{
	struct Student S;
	S = *S1;
	*S1 = *S2;
	*S2 = S;
}

void bubbleSort(int n)
{
	int i,j,k,t,h=1,g,swapSum = 0, compSum = 0;
	printf("\nProcess :-\n\nOriginal : ");
	for(k=0;k<n;k++)
		printf("%d   ", S[k].roll);
	printf("\n");
	for(i=0;i<n;i++)
	{
		t=0;
		g=0;
		for(j=(n-1);j>i;j--)
		{
		    g++;
			if(S[j-1].roll>S[j].roll)
			{
				swap(&S[j-1],&S[j]);
				t++;
			}
		}
		if(t==0)
			break;
		printf("Pass %d   : ", h);
		for(k=0;k<n;k++)
			printf("%d   ", S[k].roll);

		printf(" | Swaps = %d  | Comparisons = %d\n", t-1, g);
		swapSum += t-1;
		compSum += g;
		h++;
	}
	printf("\nHence List is Sorted in %d passes.\nTotal Swaps = %d.\nTotal Comparisons = %d.\n", h-1, swapSum, compSum+n-1);
}


void selectionSort(int n)
{
	int i,j,max,k,h=1,g,t, swapSum = 0, compSum = 0;
	printf("\nProcess :-\n\nOriginal : ");
		for(k=0;k<n;k++)
			printf("%s", S[k].name);
		printf("\n");
	for(i=0;i<(n-1);i++)
	{
		g=0;t=0;
		max=i;
		for(j=(i+1);j<n;j++)
		{
			g++;
			if(strcmp(S[j].name,S[max].name)>0)
				max = j;
		}
		swap(&S[i],&S[max]);
		t++;
		printf("Pass %d   : ", h);
		for(k=0;k<n;k++)
			printf("%s   ", S[k].name);
		printf(" | Swaps = %d  | Comparisons = %d\n", t-1, g);
		swapSum += t-1;
		compSum += g;
		h++;
	}

	printf("\nHence List is Sorted in %d passes.\nTotal Swaps = %d.\nTotal Comparisons = %d.\n", h-1, swapSum, compSum);
}

int binarySearchWOR(int n,int sch)
{
	int beg=0, end=n-1, mid=(beg+end)/2;

	while(beg<end)
	{
		if(S[mid].roll==sch)
			return mid;
		else if(S[mid].roll>sch)
		{
			end = mid-1;
			mid = (beg+end)/2;
		}
		else
		{
			beg = mid+1;
			mid = (beg+end)/2;
		}
	}
	return -1;
}

int binarySearchWR(int beg,int end,int sch)
{
	int mid = (beg+end)/2;
    if (beg > end)
        return -1;
	if(S[mid].roll==sch)
		return mid;
	if(S[mid].roll>sch)
		return(binarySearchWR(beg,mid-1,sch));
	else
		return(binarySearchWR(mid+1,end,sch));
}

int main()
{
	int ch,t=0,i,m,sch;

	do
		{
			printf("\nMenu :\n1. Enter Students Records.\n2. Display in ascending order of Roll. No.\n3. Display in descending order of Name.\n4. Search Data ( Without Recursion ).\n5. Search Data ( With Recursion ).\n6. Exit.\nEnter your choice : ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:	do
						{
							printf("\nEnter no. of students : ");
							scanf("%d",&t);
							if(t>=lim)
								printf("\nMaximum no. of data entry allowed is %d ...!!\n",lim);
							if(t<0)
								printf("\nEnter a VALID number...!!\n");
						}while((t>=lim)||(t<0));
						for(i=0;i<t;i++)
							acceptData(i);
						break;

				case 2:	if(t!=0)
						{
							printf("\nBUBBLE SORT : (Sort by Roll No. in Ascending Order)\n");
							bubbleSort(t);
							printf("\nDATA BASE :\n");
							tabHead();
							for(i=0;i<t;i++)
								displayData(i);
							printf("\n");
							ll
						}
						else
							printf("\nEnter Data First..!!\n");
						break;

				case 3:	if(t!=0)
						{	selectionSort(t);
							printf("\nSELECTION SORT : (Sort by Name in Descending Order)\n");
							printf("\nDATA BASE :\n");
							tabHead();
							for(i=0;i<t;i++)
								displayData(i);
							printf("\n");
							ll
						}
						else
							printf("\nEnter Data First..!!\n");
						break;

				case 4:	if(t!=0)
						{
							printf("\nBINARY SEARCH : (Search Record by Roll No.)\n");

							printf("\nEnter Roll No. to Search : ");
							scanf("%d",&sch);

							m = binarySearchWOR(t,sch);
							if(m!=-1)
							{	tabHead();
								displayData(m);
								printf("\n");
								ll
							}
							else
								printf("\nEntered Roll No. doesn't exist..!!\n");
						}
						else
							printf("\nEnter Data First..!!\n");
						break;

				case 5:	if(t!=0)
						{
							printf("\nBINARY SEARCH : (Search Record by Roll No.)\n");

							printf("\nEnter Roll No. to Search : ");
							scanf("%d",&sch);

							m = binarySearchWR(0,t-1,sch);
							printf("%d",m);
							if(m!=-1)
							{	tabHead();
								displayData(m);
								printf("\n");
								ll
							}
							else
								printf("\nEntered Roll No. doesn't exist..!!\n");
						}
						else
							printf("\nEnter Data First..!!\n");
						break;

				case 6:	break;
			}
		}while(ch!=6);

	return 0;
}


/*

Menu :
1. Enter Students Records.
2. Display in ascending order of Roll. No.
3. Display in descending order of Name.
4. Search Data ( Without Recursion ).
5. Search Data ( With Recursion ).
6. Exit.
Enter your choice : 1

Enter no. of students : 4

Student 1 :
Unique Roll No. : 1234
Name : Gaurav
Age : 23
Percentage : 23

Student 2 :
Unique Roll No. : 2345
Name : Puneet
Age : 34
Percentage : 34

Student 3 :
Unique Roll No. : 3456
Name : Ellika
Age : 45
Percentage : 45

Student 4 :
Unique Roll No. : 4567
Name : Sakshee
Age : 56
Percentage : 56

Menu :
1. Enter Students Records.
2. Display in ascending order of Roll. No.
3. Display in descending order of Name.
4. Search Data ( Without Recursion ).
5. Search Data ( With Recursion ).
6. Exit.
Enter your choice : 2

BUBBLE SORT : (Sort by Roll No. in Ascending Order)

Process :-

Original : 1234   2345   3456   4567   

Hence List is Sorted in 0 passes.
Total Swaps = 0.
Total Comparisons = 3.

DATA BASE :
-------------------------------------------------------------------------------------

Unique Roll No.		Name of Student		Age	Percentage

-------------------------------------------------------------------------------------

  1234			Gaurav			13106	23.000000
  2345			Puneet			13363	34.000000
  3456			Ellika			13620	45.000000
  4567			Sakshee			13877	56.000000
-------------------------------------------------------------------------------------

Menu :
1. Enter Students Records.
2. Display in ascending order of Roll. No.
3. Display in descending order of Name.
4. Search Data ( Without Recursion ).
5. Search Data ( With Recursion ).
6. Exit.
Enter your choice : 3

Process :-

Original : GauravPuneetEllikaSakshee
Pass 1   : Sakshee   Puneet   Ellika   Gaurav    | Swaps = 0  | Comparisons = 3
Pass 2   : Sakshee   Puneet   Ellika   Gaurav    | Swaps = 0  | Comparisons = 2
Pass 3   : Sakshee   Puneet   Gaurav   Ellika    | Swaps = 0  | Comparisons = 1

Hence List is Sorted in 3 passes.
Total Swaps = 0.
Total Comparisons = 6.

SELECTION SORT : (Sort by Name in Descending Order)

DATA BASE :
-------------------------------------------------------------------------------------

Unique Roll No.		Name of Student		Age	Percentage

-------------------------------------------------------------------------------------

  4567			Sakshee			13877	56.000000
  2345			Puneet			13363	34.000000
  1234			Gaurav			13106	23.000000
  3456			Ellika			13620	45.000000
-------------------------------------------------------------------------------------

Menu :
1. Enter Students Records.
2. Display in ascending order of Roll. No.
3. Display in descending order of Name.
4. Search Data ( Without Recursion ).
5. Search Data ( With Recursion ).
6. Exit.
Enter your choice : 5

BINARY SEARCH : (Search Record by Roll No.)

Enter Roll No. to Search : 2345
1-------------------------------------------------------------------------------------

Unique Roll No.		Name of Student		Age	Percentage

-------------------------------------------------------------------------------------

  2345			Puneet			13363	34.000000
-------------------------------------------------------------------------------------

Menu :
1. Enter Students Records.
2. Display in ascending order of Roll. No.
3. Display in descending order of Name.
4. Search Data ( Without Recursion ).
5. Search Data ( With Recursion ).
6. Exit.
Enter your choice : 4

BINARY SEARCH : (Search Record by Roll No.)

Enter Roll No. to Search : 2345
-------------------------------------------------------------------------------------

Unique Roll No.		Name of Student		Age	Percentage

-------------------------------------------------------------------------------------

  2345			Puneet			13363	34.000000
-------------------------------------------------------------------------------------

Menu :
1. Enter Students Records.
2. Display in ascending order of Roll. No.
3. Display in descending order of Name.
4. Search Data ( Without Recursion ).
5. Search Data ( With Recursion ).
6. Exit.
Enter your choice : 6

*/
