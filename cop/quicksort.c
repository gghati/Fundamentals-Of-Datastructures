/*
=====================================================================
Assignment : QUICK SORT
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Accept Mobile user information (e.g. MobileNo, Name, BillAmount etc.).
a) Display the data in descending order of Name (Quicksort, recursive)
b) Display the data in ascending order of MobileNo (Quicksort nonrecursive)
c) Display pivot position and its corresponding list in each pass.
d) Display the number of passes and comparisons for different test cases (Worst, Average, Best case).

=====================================================================
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

struct Mobile			//Structure for storing Customer Data
{
	long long int mno;
	char name[nm];
	float bill;
}M[lim];

int checkMob(int t)		//Check if Mobile No. is Unique
{
	int i;
	for(i=0;i<t;i++)
		if(M[i].mno==M[t].mno)
			return 1;
	return 0;
}

void tabHead()
{
	ll
	printf("\nSr. No.\t\tName\t\tMobile No.\tBill Amount\n\n");
	ll
}

void acceptData(int t)			//Get Data
{
    printf("\nCustomer %d :",t+1);
    printf("\n");

    while(getc(stdin)!='\n');
	do
    {
        printf("Name : ");
        scanf("%s", M[t].name);
        if(strlen(M[t].name)==0)
            printf("\nName Cannot be Empty...!!\n");
    }while(strlen(M[t].name)==0);

	do
	{
		printf("Mobile No. : ");
		scanf("%lld",&M[t].mno);
		if((M[t].mno<1000000000)||(M[t].mno>9999999999))
			printf("Enter CORRECT 10 Digit Mobile No. !!\n");
		if(checkMob(t))
			printf("\nEntered Mobile No. Already Exists..!!");
	}while(checkMob(t)||(M[t].mno<1000000000)||(M[t].mno>9999999999));      //Validation of Mobile Number

	printf("Bill Amount : ");
    scanf("%f",&M[t].bill);
}

void displayData(int j)			//Displaying Data
{
	printf("\n %5d\t\t%s\t\t%lld\t%2f",j+1,M[j].name,M[j].mno,M[j].bill);
}

void swap(struct Mobile *M1,struct Mobile *M2)
{
	struct Mobile M;
	M = *M1;
	*M1 = *M2;
	*M2 = M;
}

int partitionR(int low, int high, int s[2])
{
	int i, j;
	int comp = 0,swaps = 0;
    char pivot[nm];

    strcpy(pivot,M[high].name);
    printf("Pivot = %s",pivot);

    i = (low - 1);

    for (j = low; j < high; j++)
    {
        comp++;
        if (strcmp(pivot,M[j].name) < 0)
        {
            i++;
            if(i != j)
            {   swap(&M[i], &M[j]);
                swaps++;
            }
        }
    }
    if(i+1 != high)
    {   swap(&M[i+1], &M[high]);
        swaps++;
    }

    s[0] += comp;
    s[1] += swaps;

    return (i+1);
}

void QuickSortR(int low,int high,int c,int s[2])
{
	int i;
	if (low < high)
    {
        int p = partitionR(low, high, s);
        printf("\nPosition of Pivot = %d\n",p);
        for (i = 0; i < c; ++i)
        {
        	printf("  %s  ",M[i].name);
        }
        printf("\n");

        QuickSortR(low, p-1, c, s);
        QuickSortR(p+1, high, c, s);
    }
}

int main()
{
    int ch,t,i,temp =0, s[2];

    do
	{
		printf("\nMenu :\n1. Enter Mobile Records.\n2. Display Data.\n3. Display in descending order of Name.\n4. Exit.\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	do
					{
						printf("\nEnter no. of records : ");
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
					{
					    s[0] = 0;
                        s[1] = 0;
						printf("\nQuick SORT : (Sort by Name in Descending Order)\n");
						QuickSortR(0,t-1,t,s);

						printf("\nQuick Sort Completed..!\nTotal Number of Comparisons = %d\nTotal Number of Swaps = %d\n",s[0],s[1]);

                        for(i=1;i<t;i++)
                            temp += i;

                        if(temp == s[0])
                            printf("Test Case : Worst\n");
                        else
                            printf("Test Case : Average\n");

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

			case 4:	break;

			default:printf("\nEnter Choice Between 1 - 4 Only..!!\n");
		}
	}while(ch!=4);

    return 0;
}
