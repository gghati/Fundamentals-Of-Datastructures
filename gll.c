/*
============================================================================
Assignment : Generalized linked list
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
	Implement Generalized Linked List to create and display the book index.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 4
//node structure
typedef struct Node
{
	struct Node *next;
	int flag;
	union
	{
		char data[MAX];
		struct Node *dlink;
	}u;
}Node;

Node* getnode()
{
	Node* new1 =
	(Node*)malloc(sizeof(Node));
	new1->next = NULL;
	new1->u.dlink = NULL;
	return new1;
}

Node* Create_GLL(Node* head, char str[])
{
	int i,j;
	Node *temp;
	for(i=0;str[i]!=NULL;)
	{
		if(str[i]=='('&&i==0)
		{
			head=getnode();
			temp=head;
		}
		else
		{
			temp->next=getnode();
			temp=temp->next;
		}
		i++;
		j=0;
		while(str[i]!=','&&str[i]!='('&&str[i]!=')')
		{
			temp->u.data[j]=str[i];
			i++;
			j++;
		}
		temp->u.data[j] = NULL;
		temp->flag = 0;
		if(str[i] == '(')
		{
			temp->next = getnode();
			temp = temp->next;
			temp->flag = 1;
			temp->u.dlink =
			Create_GLL(NULL, &str[i]);
		}
		while(str[i] != ')')
			i++;
		i++;
		if(str[i] == ')')
			return head;
	} 
} 

void Display(Node* temp)
{
	static int depth;
	depth++;
	int i;
	if(temp == NULL)
	{
		if(depth == 1)
			printf("List is Empty");
		else
			printf("Sublist is Empty");
	}
	else
		while(temp != NULL)
		{
			if(temp->flag == 0)
			{
			printf("\n");
			for(i = 1; i <= depth; i++)
				printf(" ");
			printf("%s)", temp->u.data);
			}
			else
				Display(temp->u.dlink);
			temp = temp->next;
		}
	depth--;
}
int main()
{
	Node* head = NULL;
	char str[51], repeat = 'n';
	do
	{
	printf("\nEnter the book index string to be converted to GLL:");
	scanf("\n");
	gets(str);
	printf("The book index is: ");
	head = Create_GLL(head, str);
	Display(head);
	printf("\nDo you want to try again (y/n): ");
	scanf(" %c", &repeat);
	}while(repeat == 'y');
	return 0;
}
/*

NOT IMPLEMENTED CORRECTLY

*/
