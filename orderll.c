#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*head=NULL,*temp=NULL,*preptr=NULL;
int main()
{
	int val,a;
	while(1){
		printf("\n 1) enter elements \n 2) display \n 3) exit \n");
		printf("\n select one operation \n");
		
		scanf("%d",&a);
		switch(a)
		{
		case 1: 
		{	
			struct node* newnode =(struct node*)malloc(sizeof(struct node));
		printf("\n enter element \n");
			scanf("%d",&val);
		if(head==NULL)
		{
		newnode->data=val;
		newnode->next=NULL;
		head=newnode;
		break;
		}
		if(val<head->data)
		{
			newnode->data=val;
			newnode->next=head;
			head=newnode;
			break;
		}
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		if(val>temp->data)
		{
			newnode->data=val;
			temp->next=newnode;
			newnode->next=NULL;
		}
		else{
			temp=head;
			while(temp->next!=NULL&&val>temp->data)
			{
				preptr=temp;
				temp=temp->next;
			}
			newnode->data=val;
			preptr->next=newnode;
			newnode->next=temp;
			break;

		}
		break;
	}
	case 2:
		{	
			temp=head;
			while(temp!=NULL)
			{
				printf(" %d ",temp->data);
				temp=temp->next;
			}
			break;

		}
		case 3:
		{
			exit(0);
		}
	}
}
}
