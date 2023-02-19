//Program to represent Binary Tree using linked list.
#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *lc,*rc;
};
void buildtree(struct tree *ptr)
{
	struct tree *lcptr,*rcptr;
	int ch;
	if(ptr!=NULL)
	{
		printf("\n Enter the data: ");
		scanf("%d",&ptr->data);
		ptr->lc=NULL;
		ptr->rc=NULL;
		printf("\nDo you want to create left child for %d(1/0)",ptr->data);
		scanf("%d",&ch);
		if(ch==1)
		{
			lcptr=(struct tree*)malloc(sizeof(struct tree));
			ptr->lc=lcptr;
			buildtree(lcptr);
		}
		printf("\nDo you want to create left child for %d(1/0)",ptr->data);
		scanf("%d",&ch);
		if(ch==1)
		{
			rcptr=(struct tree*)malloc(sizeof(struct tree));
			ptr->rc=rcptr;
			buildtree(rcptr);
		}
	}
}
void inorder(struct tree*ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lc);
		printf("\t%d",ptr->data);
		inorder(ptr->rc);
	}
}
int main()
{
	struct tree *root;
	root=(struct tree*)malloc(sizeof(struct tree));
	buildtree(root);
	printf("\nBINARY TREE USING LINKED LIST : ");
	inorder(root);
}

/* OUTPUT

Enter the data: 10

Do you want to create left child for 10(1/0)1

 Enter the data: 12

Do you want to create left child for 12(1/0)0

Do you want to create left child for 12(1/0)0

Do you want to create left child for 10(1/0)1

 Enter the data: 20

Do you want to create left child for 20(1/0)1

 Enter the data: 38

Do you want to create left child for 38(1/0)0

Do you want to create left child for 38(1/0)1

 Enter the data: 75

Do you want to create left child for 75(1/0)0

Do you want to create left child for 75(1/0)0

Do you want to create left child for 20(1/0)0

BINARY TREE USING LINKED LIST :         12      10      38      75      20 */
