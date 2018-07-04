/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>
#include<math.h>


struct node{
  struct node * left;
  int data;
  struct node *right;
};





struct node * adjustRoot(struct node *root, struct node *temp)
{
	if (root == temp)
		return temp;
	struct node *r;
	if (root->left == temp)
	{
		r = temp;
		while (r->right != NULL)
		{
			r = r->right;
		}
		root->left = NULL;
		r->right = root;
		root = temp;
	}
	else if (root->right== temp)
	{
		
		r = temp;
		while (r->left != NULL)
		{
			r = r->left;
		}
		root->right = NULL;
		
		r->left = root;
		root = temp;
	}

	if (root == temp)
	{
		
		return temp;
	}

return adjustRoot(root->left, temp);
return adjustRoot(root->right, temp);

}


int getLeastHeight(struct node *root)
{
	
	
	if (root == NULL)
		return 0;
	

	int lside =getLeastHeight(root->left);
	int rside = getLeastHeight(root->right);

	if (lside > rside)
		return lside +1;
	return rside +1;
	
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root==NULL||temp==NULL)
  return -1;
	
	int c = getLeastHeight(temp)-1;

	root=adjustRoot(root, temp);

	
	//printf("  %d  %d  ", root->data,  root->left->data);

	int a, b;


	

	struct node *rleft = root->right;
	root->right = NULL;

	a = getLeastHeight(root) - 1;
	b = getLeastHeight(rleft) ;


	//printf("%d %d %d\n", a, b,c);

	
	
	if (a!=0&&a <= b&&a <= c)
		return a;
	else if (b!=0&&b <= a&&b <= c)
		return b;
	else
		return c;
	
	

	


	
}