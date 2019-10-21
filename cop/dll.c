#include<stdio.h>
#include <stdlib.h>
typedef struct student
{
	int roll;
	char name[30];
	float per;
}student;

typedef struct node
{
	student data;
	struct node *next;
	struct node *prev;
}node;
node* create(node *head);
node* insert(node *head, int loc);
node* delete(node *head, int loc);
void display(node *head);
void display_back(node *head);
int main()
{
	int ch,x,y,pos;
	node *Head=NULL;
	do
	{
		printf("\n1.Create Linked List\n2.Insert (at front, at end, in the middle)\n3.Delete (at front, at end, in the middle)\n");
		printf("4.Display Linked List Forward\n5.Display Linked List Backward\n6.End\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			Head=create(Head);
			break;
		case 2:
			do
			{
				printf("\n1.Insert at Front\n2.Insert at end\n3.Insert at middle\n4.End\n");
				scanf("%d",&x);
				switch(x)
				{
				case 1:
					Head=insert(Head,0);
					break;
				case 2:
					Head=insert(Head,100);
					break;
				case 3:
					printf("\nEnter position to insert node at\n");
					scanf("%d",&pos);
					Head=insert(Head,pos);
					break;
				case 4:
					break;
				default:
					printf("\nWrong value entered\n");
				}
			}while(x!=4);
			break;
		case 3:
			do
			{
				printf("\n1.Delete from Front\n2.Delete from end\n3.Delete from middle\n4.End\n");
				scanf("%d",&y);
				switch(y)
				{
				case 1:
					Head=delete(Head,1);
					break;
				case 2:
					Head=delete(Head,100);
					break;
				case 3:
					printf("\nEnter position to delete node from\n");
					scanf("%d",&pos);
					Head=delete(Head,pos);
					break;
				case 4:
					break;
				default:
					printf("\nWrong value entered\n");
				}
			}while(y!=4);
			break;
		case 4:
		{
			display(Head);
			break;
		}
		case 5:
			display_back(Head);
			break;
		case 6:
			printf("\nExit Successful\n");
			break;
		}
	}while(ch!=6);
}

node* create(node *head)
{
	int n,i,x;
	node *p=NULL;
	head=NULL;
	head=(node*)malloc(sizeof(node));
	printf("\nEnter no of Records to create\n");
	scanf("%d",&n);
	printf("\nEnter Roll Number %d\n",1);
	scanf("%d",&head->data.roll);
	printf("\nEnter Name\n");
	scanf("%s",head->data.name);
	printf("\nEnter Percent\n");
	scanf("%f",&head->data.per);
	head->next=NULL;
	head->prev=NULL;
	p=head;
	for(i=1;i<n;i++)
	{
		p->next=(node*)malloc(sizeof(node));
		printf("\nEnter Roll Number of %d\n",i);
		scanf("%d",&p->next->data.roll);
		printf("\nEnter Name\n");
		scanf("%s",p->next->data.name);
		printf("\nEnter Percent\n");
		scanf("%f",&p->next->data.per);
		p->next->prev=p;
		p=p->next;
	}
	p->next=NULL;
	return head;
}

node* insert(node *head, int loc)
{
	int i=0;
	node *p=NULL;
	node *q=NULL;
	node *count=NULL;
	count=head;
	while(count->next!=NULL)
	{
		i++;
		count=count->next;
	}
	printf("%d",i);
	if(loc==100)
		loc=i;
	if(loc==0 && head!=NULL)
	{
		p=(node*)malloc(sizeof(node));
		printf("\nEnter data to insert\n");
		printf("\nEnter Roll Number %d\n",1);
		scanf("%d",&p->data.roll);
		printf("\nEnter Name\n");
		scanf("%s",p->data.name);
		printf("\nEnter Percent\n");
		scanf("%f",&p->data.per);
		p->next=head;
		head->prev=p;
		head=p;
		head->prev=NULL;
		return head;
	}
	if(head==NULL)
	{
		printf("\nLinked List does not exist\n");
		return head;
	}
	else
	{
		p=head;
		for(i=0;i<loc&&p!=NULL;i++)
		{
			p=p->next;
		}
		if(p!=NULL)
		{
			q=(node*)malloc(sizeof(node));
			printf("\nEnter data to insert\n");
			printf("\nEnter Roll Number %d\n",1);
			scanf("%d",&q->data.roll);
			printf("\nEnter Name\n");
			scanf("%s",q->data.name);
			printf("\nEnter Percent\n");
			scanf("%f",&q->data.per);
			q->next=p->next;
			if(p->next!=NULL)
				(p->next)->prev=q;
			q->prev=p;
			p->next=q;
			return head;
		}
		else
		{
			printf("\nWrong position entered\n");
			return head;
		}
	}
}

void display(node *head)
{
	printf("\nRoll No\tName\tPercent\n");
	while(head!=NULL)
	{
		printf("\n%d\t%s\t%f\n",head->data.roll,head->data.name,head->data.per);
		head=head->next;
	}
	if(head==NULL)
		printf("\nLinked List Empty\n");
	//printf("NULL");
}

void display_back(node *head)
{
	printf("\nRoll No\tName\tPercent\n");
	if(head!=NULL)
	{
		while(head->next!=NULL)
			head=head->next;
			while(head!=NULL){
				printf("\n%d\t%s\t%f\n",head->data.roll,head->data.name,head->data.per);
				head=head->prev;
			}
	}
	else
		printf("\nLinked List Empty\n");
		//printf("NULL");
}

node* delete(node *head, int loc)
{
	int i=0;
	node *p;
	node *q;
	node *count;
	count=head;
	while(count!=NULL)
	{
		i++;
		count=count->next;
	}
	printf("%d",i);
	if(loc==100)
		loc=i;
	p=head;
	if(head==NULL)
	{
		printf("\nLinked List does not exist\n");
		return head;
	}
	p=head;
	if(loc==1)
	{
		p=head;
		head=head->next;
		if(head!=NULL)
			head->prev=NULL;
		free(p);
		return head;
	}
	for(i=0;i<loc-1&&p!=NULL;i++)
	{
		q=p;
		p=p->next;
	}
		if(p!=NULL)
		{
			q->next=p->next;
			p->prev=q;
			free(p);
		}
		else
			printf("\nWrong Position Entered\n");
		return head;

}

