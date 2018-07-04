/*

	Raju bhai is a new don in town. He enjoys hanging people every weekend.
	This weekend he assembled N people in a circular manner (1,2,..N,1) and choosen a random integer K. 
	He framed certain rules to hang people.
	
	Rule 1: He skips K-1 persons (inclusive) and hang Kth person.
	Rule 2: He always starts counting from 1st person.
	Rule 3: The last person will be allowed to live for rest of his life.
	
	Sample Case:
		Given N=5, K=2
			Initial state: 1,2,3,4,5
		Step 1: skips 1 and hangs 2
			1,3,4,5
		Step 2: Now skips 3 and hangs 4
			1,3,5
		Step 3: Now skips 5 and hangs 1
			3,5
		Step 4: Now skips 3 and hangs 5
			3
		As 3 is only person, he lets him live.

	Save our friend Mary by choosing correct position in the initial circle.
	You have to return the integer x, such that if mary is positioned at x in [1..N] she
	will not be killed, if no such position exists, return -1
	Fill the below function with code and return the postion.
	Return -1 for error cases
*/
#include<stdio.h>
#include<malloc.h>



struct node
{
	int item;
	struct node *next;
};

int counte = 1;

int save(int n, int k, struct node *h)
{
	if (counte == n)
		return h->item;

	else
	{
		struct node *c;
		c = h;
		int i;
		for (i = 1; i < k - 1; i++)
		{
			h = h->next;
		}
		//printf("%d ", h->next->item);
		h->next = h->next->next;
		h = h->next;
		counte++;
		return save(n, k, h);
	}

}
int saveMary(int n, int k){
	if (n <= 0 || k <= 0)
		return -1;

	struct node**a = (struct node**)malloc((n + 1)*sizeof(struct node *));
	int i;
	for (i = 1; i <= n; i++)
	{
		a[i] = (struct node *)malloc(sizeof(struct node));
		a[i]->item = i;
	}
	struct node *head, *current;
	current = a[1];
	head = current;

	for (i = 2; i <= n; i++)
	{
		current->next = a[i];
		current = current->next;
	}
	current->next = head;

	/*	current=head;
	for (i = 1; i <= n; i++)
	{
	printf("%d ", current->item);
	current = current->next;
	}  */



	counte = 1;
	return save(n, k, head);

	return 0;
}
