//Program to implement DFS and BFS on an undirected connected graph.
#include<stdio.h>
#include<stdlib.h>
int source,V,E,visited[20],G[20][20],Q[20],front=-1,rear=-1;
void DFS(int i)
{
	int j;
	visited[i]=1;
	printf("%d->",i);
	for(j=1;j<=V;j++)
	{
		if(G[i][j]==1&&visited[j]==0)
			DFS(j);
	}
	
}
void enqueue(int item)
{
	if(front==-1&&rear==-1)
	{
		front=rear=0;
		Q[rear]=item;
	}
}
int dequeue()
{
	int item;
	if(front==-1&&rear==-1)
		return -1;
	else if(front==rear)
	{
		item=Q[front];
		front=rear=-1;
		return item;
	}
	else
	{
		return Q[front++];
	}
}
void BFS(int s)
{
	int i;
	visited[s]=1;
	printf("%d->",s);
	enqueue(s);
	while(front!=-1)
	{
		s=dequeue();
		for(i=1;i<=V;i++)
		{
			if(G[s][i]==1&&visited[i]==0)
			{
				printf("%d->",i);
				visited[i]=1;
				enqueue(i);
			}
		}
	}
}
int main()
{
	int i,j,v1,v2;
	printf("Enter the no of vertices of the graph: ");
	scanf("%d",&V);
	for(i=1;i<=V;i++)
		for(j=1;j<=V;j++)
			G[i][j]=0;
	printf("Enter the no of edges of the graph: ");
	scanf("%d",&E);
	for(i=1;i<=E;i++)
	{
		printf("Enter the edges(format: V1 V2): ");
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	printf("\nThe adjacency matrix:\n");
	for(i=1;i<=V;i++)
	{
		for(j=1;j<=V;j++)
			printf("%d\t",G[i][j]);
		printf("\n");
	}
	for(i=1;i<=V;i++)
		visited[i]=0;
	printf("Enter the source: ");
	scanf("%d",&source);
	printf("\nDFS\n");
	DFS(source);
	for(i=1;i<=V;i++)
		visited[i]=0;
	printf("\nBFS\n");
	BFS(source);
}
/* OUTPUT
Enter the no of vertices of the graph: 4
Enter the no of edges of the graph: 5
Enter the edges(format: V1 V2): 1 2
Enter the edges(format: V1 V2): 1 3
Enter the edges(format: V1 V2): 1 4
Enter the edges(format: V1 V2): 2 3
Enter the edges(format: V1 V2): 3 4

The adjacency matrix:
0       1       1       1
1       0       1       0
1       1       0       1
1       0       1       0
Enter the source: 1

DFS
1->2->3->4->
BFS
1->2->3->4-> */
