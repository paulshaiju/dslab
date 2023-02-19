/* exp:33
height of binary tree */
#include <stdio.h>
#include <stdlib.h>
 
struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};
 
int height(struct tree* node)
{
    if (node == NULL)
        return 0;
    else {
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
 
        
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}
 

struct tree* newNode(int data)
{
    struct tree* node
        = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
void buildtree(struct tree *ptr)
{
	struct tree *left,*right;
	int ch;
	if(ptr!=NULL)
	{
		printf("\nEnter the data:");
		scanf("%d",&ptr->data);
		ptr->left=NULL;
		ptr->right=NULL;
		printf("\ndo you want to create left child for %d(1/0)",ptr->data);
		scanf("%d",&ch);
		if(ch==1)
		{
		left=(struct tree *)malloc(sizeof(struct tree));
			ptr->left=left;
			buildtree(left);
		}
		printf("\n do you want to create right child for %d(1/0)",ptr->data);
		scanf("%d",&ch);
		if(ch==1)
		{
			right=(struct tree *)malloc(sizeof(struct tree));
			ptr->right=right;
			buildtree(right);
		}
	}
} 
int main()
{
   
 struct tree *root;
	root=(struct tree *)malloc(sizeof(struct tree));
	buildtree(root);
    printf("Height of tree is %d", height(root)-1);
 
    getchar();
return 0;
}
/*Enter the data:12
do you want to create left child for 12(1/0)1
Enter the data:22
do you want to create left child for 22(1/0)0
do you want to create right child for 22(1/0)0
do you want to create right child for 12(1/0)0
Height of tree is 1*/

