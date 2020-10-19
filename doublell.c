#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*head=NULL,*temp,*preptr;
int main()
{
	int a,val,loc;
	while(1){
	printf("\n 1)insertion at the beginning \n 2) insertion at end \n 3) insertion afer a specified node \n 4)deletion at the beginning \n 5) deletion at the end \n 6) deletion of specified node \n 7) display \n 8) search \n");
	printf("\n enter operation you want to perform\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			printf("\n enter data ");
			scanf("%d",&val);
			struct node* newnode =(struct node*)malloc(sizeof(struct node));
			if(head==NULL)
			{
				newnode->data=val;
				newnode->left=NULL;
				newnode->right=NULL;
				head=newnode;
				break;
			}
			else
			{
				newnode->data=val;
				newnode->right=head;
				head->left=newnode;
				newnode->left=NULL;
				head=newnode;
			}
		break;	
		case 2:{
			struct node* newnode =(struct node*)malloc(sizeof(struct node));
			printf("\n enter data\n");
			scanf("%d",&val);
			if(head==NULL)
			{
				newnode->data=val;
				newnode->left=NULL;
				newnode->right=NULL;
				head=newnode;
				break;
			}
			else{
			temp=head;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			newnode->data=val;
			newnode->left=temp;
			temp->right=newnode;
			newnode->right=NULL;
		}
		break;
		}
		case 3:{
			struct node* newnode=(struct node*)malloc(sizeof(struct node));
			printf("\n enter location of node after which your data will be inserted\n");
			scanf("%d",&loc);
			if(head==NULL)
			{
				printf("there is no existing node");
				break;
			}
			if(loc==1)
			{
				printf("\n enter data\n");
				scanf("%d",&val);
				newnode->data=val;
				newnode->left=head;
				newnode->right=head->right;
				head->right->left=newnode;
				head->right=newnode;
				break;
			}
			else{
				printf("\n enter data\n");
				scanf("%d",&val);
				temp=head;
				for(int i=0;i<loc-1;i++)
				{
					temp=temp->right;
				}
				newnode->data=val;
				newnode->right=temp->right;
				newnode->left=temp;
				temp->right->left=newnode;
				temp->right=newnode;
			}
			break;
		}
		case 4:{
			if(head==NULL)
			{
				printf("\nno element to delete\n");
				break;
			}
			else{
				temp=head;
				head=head->right;
				head->left=NULL;
				free(temp);
			}
			break;
		}
		case 5:{
			if(head==NULL)
			{
				printf("\nno element to delete\n");
				break;
			}
			else{
			temp=head;
			while(temp->right!=NULL)
			{
				preptr=temp;
				temp=temp->right;
			}
			preptr->right=NULL;
			free(temp);
		}

		break;
		}
		case 6:{
			printf("\n enter location of node to be deleted\n");
			scanf("%d",&loc);
			if(loc==1)
			{
				temp=head;
				head=head->right;
				head->left=NULL;
				free(temp);
				break;
			}
			else{
				temp=head;
				for(int i=0;i<loc-1;i++)
				{
					preptr=temp;
					temp=temp->right;
				}
				preptr->right=temp->right;
				temp->right->left=preptr;
				free(temp);
			}
			break;
		}
		case 7:{
			if(head==NULL)
			{
				printf("\n linked list is empty");
				break;
			}
			else{
				temp=head;
				while(temp!=NULL){
					printf(" %d ",temp->data);
					temp=temp->right;
				}
			}
			break;

		}
		case 8:{
			int flag=1;
				printf("\n enter value to be searched\n");
				scanf("%d",&val);
				if(head==NULL)
				{
					printf("\n no element in the linkedlist\n");
					break;
				}
				else{
					temp=head;
					while(temp!=NULL)
					{
						if(val==temp->data)
						{
							printf("\nelement found\n");
							flag=0;
							break;

						}
						temp=temp->right;
					}
					if(flag==1){
					printf("\n element not in the linked list");
						}
		}	


	}
}
}
}