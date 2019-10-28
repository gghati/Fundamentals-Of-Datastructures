/*
=====================================================================
Assignment : FILE operations
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Implement sequential file and perform following operations on any database:
	i. Display
	ii. Add records
	iii. Search record
	iv. Modify record
	v. Delete record
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define ll line(55);

void line(int n)		//For horizontal line of table
{
	int i;
	for(i=0;i<n;i++)
		printf("-");
	printf("\n");
}

void tabHead()          //For Table Tittles or Headings
{
	ll
	printf("\nRoll No.\tName\t\tAge\tPercentage\n");
	printf("\n");
	ll
}

int checkRoll(int r)        //Checking Roll No. for its Uniqueness
{
    FILE *fp;
    char name[50];
    int age, roll;
    float percent;

    fp = fopen("F1.txt","r");
    while(fscanf(fp, "%d %s %d %f", &roll, name, &age, &percent)==4){
        if(r==roll)
            return 1;
    }
    fclose(fp);
    return 0;
}

void display()          //Display Record
{
    FILE *fp;
    char name[50];
    int age, roll;
    float percent;

    fp = fopen("F1.txt","r");
    while(fscanf(fp, "%d %s %d %f", &roll, name, &age, &percent)==4){
        printf("%8d\t%s\t\t%d\t%f\n", roll, name, age, percent);
    }
    fclose(fp);
}

void addData()             //Add a Record
{
    FILE *fp;
    char name[50];
    int age, roll;
    float percent;

    fp = fopen("F1.txt","a");

    printf("\nNEW RECORD :\n");
    do
    {
        printf("\nRoll No.: ");
        scanf("%d", &roll);
        if(checkRoll(roll))
            printf("\nEntered Roll No. ALREADY Exists..!!\n");
    }while(checkRoll(roll));
    printf("Name    : ");
    scanf("%s", name);
    printf("Age     : ");
    scanf("%d", &age);
    do
    {
        printf("Percentage : ");
        scanf("%f", &percent);
        if(percent<0 || percent>100)
            printf("\nEnter Correct Percentage..!!\n");
    }while(percent<0 || percent>100);
    fprintf(fp, "%d %s %d %f\n", roll, name, age, percent);

    printf("\nRecord Added Successfully..!!\n");

    fclose(fp);
}

void searchData()           //Search Function
{
    FILE *fp;
    char name[50];
    int age, roll;
    float percent;
    int sch,t=0,k;

    printf("\nEnter Roll No. to search : ");
    scanf("%d",&sch);

    printf("\nSEARCH RESULTS :\n");

    tabHead();

    fp = fopen("F1.txt","r");
    while(1){
        k=fscanf(fp, "%d %s %d %f", &roll, name, &age, &percent);
        if(k==4)
        {
            if(sch==roll)
            {
                printf("%8d\t%s\t\t%d\t%f\n", roll, name, age, percent);
                t++;
            }
        }
        else
            break;
    }
    ll
    if(t==0)
        printf("\nEntered Roll no. doesn't exist..!!\n");
    fclose(fp);
}

void modifyData()           //Modify or Edit Record
{
    FILE *fp, *fnew;
    char name[50];
    int age, roll;
    float percent;
    int sch, t=0, k, ch1;

    printf("\nEnter Roll No. to modify : ");
    scanf("%d",&sch);

    tabHead();

    fp = fopen("F1.txt","r");
    fnew = fopen("F2.txt","w");

    while(1){
        k=fscanf(fp, "%d %s %d %f", &roll, name, &age, &percent);
        if(k==4)
        {
            if(sch==roll)
            {
                printf("%8d\t%s\t\t%d\t%f\n", roll, name, age, percent);
                ll
                do{
                    printf("\nWhat do you want to modify ?\n  1.Name\n  2.Age\n  3.Percentage\n  4.Done with Modification\nEnter your choice : ");
                    scanf("%d", &ch1);

                    switch(ch1)
                    {
                        case 1:
                            printf("\nEnter new name : ");
                            scanf("%s", name);
                            break;

                        case 2:
                            printf("\nEnter new age : ");
                            scanf("%d", &age);
                            break;

                        case 3:
                            do
                            {
                                printf("\nEnter new percentage : ");
                                scanf("%f", &percent);
                                if(percent<0 || percent>100)
                                    printf("\nEnter Correct Percentage..!!\n");
                            }while(percent<0 || percent>100);
                            break;

                        case 4:
                            break;

                        default:
                            printf("\nEnter Valid Choice (1-4 only)..!!\n");
                    }
                }while(ch1!=4);

                fprintf(fnew, "%d %s %d %f\n", roll, name, age, percent);

                printf("\nRecord Modified Successfully..!!\n");

                t++;
            }
            else{
                fprintf(fnew, "%d %s %d %f\n", roll, name, age, percent);
            }
        }
        else
            break;
    }
    if(t==0)
        printf("\nEntered Roll no. doesn't exist..!!\n");
    fclose(fp);
    fclose(fnew);
    remove("F1.txt");
    rename("F2.txt","F1.txt");
}

void deleteData()           //Delete Function to delete a Record
{
    FILE *fp, *fnew;
    char name[50];
    int age, roll;
    float percent;
    int sch,t=0,k;

    printf("\nEnter Roll No. to delete : ");
    scanf("%d",&sch);

    tabHead();

    fp = fopen("F1.txt","r");
    fnew = fopen("F2.txt", "w");
    while(1){
        k=fscanf(fp, "%d %s %d %f", &roll, name, &age, &percent);
        if(k==4)
        {
            if(sch==roll)
            {
                printf("%8d\t%s\t\t%d\t%f\n", roll, name, age, percent);
                t++;
                continue;
            }
            fprintf(fnew, "%d %s %d %f\n", roll, name, age, percent);
        }
        else
            break;
    }
    ll
    if(t!=0)
        printf("\nAbove Record Deleted Successfully..!!\n");
    if(t==0)
        printf("\nEntered Roll no. doesn't exist..!!\n");
    fclose(fp);
    fclose(fnew);
    remove("F1.txt");
    rename("F2.txt","F1.txt");
}

int main()
{
    int ch;

    do{
        printf("\nMenu :\n1.Display\n2.Add Record\n3.Search Record\n4.Modify Record\n5.Delete Record\n6.Exit\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                tabHead();
                display();
                ll
                break;

            case 2:
                addData();
                break;

            case 3:
                searchData();
                break;

            case 4:
                modifyData();
                break;

            case 5:
                deleteData();
                break;

            case 6:
                break;

            default:
                printf("\nEnter Valid Choice (1-6 only)..!!\n");
        }
    }while(ch!=6);

    return 0;
}

