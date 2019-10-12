#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data;
	struct node *prev;
	struct node *next;
}node; 
int get_node(node *head){
	head = (node *)malloc(sizeof(node));
	return head;
}
int create(node *head, node *last, int n){
	int i;
	node *nev;
	if(head==NULL){
		nev = get_node(nev);
		head = nev;
		last = nev;
		head->prev = NULL;
		printf("\nEnter head data ");
		scanf("%d",&head->data);
	}
	nev = head;
	for(i=0;i<n-1;i++){
		nev = get_node(nev);
		printf("\nEnter data ");
		scanf("%d",&nev->data);
		last->next = nev;
		nev->prev = last;
		last = nev;
	}
	last->next = NULL;
	return head;
}
void display(node *head){
	node *temp;
	temp = head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int delete(node *head, int dt){
	node *temp;
	node *p;
	node *n;
	temp = head;
	if(head==NULL){
		printf("\nList empty, can't delete\n");
		return -1;
	}
	else if(head->data==dt){
		head = head->next;
		if(head!=NULL){
			head->prev = NULL;
			free(temp);
		}
		return head;
	}
	while(temp!=NULL&&temp->data!=dt){
		p = temp;
		temp = temp->next;
	}
	if(temp==NULL){
		printf("\nSorry, data not found!\n");
		return -1;
	}
	n = temp->next;
	p->next = n;
	if(temp->next!=NULL){
		n->prev = p;
	}
	free(temp);
	return head;
}
void rev_display(node *head){
	node *temp;
	temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->prev;
	}
}
int insert(node *head, int pos){
	int dt,i=0;
	node *temp,*temp1;
	node *nev;
	temp = get_node(temp);
	if(head==NULL){
		printf("\nEnter data ");
		scanf("%d",&dt);
		temp->data = dt;
		head = temp;
		return head;
	}
	else if(pos==0){
		printf("\nEnter data ");
		scanf("%d",&dt);
		temp->data = dt;
		temp->next = head;
		head->prev = temp;
		head = temp;
		return head;
	}
	nev = head;
	while(nev->next!=NULL&&i<pos-1){
		nev = nev->next;
		i++;
	}
	temp1 = nev->next;
	nev->next = temp;
	temp->prev = nev;
	temp->next = temp1;
	if(temp1!=NULL){
		temp1->prev = temp;
	}
	printf("\nEnter data ");
	scanf("%d",&dt);
	temp->data = dt;
	return head;
}
int main(){
	int n,dt,pos;
	node *head;
	node *last;
	head = NULL;
	printf("How many ");
	scanf("%d",&n);
	head = create(head, last, n);
	display(head);
	/*printf("\nWhich data is to be deleted ");
	scanf("%d",&dt);
	head = delete(head, dt);
	if(head!=-1){
		display(head);
	}*/
	printf("\nEnter position ");
	scanf("%d",&pos);
	head = insert(head, pos);
	display(head);
}





