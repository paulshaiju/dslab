// Binary Search Tree operations in C
//exp::35
#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL; int a,x,n;
   printf("Enter the no. of elements to insert:\n"); scanf("%d",&n);
  printf("Enter the elements to insert:\n");
  for(int i=0;i<n;i++)
  {
      scanf("%d",&a); root=insert(root,a);
  }
 

  printf("Inorder traversal: ");
  inorder(root);

  printf("\nEnter the node to delete\n"); scanf("%d",&x);
  root = deleteNode(root, x);
  printf("Inorder traversal: ");
  inorder(root);
}
/*Output::
Enter the no. of elements to insert:
12
Enter the elements to insert:
14 15 4 18 9 16 20 17 3 7 5 2
Inorder traversal: 2 -> 3 -> 4 -> 5 -> 7 -> 9 -> 14 -> 15 -> 16 -> 17 -> 18 -> 20 -> 
Enter the node to delete
9
Inorder traversal: 2 -> 3 -> 4 -> 5 -> 7 -> 14 -> 15 -> 16 -> 17 -> 18 -> 20 -> 
*/