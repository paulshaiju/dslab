/* exp 32
binary tree traversal */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		printf("\nEnter the data:");
		scanf("%d",&ptr->data);
		ptr->lc=NULL;
		ptr->rc=NULL;
		printf("\ndo you want to create left child for %d(1/0)",ptr->data);
		scanf("%d",&ch);
		if(ch==1)
		{
			lcptr=(struct tree *)malloc(sizeof(struct tree));
			ptr->lc=lcptr;
			buildtree(lcptr);
		}
		printf("\n do you want to create right child for %d(1/0)",ptr->data);
		scanf("%d",&ch);
		if(ch==1)
		{
			rcptr=(struct tree *)malloc(sizeof(struct tree));
			ptr->rc=rcptr;
			buildtree(rcptr);
		}
	}
}
void inorder(struct tree *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lc);
		printf("%d ",ptr->data);
		inorder(ptr->rc);
	}
}
void preorder(struct tree *ptr)
{
		if(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			preorder(ptr->lc);
			preorder(ptr->rc);
		}
}
void postorder(struct tree *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf("%d ",ptr->data);
	}
}
int main()
{
	struct tree *root;
	root=(struct tree *)malloc(sizeof(struct tree));
	buildtree(root);
	printf("\n inorder traversal    :");
	inorder(root);
	printf("\n preorder traversal    :");
	preorder(root);
	printf("\n postorder traversal    :");
	postorder(root);
	gets();
}
/* output::
Enter the data:5
do you want to create left child for 5(1/0)1
Enter the data:3
do you want to create left child for 3(1/0)1
Enter the data:1
do you want to create left child for 1(1/0)0
do you want to create right child for 1(1/0)0
do you want to create right child for 3(1/0)1
Enter the data:2
do you want to create left child for 2(1/0)0
do you want to create right child for 2(1/0)0
do you want to create right child for 5(1/0)1
Enter the data:4
do you want to create left child for 4(1/0)0
do you want to create right child for 4(1/0)0
ineorder traversal    :1 3 2 5 4 
 preorder traversal    :5 3 1 2 4 
 postorder traversal    :1 2 3 4 5 */