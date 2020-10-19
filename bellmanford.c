#include<stdio.h>
#include<limits.h> 
int k=0;
int d[10];
int p[10];



void bellmanford(int G[10][10], int n, int r)
{
	d[r] = 0;
	for(i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(G[j][k] != 0 )
			}
		}
	}

}
void main()
{
	for(int i=0;i<10;i++)
	{
		d[i] = 999;
		p[i] = -1;
	}		
	int G[10][10] = {{0}}, r, n;
	printf("\nenter number of vertices: ");
	scanf("%d", &n);
	printf("\nenter adjacency matrix\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &G[i][j]);


	printf("\nenter root vertex: ");
	scanf("%d", &r);
	bellmanford(G, n, r);

	
}
