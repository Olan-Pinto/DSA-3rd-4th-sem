#include<stdio.h>
#include<stdlib.h>
int main()
{
	int max,front=-1,rear=-1,a;
	printf("\n enter number of elements in your array\n");
	scanf("%d",&max);
	int arr[max];
	while(1){
	printf("\n 1) enqueue \n2)dequeue \n 3) display\n 4) exit");
	printf("\n enter operation you want to perform\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			if(rear==max-1)
			{
				printf("\n queue is full\n");
				break;
			}
			if(front==-1&&rear==-1){
				front++;
				rear++;
				printf("\nenter element you want to enter \n");
				scanf("%d",&arr[rear]);
				
			}
			else
			{
				rear++;
				printf("\n enter element you want to enter \n");
				scanf("%d",&arr[rear]);
				
			}
			break;
		case 2:
			if(front==-1)
			{
				printf("\n no element present in the queue\n");
			}
			else{
				front++;
			}
		break;
		case 3:
			printf("\n queue elements are\n");
			for(int i=front;i<rear;i++)
			{
				printf("%d",arr[i]);
			}
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Enter correct option");
	}
	}
}