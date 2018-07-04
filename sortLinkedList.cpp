/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/
//refered from geeks for geeks

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};
void swap(struct node *a, struct node *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}
struct node * sortLinkedList(struct node *head) {
	int b = 1;
	struct node *p=head;
	struct node *lptr = NULL;


	
	if (p == NULL)
		return NULL;

	while (b)
	{
		b = 0;
		p = head;

		while (p->next != lptr)
		{
			if (p->num > p->next->num)
			{
				swap(p, p->next);
				b = 1;
			}
			p = p->next;
		}
		lptr = p;
	} 

	return head;
}