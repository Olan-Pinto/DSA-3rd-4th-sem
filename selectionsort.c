#include<stdio.h>
void main()
{
	int ar[20], n, i, j, min, t, pos;
	printf("\nenter size of array ");
	scanf("%d",&n);
	printf("\nenter array ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	for(i=0;i<n;i++)
	{
		min = ar[i];
		pos = i;
		for(j=i;j<n;j++)
		{
			if(ar[j]<min)
			{
				min = ar[j];
				pos = j;
			}
		}
		t = ar[pos];
		ar[pos] = ar[i];
		ar[i] = t;
	}	

	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
	}
}
