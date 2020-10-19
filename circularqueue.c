#include<stdio.h>
#include<stdlib.h>
int main()
{
	int max,front=-1,rear=-1,a,val;
	printf("\n enter max size of array\n");
	scanf("%d",&max);
	int arr[max];
	while(1){
	printf("\n1)enqueue \n2)dequeue \n3)display \n4)exit \n");
	printf("\n enter operation you want to perform\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:{
			if((rear+1)%max==front)
		{
			printf("\n array is full");
			break;
		}
		else if(front==-1&&rear==-1)
		{
			front=0;
			rear=0;
		}
		else if(front!=0&&rear==max-1)
		{
			rear=0;
		}
		else{
			rear=(rear+1)%max;
		}
		printf("\n enter value to be inserted\n");
		scanf("%d",&val);
		arr[rear]=val;
		}
		break;
		case 2:
		{
			if(front==-1&&rear==-1)
			{
				printf("\n no element present\n");
				break;
			}
			else if(front==rear)
			{
				front =-1;
				rear=-1;
			}
			else if(front==max-1)
			{
				front=0;
			}
			else{
				front++;
			}
		break;	

		}
		case 3:{
			if(front==-1)
		{
			printf("\nNo element present\n");
		}
		else{
			if(front>rear)
			{
				for(int i=0;i<=rear;i++)
				{
					printf(" %d ",arr[i]);
				}
				for(int j=front;j<max;j++)
				{
					printf(" %d ",arr[j]);
				}
			}
			else{
				for(int i=front;i<=rear;i++)
				{
					printf(" %d ",arr[i]);
				}
			}
		}
	}
			break;
		case 4:
			exit(0);
		default:
			printf("\nenter correct option");						
	}
}
}
	
	