#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
}*head=NULL,*n,*temp,*preptr;
int main()
{	int a,val,loc;
	while(1)
	{
	printf("\n1)enter element at the beginning \n 2)enter element at the end \n 3)insertion after a specific node \n4)deletion at the beginning\n 5)deletion at the end \n 6)deletion after a specific node \n 7)display \n 8)search\n");
	printf("\n enter operation you want to perform \n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			printf("\n enter element you want to enter \n");
			scanf("%d",&val);
			struct node* newnode = (struct node*)malloc(sizeof(struct node));
			if(head==NULL)
			{
				newnode->data=val;
				head=newnode;
			}
			else{
				newnode->next=head;
				newnode->data=val;
				head=newnode;
			}
		break;
		case 2:
		{
			printf("\n enter element you want to enter \n");
			scanf("%d",&val);
			struct node* newnode = (struct node*)malloc(sizeof(struct node));
			if(head==NULL)
			{
				head =newnode;
				newnode->next=NULL;
				newnode->data=val;
				break;
				
			}
			else{
			
				temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=newnode;
				newnode->next=NULL;
				newnode->data=val;
			}
			break;
		}
		case 3:
		{
			struct node* newnode=(struct node*)malloc(sizeof(struct node));
			printf("\nEnter location of node after which you will enter\n");
			scanf("%d",&loc);
			printf("\n enter element you want to enter\n");
			scanf("%d",&val);
			temp=head;
			if(head==NULL)
			{
				printf("\n linked list is empty\n");
				break;
			}
			if(loc==1)
			{
				newnode->data=val;
				newnode->next=head->next;
				head->next=newnode;
				break;
			}
			else{
			for(int i=0;i<loc-1;i++)
			{
				temp=temp->next;
			}
			newnode->data=val;
			newnode->next=temp->next;
			temp->next=newnode;
		}



			break;
		}
		break;
		case 4:
		{
			if(head==NULL)
			{
				printf("\n linked list is empty\n");
				break;
			}
			temp=head;
			head=head->next;
			free(temp);
			break;
		}
		case 5:
		{
			if(head==NULL)
			{
				printf("\n linked list is empty\n");
				break;
			}
			temp=head;
			while(temp->next!=NULL)
			{
				preptr=temp;
				temp=temp->next;
			}
			preptr->next=NULL;
			free(temp);
		break;	
		}
		case 6:
		{
			if(head==NULL)
			{
				printf("\nno element present to delete\n");
				break;
			}
			printf("\nEnter location of node you want to delete\n");
			scanf("%d",&loc);
			if(loc==1)
			{
				temp=head;
				head=head->next;
				free(temp);
				break;

			}
			temp=head;
			for(int i=0;i<loc-1;i++)
			{
				preptr=temp;
				temp=temp->next;
			}
			preptr->next=temp->next;
			free(temp);
			break;

		}	
		case 7:
			
			if(head==NULL)
			{
				printf("\n linked list is empty");
			}
			else{
				n=head;
				while(n!=NULL){
					printf(" %d ",n->data);
					n=n->next;
				}
			}
			break;
		case 8:
			{ 
				int flag=1;
				printf("\n enter value to be searched\n");
				scanf("%d",&val);
				if(head==NULL)
				{
					printf("\n no element in the linkedlist\n");
					break;
				}
				else{
					n=head;
					while(n!=NULL)
					{
						if(val==n->data)
						{
							printf("\nelement found\n");
							flag=0;
							break;

						}
						n=n->next;
					}
					if(flag==1){
					printf("\n element not in the linked list");
						}
					
			}
			}	

	}
	}
}