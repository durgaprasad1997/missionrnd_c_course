/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
#include<stdbool.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head==NULL)
	return -1;
	struct node *h = head;
	int i = 0;
	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	bool b;
	if (i % 2 != 0)
	{
		i = i / 2 + 1;
		b = false;
	}
	else
	{
		i = i / 2;
		b = true;
	}
	int j = 1;
	while (j <= i)
	{
		if (j == i)
		{
			if (b==false)
			return head->num;
			else
			return (head->num + head->next->num) / 2;
		}
			j++;
		head = head->next;
	}
}
