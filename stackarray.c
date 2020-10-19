#include<stdio.h>
#include<stdlib.h>
int main()
{
	int max,top=-1,a,n;
	printf("\n enter size of array \n");
	scanf("%d",&max);
	int arr[max];
	while(1){
	printf("\n 1)Push \n 2)Pop \n 3)display \n4)exit");
	printf("\n enter operation you want to perform\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			if(top==max-1)
			{
				printf("\narray is full\n");
			}
			else{
			printf("\nEnter element to be pushed\n");
			scanf("%d",&n);
			top++;
			arr[top]=n;
		}
		break;
		case 2:
			if(top==-1)
			{
				printf("\nstack is empty\n");
			}
			else
				top--;
		break;
		case 3:
			printf("\nstack elements are\n");
			for(int i=0;i<max;i++)
			{
				printf("%d\n",arr[i]);
			}
		break;	
		case 4:
			exit(0);
		default:
			printf("Enter correct option");	
		break;	
	}
}
}