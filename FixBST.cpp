/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
int i = 0;

void inorder_fixBst(struct node*root, int *a)
{
	if (root == NULL)
		return;

	inorder_fixBst(root->left,a);
	a[i++] = root->data;
	inorder_fixBst(root->right, a);

}
void fix(struct node *root, int *a)
{
	if (root == NULL)
		return;

	if (root->data == a[0])
	{
		root->data = a[1];
		
	//	return;
	}
	else if (root->data == a[1])
	{
		root->data = a[0];
	
	//	return;
	}
	fix(root->left, a);
	fix(root->right, a);
}
			

void fix_bst(struct node *root){
	
	if (root == NULL)
		return;
	int * x = (int *)malloc(100 * sizeof(int));
	
	inorder_fixBst(root, x);
	
	int *p = (int *)malloc(2* sizeof(int));

	int j, k;
	int * t = (int *)malloc(100 * sizeof(int));

	for (j = 0; j < i; j++)
	{
		t[j] = x[j];
	}

	for (j = 0; j < i-1; j++)
	{
		for (k = 0; k < i - 1 - j; k++)
		{
			if (t[k]>t[k + 1])
			{
				int pp = t[k];
				t[k] = t[k + 1];
				t[k + 1] = pp;
			}
		}
	}

	

	for (j = 0; j < i; j++)
	{
		if (x[j] != t[j])
		{
			p[0] = x[j];
			p[1] = t[j];
			break;
		}

	}
	//printf("%d %d\n", p[0], p[1]);


	
	fix(root, p);
	
/*	i = 0;
	inorder_fixBst(root, t);
	for (j = 0; j < i; j++)
		printf("%d ", t[j]);*/

	i = 0;

}