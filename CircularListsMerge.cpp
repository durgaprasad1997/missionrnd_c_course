/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node **head1, struct node **head2){
	if (*head1 == NULL&&*head2 == NULL)
		return -1;

	struct node *first = *head1;
	struct node *second = *head2;
	while (first->next != *head1)
	{
		first = first->next;
	}
	first->next = NULL;
	while (second->next != *head2)
	{
		second = second->next;
	}
	second->next = NULL;

	first = *head1;
	second = *head2;

	//	if (first == NULL&&second != NULL)
	//	return sec;
	//	if (first != NULL&&second == NULL)
	//	return head1;

	struct node *h = NULL;
	struct node *hnew = NULL;
	struct node *temp = NULL;
	bool b = true;

	if (first->data <= second->data)
	{
		h = first;
		hnew = h;
		temp = h;

		first = first->next;
		h->next = NULL;
	}
	else
	{
		h = second;
		hnew = h;
		temp = h;
		second = second->next;
		h->next = NULL;
	}
	while (first != NULL && second != NULL)
	{

		if (first->data <= second->data)
		{
			h = first;

			first = first->next;
			h->next = NULL;
			temp->next = h;
		}
		else
		{
			h = second;

			second = second->next;
			h->next = NULL;
			temp->next = h;
		}

		h = h->next;
		temp = temp->next;
		h = NULL;
	}



	if (first == NULL)
	{
		h = second;
		temp->next = h;

	}
	else
	{
		h = first;
		temp->next = h;

	}

	
	struct node *x = hnew;
	int count = 1;
	while (x->next != NULL)
	{
		count++;
		x = x->next;
	}
	x->next = hnew;
	*head1 = hnew;
	//printf("%d ", count);
	return count;

}