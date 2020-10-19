#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*head=NULL,*temp;
void push(int val)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=head;
	head=newnode;
}
void pop()
{	if(head==NULL)
	{
		printf("\n no element in the linkedlist\n");
	}
	else{
	temp=head;
	head=head->next;
	free(temp);
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\n no elements present\n");
	}
	else{
		temp=head;
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	
	int a,val;
	while(1){
	printf("\n1) push \n2)pop\n3)display\n4)exit\n");
	printf("\n Enter the operation you want to perform\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1: 
			printf("\nEnter the value to be pushed\n");
			scanf("%d",&val);
			push(val);
			break;
		case 2: 
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default: printf("\nInvalid option");				
	}
}

}







