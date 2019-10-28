/*
=====================================================================
Assignment : Singly linked list
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Implement Singly Linked List to create and display the book index.

=====================================================================
*/

#include<stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node *next;
}Node;

Node* create(){
	Node* p;
	int n, val;
	printf("\nEnter the Number of element in the list :");
	scanf("%d", &n);
	p = (Node*) malloc(sizeof(Node));
	printf("Enter the value: ");
	scanf("%d", &val);
	p->data = val;	
	p->next = NULL;
	
	Node* hp = p;
	n = n - 1;
	while(n--){
		p->next = (Node*) malloc(sizeof(Node));
		p = p->next;
		printf("\nEnter the value: ");
		scanf("%d", &val);
		p->data = val;
		p->next = NULL;
	}
	return hp;	
}

void display(Node* p){
	Node* hp = p;
	while(hp != NULL){
		printf("(%d) -> ", hp->data);
		hp = hp->next;
	}
	printf("\n");
}

Node* insert(Node* head){
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
		head = temp; 
	} else {
		t = t - 2;
		while(t--){
			head1 = head1->next;
		}
		temp->next = head1->next;
		head1 -> next = temp;
	}
	return head;
}

Node* delete(Node* head){
	int t;
	printf("Enter the Position which you want to delete : ");
	scanf("%d", &t);
	Node* head1 = head;
	
	if(t==1){
		head = head->next;
		free(head1);
	} else {
		t = t - 2;
		while(t--){
			head1 = head1 -> next;	
		}
		Node* temp = head1 -> next;
		head1 -> next = temp -> next;
		free(temp);
	}
	return head;
}

void reverse(Node* head){
	int a[20],i = 0;
	Node* temp = head;
	while(temp != NULL){
		a[i] = temp -> data;
		temp = temp -> next;				
		i++;
	}
	for(i=i-1;i>=0; i--){
		printf("(%d) -> ", a[i]);
	}
}

Node* reverseLL(Node* head){
	Node *prev = NULL, *current = head, *next;
	
	while(current != NULL){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

int main(){
	
	// Add menu driven program by yourself.
	
	Node* p = create();
	display(p);
	p = insert(p);
	display(p);
	p = delete(p);
	display(p);
	reverse(p);
	printf("\nPrinting Reverted Linked List: \n");
	p = reverseLL(p);
	display(p);
	return 0;
}

/*

Enter the Number of element in the list :5
Enter the value: 1

Enter the value: 2

Enter the value: 3

Enter the value: 4

Enter the value: 5
(1) -> (2) -> (3) -> (4) -> (5) -> 

Enter the position you want to enter: 2

Enter the value: 100
(1) -> (100) -> (2) -> (3) -> (4) -> (5) -> 
Enter the Position which you want to delete : 2
(1) -> (2) -> (3) -> (4) -> (5) -> 

Printing reverse of the LinkList:
(5) -> (4) -> (3) -> (2) -> (1) -> 
Printing Reverted Linked List: 
(5) -> (4) -> (3) -> (2) -> (1) -> 


*/

