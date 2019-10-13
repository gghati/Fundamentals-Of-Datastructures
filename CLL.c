/*
=====================================================================
Assignment : Operations on single variable polynomial using circular linked lists.
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Implement polynomial using CLL and perform
	a) Addition of Polynomials
	b) Multiplication of polynomials
	c) Evaluation of polynomial.
	
=====================================================================
*/

#include<stdio.h>

typedef struct {
	int data;
	struct Node *next;
}Node;

Node* getNode(){
	Node* new = (Node*) malloc(sizeof(Node));
	new -> next = NULL;
	return new;
}

Node* create(Node ){
	
}




