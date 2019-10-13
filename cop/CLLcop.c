/*
 ============================================================================
 Name        : CircularLL.c
 Author      : Omkar S. Dabir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct circular {
	int coef;
	int exp;
	struct circular *next;
};

typedef struct circular node;

node* insert(node *head, int coef, int exp);
node* getNode(node *nev);
void displayPoly(node *head);
node* getPoly(node *head, int x, int *num);
int menu();
void evalPoly(node *head);

node* addPoly(node *head1, node *head2, node *head3);
node* multPoly(node *head1, node *head2, node *head3);

///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

	node *head1 = NULL;
	node *head2 = NULL, *head3 = NULL;
	int choice, choice2, num1, num2, num3;

	do {
		choice = menu();

		switch (choice) {
		case 1:
			head1 = head2 = NULL;
			head1 = getPoly(head1, 1, &num1);
			head2 = getPoly(head2, 2, &num2);

			break;
		case 2:

			printf("\n\n************************************************");
			if (head1 == NULL) {
				printf("\n\nPOLYNOMIAL 1: 0");
			} else {
				printf("\n\nPOLYNOMIAL 1: ");

				displayPoly(head1);
			}
			if (head2 == NULL) {
				printf("\n\nPOLYNOMIAL 2: 0");
			} else {
				printf("\n\nPOLYNOMIAL 2: ");

				displayPoly(head2);
			}
			break;
		case 3:
			if (head1 == NULL && head2 == NULL) {
							printf("\n\n************************************************");
							printf("\n\nADDITION: 0");
			}else if (head1 == NULL) {
				printf("\n\n************************************************");
				printf("\n\nADDITION: ");
				displayPoly(head2);
			} else if (head2 == NULL) {
				printf("\n\n************************************************");
				printf("\n\nADDITION: ");
				displayPoly(head1);
			}else {
				head3 = NULL;
				head3 = addPoly(head1, head2, head3);
				printf("\n\n************************************************");
				printf("\n\nADDITION: ");
				displayPoly(head3);
			}
			break;
		case 4:
			if (head1 == NULL || head2 == NULL) {
				printf("\n\n************************************************");
				printf("\n\nPRODUCT: 0");
			} else {
				head3 = NULL;

				head3 = multPoly(head1, head2, head3);
				printf("\n\n************************************************");
				printf("\n\nPRODUCT: ");
				displayPoly(head3);
			}

			break;
		case 5:

			printf("\n\n************************************************");

			if (head1 == NULL) {
				printf("\n\n1] Evaluate Polynomial 1: 0");

			} else {
				printf("\n\n1] Evaluate Polynomial 1:");

				displayPoly(head1);
			}
			if (head2 == NULL) {
				printf("\n\n2] Evaluate Polynomial 2: 0");

			} else {
				printf("\n2] Evaluate Polynomial 2:");
				displayPoly(head2);
			}
			printf("\n\n***Enter your choice: ");
			scanf("%d", &choice2);

			switch (choice2) {
			case 1:

				evalPoly(head1);
				break;
			case 2:
				evalPoly(head2);
				break;

			}

			break;
		case 6:
			printf("\n\n****TERMINATING PROGRAM!!!");
			return 0;

		}
	} while (1);

	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

int menu() {
	int choice;
	printf("\n\n*********MENU FOR POLYNOOMIAL OPERATIONS*************\n\n");
	printf(
			"1.Enter Polynomials\n2.Display Polynomials\n3.Addition\n4.Multiplication\n5.Evaluation\n6.Exit\n\n");
	printf("Enter your choice: ");

	scanf("%d", &choice);

	return choice;

}

node* getNode(node *nev) {

	nev = (node*) malloc(sizeof(node));
	nev->next = NULL;

	return nev;
}

node* insert(node *head, int coef1, int exp1) {
	node *p = NULL, *temp;

	p = getNode(p);
	p->coef = coef1;
	p->exp = exp1;

	if (head == NULL) //create the list
	{
		head = p;
		head->next = head;
		return head;
	}

	if (exp1 > (head->exp)) //insert at position 1
			{
		p->next = head;
		temp = head;

		while (temp->next != head)
			temp = temp->next;
		temp->next = p;
		head = p;

		return head;

	}

	temp = head;

	while (temp->next != head && exp1 <= temp->next->exp) //until exponent is equal or smaller
	{
		temp = temp->next;
	}

	if (p->exp == temp->exp) //when exponent is same
			{
		temp->coef = temp->coef + p->coef;
		free(p);
		return head;
	}

	else {
		p->next = temp->next;
		temp->next = p;
	}

	return head;
}

void displayPoly(node *head) {
	node *temp;

	if (head->coef < 0)
		printf(" %d", head->coef);
	else if (head->coef == 1) {
		printf(" ");
	} else {
		printf(" %d", head->coef);
	}

	if (head->exp == 0)
		printf(" ");
	else if (head->exp == 1)
		printf("X ");
	else {
		printf("X^(%d) ", head->exp);
	}

	if (head->next->coef > 0 && head->next != head)
		printf("+");
	else if (head->next != head)
		printf("-");

	temp = head->next;

	while (temp->next != head) {
		if (temp->coef < 0)
			printf(" %d", -1 * temp->coef);
		else if (temp->coef == 1 && temp->exp != 0) {
			printf(" ");
		} else {
			printf(" %d", temp->coef);
		}

		if (temp->exp == 0)
			printf(" ");
		else if (temp->exp == 1)
			printf("X ");
		else {
			printf("X^(%d) ", temp->exp);
		}

		if (temp->next->coef > 0 && temp->next != head)
			printf("+");
		else if (temp->next != head)
			printf("-");

		temp = temp->next;
	}

	if (temp != head) {
		if (temp->coef < 0)
			printf(" %d", -1 * temp->coef);
		else if (temp->coef == 1 && temp->exp != 0) {
			printf(" ");
		} else {
			printf(" %d", temp->coef);
		}

		if (temp->exp == 0)
			printf(" ");
		else if (temp->exp == 1)
			printf("X ");
		else {
			printf("X^(%d) ", temp->exp);
		}
	}

}

node* getPoly(node *head, int x, int *num) {
	int coeff, expo;
	printf(
			"\n\n*************************************************************\n");

	printf("\nHow many non-zero terms are there in polynomial %d ?: ", x);
	scanf("%d", num);

	while (num <= 0) {
		printf("***Invalid Input!PLEASE TRY AGAIN!...");
		scanf("%d", num);
	}

	for (int i = 0; i < *num; i++) {
		printf("\nTerm %d: \n", i + 1);
		printf("Enter the Coefficient: ");
		scanf("%d", &coeff);

		while (coeff == 0) {
			printf("***Please Enter only non-zero terms!!!...");
			printf("\nEnter the Coefficient again: ");
			scanf("%d", &coeff);
		}

		printf("Enter the Exponent: ");
		scanf("%d", &expo);

		while (expo < 0) {
			printf("***Exponent cannot be negative!PLEASE TRY AGAIN!...");
			printf("\nEnter the Exponent again: ");
			scanf("%d", &expo);
		}

		head = insert(head, coeff, expo);
	}

	return head;
}

node* addPoly(node *head1, node *head2, node *head3) {
	node *temp1, *temp2;

	temp1 = head1;
	temp2 = head2;

	head3 = insert(head3, temp1->coef, temp1->exp);
	temp1 = head1->next;
	while (temp1 != head1) {
		head3 = insert(head3, temp1->coef, temp1->exp);
		temp1 = temp1->next;
	}
	head3 = insert(head3, temp2->coef, temp2->exp);
	temp2 = head2->next;

	while (temp2 != head2) {
		head3 = insert(head3, temp2->coef, temp2->exp);
		temp2 = temp2->next;
	}

	return head3;
}

void evalPoly(node *head) {
	node *temp;
	int ans = 0, x;
	temp = head;

	if (head == NULL) {
		printf("\n*****THE ANSWER IS: 0");
	} else {

		printf("\n*****Enter the value of X: ");
		scanf("%d", &x);

		ans = (temp->coef) * pow(x, temp->exp);

		while (temp->next != head) {
			ans += temp->next->coef * pow(x, temp->next->exp);
			temp = temp->next;
		}

		printf("\n*****THE ANSWER IS: %d", ans);
	}

}

node* multPoly(node *head1, node *head2, node *head3) {
	node *temp1, *temp2;

	int c,e;

	temp1 = head1;

	head3=NULL;

	do{
		temp2 = head2;

		do{

			c=temp1->coef*temp2->coef;
			e=temp1->exp+temp2->exp;
			head3=insert(head3, c, e);

			temp2=temp2->next;

			}while(temp2!=head2);
		temp1=temp1->next;

	}while(temp1!=head1);


	return head3;

}

