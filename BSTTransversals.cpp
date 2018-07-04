/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int x1 = 0;
int x3 = 0;
int x2 = 0;
void inorder(struct node *root, int *arr){
	if (root == NULL||arr==NULL)
		return;
	inorder(root->left, arr);
	arr[x1++] = root->data;
	inorder(root->right,arr);

	x2 = 0;
	x3 = 0;
}

void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	arr[x2++] = root->data;
	preorder(root->left, arr);
	
	preorder(root->right, arr);
	
	x1 = 0;
	x3 = 0;
}

void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	postorder(root->left, arr);

	postorder(root->right, arr);
	arr[x3++] = root->data;

	x1 = 0;
	x2 = 0;
}

