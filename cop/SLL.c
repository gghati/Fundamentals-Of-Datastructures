/*
=====================================================================
Assignment : Singly linked list
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement : 
Create a singly linked list with options:
	a) Insert (at front, at end, in the middle),
	b) Delete (at front, at end, in the middle),
	c) Display,
	d) Display Reverse,
	e) Revert the SLL
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lim 50

typedef struct{
	int data;
	struct Node *next;
}Node;

Node* create(int t){							// DONE
	Node *p, *hd = NULL;
	int i,val;
	printf("\nEnter %d Values one by one.\n",t);
	p = (Node*)malloc(sizeof(Node));
	scanf("%d", &val);
	p->data = val;
	p->next = NULL;
	
	hd = p;
	
	for(i=0;i<t-1;i++){
		p->next = (Node*)malloc(sizeof(Node));
		p = p->next;
		scanf("%d", &val);
		p->data = val;
		p->next = NULL;
	}
	return hd;
}

Node* insertNode(Node *head1, int t){					// DONE
	Node *temp, *head;
	int cnt = 1, pos = 0, val;

	head = head1;

	temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;

	printf("\nEnter value to insert : ");
	scanf("%d", &val);
	temp->data = val;

	printf("\nPositions start from 1 to %d. Type 0 to insert at the end.", t);

	do{
		if(pos<0 || pos>t){
			printf("\nEnter CORRECT Value..!!");
		}

		printf("\nEnter position where you wish to insert the value : ");
		scanf("%d", &pos);

		if(pos == 0){
			while(head->next!=NULL){
				head = head->next;
			}
			head->next = temp;
		}
		else if(pos == 1){
			temp->next = head;
			head1 = temp;
		}
		else{
			while(cnt != pos-1 && pos <= t){
				head = head->next;
				cnt++;
			}
			temp->next = head->next;
			head->next = temp;
		}
	}while(pos<0 || pos>t);

	return head1;
}

void display(Node *h, int t){
	Node *temp = h;
	while(temp != NULL){
		printf("(%d | %d) ->  ",temp->data, &temp->next);
		temp = temp->next;
	}
}

Node* deleteNode(Node *head1, int t){
	Node *head, *p;
	int pos = 1, cnt = 1;

	head = head1;

	printf("\nPositions start from 1 to %d.", t);

	do{
		if(pos<1 || pos>t){
			printf("\nEnter CORRECT Value..!!");
		}

		printf("\nEnter position of element you wish to delete : ");
		scanf("%d", &pos);

		if(pos == 1){
			head1 = head1->next;
			free(head);
		}
		else{
			while(cnt != pos-1){
				head = head->next;
				cnt++;
			}
			p = head->next;
			head->next = p->next;
			free(p);
		}
	}while(pos<1 || pos>t);

	return head1;
}

void reverseDisplay(Node *h, int t){
	int i, n = 0, a[20];
	Node *temp = h;
	while(temp != NULL){
		a[n] = temp->data;
		temp = temp->next;
		n++;
	}
	for(i = n-1; i>=0; i--)
		printf(" %d -> ", a[i]);
}

Node* revertNode(Node *head1, int t){
	Node *prev = NULL, *current = head1, *next;

	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

int main(){
	int ch,t=0;
	Node *head = NULL;

	do{
		printf("\nMenu :\n1. Create.\n2. Insert.\n3. Display.\n4. Delete.\n5. Display Reverse.\n6. Revert the SSL.\n7. Exit.\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	do{
					printf("\nEnter no. of number of nodes you want to create : ");
					scanf("%d",&t);

					if(t>=lim)
						printf("\nMaximum no. of value entries allowed is %d ...!!\n",lim);
					if(t<0)
						printf("\nEnter a VALID number...!!\n");
				}while((t>=lim)||(t<0));
				head = create(t);
				break;

			case 2:	if(t!=0){
						head = insertNode(head,t);
						printf("Node INSERTED Successfully..!!\n");
						t += 1;
					}
					else
						printf("\nCreate List First..!!\n");
					break;

			case 3:	if(t!=0)
					{
						printf("\n");
						display(head,t);
						printf("\n");
					}
					else
						printf("\nCreate List First..!!\n");
					break;

			case 4:	if(t!=0)
					{
						head = deleteNode(head,t);
						printf("Node DELETED Successfully..!!\n");
						t -= 1;
					}
					else
						printf("\nCreate List First..!!\n");
					break;

			case 5:	if(t!=0)
					{
						printf("\n");
						reverseDisplay(head,t);
						printf("\n");
					}
					else
						printf("\nCreate List First..!!\n");
					break;

			case 6:	if(t!=0)
					{
						head = revertNode(head,t);
						printf("List REVERTED Successfully..!!\n");
					}
					else
						printf("\nCreate List First..!!\n");
					break;

			case 7:	break;

			default:printf("\nEnter Choice Between 1 - 6 Only..!!\n");
		}
	}while(ch!=7);

	return 0;
}

/*

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 1

Enter no. of values : 6

Enter 6 Values one by one.
12 23 34 45 56 67

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 3

 12   23   34   45   56   67  

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 4

Positions start from 1 to 6.
Enter position of element you wish to delete : 3
Node DELETED Successfully..!!

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 3

 12   23   45   56   67  

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 5

 67   56   45   23   12  

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 2

Enter value to insert : 34

Positions start from 1 to 5. Type 0 to insert at the end.
Enter position where you wish to insert the value : 0
Node INSERTED Successfully..!!

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 3   

 12   23   45   56   67   34  

Menu :
1. Create.
2. Insert.
3. Display.
4. Delete.
5. Display Reverse.
6. Revert the SSL.
7. Exit.
Enter your choice : 7


*/
