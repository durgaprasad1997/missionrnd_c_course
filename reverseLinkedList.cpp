/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	struct node *temp;
	struct node *newnode;

	temp = head->next;
	head->next = NULL;
	if (temp->next == NULL)
	{
		temp->next = head;
		return temp;
	}
	newnode = temp->next;
	while (temp != NULL)
	{

		temp->next = head;
		head = temp;

		if (newnode->next == NULL)
		{
			newnode->next = temp;
			return newnode;
		}
		temp = newnode;
		newnode = newnode->next;
	}



	return newnode;
}
