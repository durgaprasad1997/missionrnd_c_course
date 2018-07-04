/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>
#include<malloc.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
static int sum1 = 0;
static bool b1 = true;
static int b2 = true;
static int sum2 = 0;

int get_height(struct node *root){

	if (root==NULL)
		return 0;
	sum1 = 0, sum2 = 0, b1 = true, b2 = true;

	int lside = get_height(root->left);
	int rside = get_height(root->right);

	if (lside > rside)
		return lside + 1;
	return rside + 1;
}

bool isLast(struct node *n)
{
	if (n->left== NULL&&n->right==NULL)
		return 1;
	return 0;
}

int get_left_subtree_sum(struct node *root){

	
	if (root == NULL)
		return sum1;

	if (b1 == true)
	{
		root = root->left;
		b1 = false;
		return get_left_subtree_sum(root);
	}

	else
	{

		sum1 = sum1 + root->data;

		//printf(" %d  ", sum1);
		//return
		get_left_subtree_sum(root->left);
			get_left_subtree_sum(root->right);

	}
	

		
	
		return sum1;
		


	
}


int get_right_subtree_sum(struct node *root){
	


	if (root == NULL)
		return sum2;

	if (b2 == true)
	{
		root = root->right;
		b2 = false;
		return get_right_subtree_sum(root);
	}

	else
	{

		sum2 = sum2 + root->data;

		//printf(" %d  ", sum1);
		//return
		get_right_subtree_sum(root->left);
		get_right_subtree_sum(root->right);

	}

	
	return sum2;




}

