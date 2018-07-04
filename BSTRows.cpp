/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
#include<malloc.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int *a;
int index = 0;

int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}


void printLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		a[index++] = root->data;
	//printf("%d ", root->data);
	else if (level > 1)
	{
		printLevel(root->right, level - 1);
		printLevel(root->left, level - 1);
	}
}


void print(struct node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printLevel(root, i);
}







int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
    return NULL;

	struct node*r = root;
	a=(int *)malloc(100*sizeof(int));
	
	print(root);
	
	 index = 0;
	 return a;
}
