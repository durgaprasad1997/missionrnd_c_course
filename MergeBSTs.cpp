/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
Example 1:

Input :
20        25
/  \      /  \
5    30   10   35
Output :

Bst 1 :
20
/   \
5     30
\   /  \
10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

void inorder(struct BstNode*, struct BstNode*);
void attachNode(struct BstNode*, struct BstNode*);

void merge_two_bst(struct BstNode **root1, struct BstNode *root2) {

	if (root2 == NULL)
		return;
	struct BstNode *tmp = *root1;
	if (!tmp){
		*root1 = root2;
		return;
	}



	struct BstNode *tmp2 = *root1;
	struct BstNode *tmp3= root2;

	while (tmp2->right != NULL)
	{
		tmp2 = tmp2->right;
	}

	int a = tmp2->data;

	while (tmp3->left != NULL)
	{
		tmp3 = tmp3->left;
	}
	int b = tmp3->data;

	if (a < b)
	{

		tmp2->right = root2;
	}


	else
	{

		inorder(tmp, root2);
		tmp = *root1;

	}
}

void inorder(struct BstNode *root1, struct BstNode* root2)
{
	if (root2->left){
		inorder(root1, root2->left);
		
	}
	
	root2->left = NULL;


	attachNode(root1, root2);

	if (root2->right){
		inorder(root1, root2->right);
		
	}
	
	root2->right = NULL;
}

void attachNode(struct BstNode *root1, struct BstNode* node)
{
	if (root1->data == node->data){
		return;
	}
	if (root1->data > node->data && root1->left)
		attachNode(root1->left, node);
	else if (root1->data > node->data)
		root1->left = node;


	if (root1->data < node->data && root1->right)
		attachNode(root1->right, node);
	else if (root1->data < node->data)
		root1->right = node;

	
}