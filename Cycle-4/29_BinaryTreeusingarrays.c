/* EXP 29
PGM TO IMPLEMENT BINARY TREE USING ARRAYS */
#include <stdio.h>
void buildtree(int  a[],int i,int item)
{
	int ch,val;
	a[i]=item;
	printf("\nDo you want to create left child for %d(1/0):",item);
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("\nEnter the left child:");
		scanf("%d",&val);
		buildtree(a,2*i,val);
	}
	printf("\nDo you want to create right child for %d(1/0):",item);
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("Enter the right child:");
		scanf("%d",&val);
		buildtree(a,2*i+1,val);
	}
}
int main()
{
	int i,a[100],item;
	for(i=0;i<100;i++)
		a[i]=-1;
	printf("\nEnter the root node:");
	scanf("%d",&item);
	buildtree(a,1,item);
	printf("\nTREE: ");
	for(i=1;i<=16;i++)
	{
		if(a[i]==-1)
			printf("- ");
		else
			printf("%d ",a[i]);
	}
}
/* Enter the root node:22
Do you want to create left child for 22(1/0):1
Enter the left child:33
Do you want to create left child for 33(1/0):0
Do you want to create right child for 33(1/0):0
Do you want to create right child for 22(1/0):1
Enter the right child:44
Do you want to create left child for 44(1/0):0
Do you want to create right child for 44(1/0):0
TREE: 22 33 44 - - - - - - - - - - - - - */