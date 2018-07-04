/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	if (head1 == NULL&&head2 != NULL)
		return head2;
	if (head1 != NULL&&head2 == NULL)
		return head1;

	struct node *h = NULL;
	struct node *hnew = NULL;
	struct node *temp = NULL;
	bool b = true;

	if (head1->num <= head2->num)
	{
		h = head1;
		hnew = h;
		temp = h;

		head1 = head1->next;
		h->next = NULL;
	}
	else
	{
		h = head2;
		hnew = h;
		temp = h;
		head2 = head2->next;
		h->next = NULL;
	}
	while (head1 != NULL && head2 != NULL)
	{

		if (head1->num <= head2->num)
		{
			h = head1;

			head1 = head1->next;
			h->next = NULL;
			temp->next = h;
		}
		else
		{
			h = head2;

			head2 = head2->next;
			h->next = NULL;
			temp->next = h;
		}

		h = h->next;
		temp = temp->next;
		h = NULL;
	}



	if (head1 == NULL)
	{
		h = head2;
		temp->next = h;

	}
	else
	{
		h = head1;
		temp->next = h;

	}

	return hnew;
}
