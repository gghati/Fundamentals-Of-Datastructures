/*
 ============================================================================
 Name        : CLL.c
 Author      : Murtuza Husain
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
	int pow;
	int coeff;
	struct node *next;
}node;

node* create(node *head);
void display(node *head);
node* add(node *head1, node *head2, node *result);
node* multiply(node *head1, node *head2, node *result);
float eval(node *head);

node* create(node *head)
{
	int pow;
	int coeff;
	int i,n;
	node *p=NULL;
	head=NULL;
	head=(node*)malloc(sizeof(node));
	printf("\nEnter no of terms to insert\n");
	scanf("%d",&n);
	printf("\nEnter power for node %d\n",1);
	scanf("%d",&pow);
	printf("\nEnter coefficient for node %d\n",1);
	scanf("%d",&coeff);
	head->coeff=coeff;
	head->pow=pow;
	head->next=head;
	p=head;
	for(i=1;i<n;i++)
	{
		p->next=(node*)malloc(sizeof(node));
		printf("\nEnter power for node %d\n",1);
		scanf("%d",&pow);
		printf("\nEnter coefficient for node %d\n",1);
		scanf("%d",&coeff);
		p->next->coeff=coeff;
		p->next->pow=pow;
		p=p->next;
	}
	p->next=head;
	return head;

}

void display(node *head)
{
	node*p=NULL;
	p=head;
	do
	{
		printf("%dx^%d",p->coeff,p->pow);
		p=p->next;
		printf("+");
	}while(p!=head);
}

node* add(node *head1, node *head2, node *result)
{
	int x=0,y=0;
	node *poly1,*poly2,*poly3=NULL;
	poly1=head1;
	poly2=head2;
	result=(node*)malloc(sizeof(node));
	result->next=result;
	poly3=result;
	printf("\n");
	if(poly1->next!=poly1&&poly2->next!=poly2)
	{
		do
		{
			if(poly1->pow==poly2->pow)
			{
				poly3->pow=poly1->pow;
				poly3->coeff=poly1->coeff+poly2->coeff;
				poly1=poly1->next;
				poly2=poly2->next;
				x++;
				y++;
			}
			else if(poly1->pow>poly2->pow)
			{
				poly3->pow=poly1->pow;
				poly3->coeff=poly1->coeff;
				poly1=poly1->next;
				x++;
			}
			else if(poly1->pow<poly2->pow)
			{
				poly3->pow=poly2->pow;
				poly3->coeff=poly2->coeff;
				poly2=poly2->next;
				y++;
			}
			poly3->next=(node*)malloc(sizeof(node));
			poly3=poly3->next;
			poly3->next=NULL;
		}while((poly1!=head1&&poly2!=head2)||(x==1||y==1));
		while(poly1!=head1||poly2!=head2)
		{
			if(poly1!=head1)
			{
				poly3->pow=poly1->pow;
				poly3->coeff=poly1->coeff;
				poly1=poly1->next;
			}
			if(poly2!=head2)
			{
				poly3->pow=poly2->pow;
				poly3->coeff=poly2->coeff;
				poly2=poly2->next;
			}
			if(poly1!=head1||poly2!=head2)
			{
				poly3->next=(node*)malloc(sizeof(node));
				poly3=poly3->next;
				poly3->next=NULL;
			}
		}
	}
	else
	{
		do
		{
			if(poly1->pow==poly2->pow)
			{
				poly3->pow=poly1->pow;
				poly3->coeff=poly1->coeff+poly2->coeff;
				poly1=poly1->next;
				poly2=poly2->next;
			}
			else if(poly1->pow>poly2->pow)
			{
				poly3->pow=poly1->pow;
				poly3->coeff=poly1->coeff;
				poly1=poly1->next;
				x++;
			}
			else if(poly1->pow<poly2->pow)
			{
				poly3->pow=poly2->pow;
				poly3->coeff=poly2->coeff;
				poly2=poly2->next;
				y++;
			}
			poly3->next=(node*)malloc(sizeof(node));
			poly3=poly3->next;
			poly3->next=NULL;
			x++;
			y++;
		}while((poly1!=head1||poly2!=head2));
		while(poly1!=head1||poly2!=head2&&(x==1||y==1))
		{
			if(poly1!=head1||x==1)
			{
				poly3->pow=poly1->pow;
				poly3->coeff=poly1->coeff;
				poly1=poly1->next;
			}
			if(poly2!=head2||y==1)
			{
				poly3->pow=poly2->pow;
				poly3->coeff=poly2->coeff;
				poly2=poly2->next;
			}
			if(poly1!=head1||poly2!=head2)
			{
				poly3->next=(node*)malloc(sizeof(node));
				poly3=poly3->next;
				poly3->next=NULL;
			}
		}
	}
		
	
	poly3->next=result;
	poly3=result;
	return poly3;
}

node* multiply(node *head1, node *head2, node *result)
{
	node *poly1,*poly2,*poly3=NULL;
	poly1=head1;
	poly2=head2;
	result=(node*)malloc(sizeof(node));
	result->next=NULL;
	poly3=result;
	do
	{
		do
		{
			poly3->coeff=poly1->coeff*poly2->coeff;
			poly3->pow = poly1->pow+ poly2->pow;
			poly1=poly1->next;
			poly3->next=(node*)malloc(sizeof(node));
			poly3=poly3->next;
			poly3->next=NULL;
		}while(poly1!=head1);
		poly2=poly2->next;
	}while(poly2!=head2);
	poly3->next=result;
	poly3=result;
	return poly3;
}

float eval(node *head)
{
	double x;
	double y;
	float sum=0;
	printf("\nEnter value of x\n");
	scanf("%lf",&x);
	node *p;
	p=head;
	do
	{
		y=pow(x,p->pow);
		sum=sum+((p->coeff)*(y));
		p=p->next;
	}while(p!=head);	
	return sum;
}
	
	

int main()
{
	int ch,x,y,pos;
	node *Head1=NULL;
	node *Head2=NULL;
	node *result=NULL;
	float sum1,sum2;
	do
	{
		printf("\n1.Insert Polynomial 1\n2.Insert Polynomial 2\n3.Display Polynomials\n4.Addition of Polynomials\n");
		printf("5.Multiplication\n6.Evaluation\n7.End\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			Head1=create(Head1);
			break;
		case 2:
			Head2=create(Head2);
			break;
		case 3:
			printf("\nPolynomial 1:\n");
			display(Head1);
			printf("\nPolynomial 2:\n");
			display(Head2);
			break;
		case 4:
			printf("\nAddition of Polynomials is:\n");
			result=add(Head1,Head2,result);
			display(result);
			break;
		case 5:
			printf("\nMultiplication of Polynomials is:\n");
			result=multiply(Head1,Head2,result);
			display(result);
			break;
		case 6:
			printf("\nEvavluation of Polynomial\n");
			printf("\nPolynomial1:\n");
			sum1=eval(Head1);
			printf("\nPolynomial2:\n");
			sum2=eval(Head2);
			printf("\nPolynomial 1=%f\nPolynomial 2=%f",sum1,sum2);
			break;
		case 7:
			printf("\nEXIT SUCCESSFULL\n");
			break;
		}
	}while(ch!=7);
}
