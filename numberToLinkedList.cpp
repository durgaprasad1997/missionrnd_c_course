/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {


	struct node  *head = NULL, *tail = NULL;
	
	if (N < 0)
		N *= -1;

	if (N == 0)
	{
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = N;
		newnode->next = NULL;
		head = newnode;
		return head;
	}

	while (N > 0)
	{
		int x = N % 10;
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = x;
		newnode->next = NULL;
		if (tail == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}

		N/=10;
	}

	return head;

}