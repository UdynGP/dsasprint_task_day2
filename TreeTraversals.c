/*
Write the different algorithms to perform in-order, pre-order, and post-order traversal of a binary Tree
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-Order Traversal
void inOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);  // Visit left subtree
        printf("%d ", root->data);     // Visit node
        inOrderTraversal(root->right); // Visit right subtree
    }
}

// Pre-Order Traversal
void preOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);      // Visit node
        preOrderTraversal(root->left);  // Visit left subtree
        preOrderTraversal(root->right); // Visit right subtree
    }
}

// Post-Order Traversal
void postOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);  // Visit left subtree
        postOrderTraversal(root->right); // Visit right subtree
        printf("%d ", root->data);       // Visit node
    }
}

// Main function
int main()
{
    // Creating a simple binary tree
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->right->right = createNode(7);

    // Performing traversals
    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}