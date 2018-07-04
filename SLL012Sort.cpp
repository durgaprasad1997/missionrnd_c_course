/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	
	if (*head == NULL)
		return;
	struct node *temp = *head;
	struct node *hzero = NULL;
	struct node *tzero = NULL;
	struct node *hone = NULL;
	struct node *tone = NULL;
	struct node *htwo = NULL;
	struct node *ttwo = NULL;
	while (temp != NULL)
	{
		if (temp->data == 0)
		{
			if (hzero == NULL)
			{
				hzero = temp;
				tzero = hzero;
			}
			else
			{
				tzero->next = temp;
				tzero = temp;
				
			}
		}
		else if (temp->data == 1)
		{
			if (hone == NULL)
			{
				hone = temp;
				tone = hone;

				
			}
			else
			{
				tone->next = temp;
				tone = temp;
				
			}
		}
		else if (temp->data == 2)
		{
			if (htwo == NULL)
			{
				htwo = temp;
				ttwo = htwo;

				
			}
			else
			{
				ttwo->next = temp;
				ttwo = temp;
				
			}
		}
		temp = temp->next;
	}



	if (hzero != NULL&&htwo != NULL&&hone != NULL)
	{
		tzero->next = hone;
		tone->next = htwo;
		ttwo->next = NULL;
		*head = hzero;
	}
	else if (hzero == NULL&&htwo == NULL)
	{

		tone->next = NULL;
		*head = hone;
	}
	else if (hzero == NULL&&hone == NULL)
	{
		ttwo->next = NULL;
		*head = htwo;
	}
	else if (hone == NULL&&htwo == NULL)
	{
		tzero->next = NULL;
		*head = hzero;
	}
	else if (hzero == NULL&&htwo != NULL&&hone != NULL)
	{
		tone->next = htwo;
		ttwo->next = NULL;
		*head = hone;
	}
	else if (hzero != NULL&&htwo == NULL&&hone != NULL)
	{
		tzero->next = hone;
		tone->next = NULL;
		*head = hzero;
	}
	else if (hzero != NULL&&htwo != NULL&&hone == NULL)
	{
		tzero->next = htwo;
		ttwo->next = NULL;
		*head = hzero;
	}
	
}

