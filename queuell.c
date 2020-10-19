#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*front=NULL,*rear=NULL,*temp;
void enqueue(int val)
{
	struct node* newnode =(struct node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		newnode->data=val;
		front=newnode;
		rear=newnode;
	}
	else{
		newnode->data=val;
		rear->next=newnode;
		rear=newnode;
	}

}
void dequeue()
{
	if(front==NULL)
	{
		printf("\n queue is empty\n");
	}
	else{
		temp=front;
		front=front->next;
		free(temp);
	}

}
void display()
{
	if(front==NULL)
	{
		printf("\n queue is empty");

	}
	else{
		temp=front;
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
	printf("\n 1) enqueue \n 2) dequeue \n 3) display \n 4) exit \n");
	printf("\n enter operation you want to perform\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1: 
		printf("\nEnter value to enqueue\n");
		scanf("%d",&val);
		enqueue(val);
		break;
		case 2:
		dequeue();
		break;
		case 3:
		display();
		break;
		case 4:
		exit(0);
		default: printf("\n invalid choice \n");
	}
	
	}


}





