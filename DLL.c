/*
=====================================================================
Assignment : Doubly linked list
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Implement any database using doubly linked list with following options:
	a) Insert a record
	b) Delete a record
	c) Modify a record
	d) Display a record
	e) Display list backward
=====================================================================
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

Node* create(){													// DONE
	Node *p = NULL, *hp = NULL;
	int num, val;
	printf("\nEnter the Number of element in the list :");
	scanf("%d", &num);
	hp = (Node*) malloc(sizeof(Node));
	printf("Enter the value: ");
	scanf("%d", &val);
	hp->data = val;	
	hp->next = NULL;
	hp->prev = NULL;
	
	p = hp;
	num -= 1;
	while(num--){
		p->next = (Node*) malloc(sizeof(Node));
		printf("\nEnter the value: ");
		scanf("%d", &val);
		(p->next)->data = val;
		(p->next)->prev = p;
		p = p->next;
	}
	p -> next = NULL;
	return hp;	
}

void disback(Node* p){												// DONE
	Node* hp = p;
	printf("\nPrinting backward : \n");
	while(hp->next != NULL){
		hp = hp->next;
	}
	while(hp != NULL){
		printf("(%d) <-> ", hp -> data);
		hp = hp -> prev;
	}
	printf("\n");
}

void disfor(Node* p){														// DONE
	Node* hp = p;
	while(hp != NULL){
		printf("(%d) <-> ", hp -> data);
		hp = hp->next;
	}
	printf("\n");
}

Node* insert(Node* head){											// DONE
	int val, t;
	printf("\nEnter the position you want to enter: ");
	scanf("%d", &t);
	printf("\nEnter the value: ");
	scanf("%d", &val);
	Node* temp = (Node*) malloc(sizeof(Node));
	temp->data = val;
	Node* head1 = head;
	if(t==1){
		temp -> next = head1;
		head1->prev = temp;
		head = temp; 
	} else {
		t = t-2;
		while(t--){
			head1 = head1->next;
		}
		temp->next = head1->next;
		temp->prev = head1;
		head1 -> next = temp;
		(head1->next)->prev = temp;
	}
	return head;
}

Node* delete(Node* head){												// DONE
	int t;
	printf("Enter the Position which you want to delete : ");
	scanf("%d", &t);
	Node* head1 = head;
	
	if(t==1){
		head = head->next;
		head->prev = NULL;
		free(head1);
	} else {
		t = t-2;
		while(t--){
			head1 = head1 -> next;	
		}
		Node* temp = head1 -> next;
		head1 -> next = temp -> next;
		(temp->next)->prev = head1;
		free(temp);
	}
	return head;
}

int main(){
	
	// Add menu driven program by yourself.
	// Add Databases in Node by yourself.
	
	Node* p = create();
	disfor(p);
	disback(p);
	
    p = insert(p);
	disfor(p);
	p = delete(p);
	disfor(p);
	disback(p);
	
	return 0;
}


