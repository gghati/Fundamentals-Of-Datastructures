/*
=====================================================================
Assignment : Generalized linked list
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Implement Generalized Linked List to create and display the book index.

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
	printf("Enter the Number of element in the list :");
	scanf("%d", &n);
	p = (Node*) malloc(sizeof(Node));
	
	Node* hp = p;
	while(n--){
		printf("Enter the value: ");
		scanf("%d", &val);
		p->data = val;
		p->next = NULL;
		p->next = (Node*) malloc(sizeof(Node));
		p = p->next;
	}
	return hp;	
}

void display(Node* p){
	Node* hp = p;
	while(hp != NULL){
		printf("(%d) -> ", hp->data);
		hp = hp->next;
	}
}

int main(){
	Node* p = create();
	display(p);
	return 0;
}

