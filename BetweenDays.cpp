/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int y1 = 0, y2 = 0, m1 = 0, m2 = 0, d1 = 0, d2 = 0;
	int i;
	for (i = 1; i <= 2; i++)
	{
		d1 = d1 * 10 + date1head->data;
		d2 = d2 * 10 + date2head->data;
		date1head = date1head->next;
		date2head = date2head->next;
	}
	for (i = 1; i <= 2; i++)
	{
		m1 = m1 * 10 + date1head->data;
		m2 = m2 * 10 + date2head->data;
		date1head = date1head->next;
		date2head = date2head->next;
	}
	for (i = 1; i <= 4; i++)
	{
		y1 = y1 * 10 + date1head->data;
		y2 = y2 * 10 + date2head->data;
		date1head = date1head->next;
		date2head = date2head->next;
	}

	
	int days = 0;
	
	if (y1 != y2)
	{
		if (m1 == m2&&d1 == d2)
		{
			if (y1>y2)
				y1++;
			else
				y2++;
		}
		if (y1 > y2)
		{
			int i;
			for (i = y2 + 1; i <y1; i++)
			{
				if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
					days = days + 366;
				else
					days = days + 365;
			}
		}
		else
		{
			int i;
			for (i = y1 + 1; i <y2; i++)
			{
				if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
					days = days + 366;
				else
					days = days + 365;
				
			}
		}
		if (m1 == m1&&d1 == d2)
			days--;
	}
	


	if (m1 != m2)
	{
		int i;
		int x = 12;
		if (y1 == y2)
			x = m2 - 1;
		int y = 1;
		if (y1 == y2)
			y = m2;


		if (y1 <= y2)
		{

			for (i = m1 + 1; i <= x; i++)
			{
				switch (i)
				{

				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					days = days + 31;
					break;
				case 2:
					if ((y1 % 4 == 0 && y1 % 100 != 0) || y1 % 400 == 0)
						days = days + 29;
					else
						days = days + 28;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					days = days + 30;
					break;
				}
			}
			for (i = y; i < m2; i++)
			{
				switch (i)
				{

				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					days = days + 31;
					break;
				case 2:
					if ((y2 % 4 == 0 && y2 % 100 != 0) || y2 % 400 == 0)
						days = days + 29;
					else
						days = days + 28;
					break;
			
				case 4:
				case 6:
				case 9:
				case 11:
					days = days + 30;
					break;
				
				
				}
			}
		}
		else
		{
			int t = m1;
			m1 = m2;
			m2 = t;

			for (i = m1 + 1; i <= x; i++)
			{
				switch (i)
				{

				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					days = days + 31;
					break;

				case 2:
					if ((y2 % 4 == 0 && y2 % 100 != 0) || y2 % 400 == 0)
						days = days + 29;
					else
						days = days + 28;
					break;
				
				case 4:
				case 6:
				case 9:
				case 11:
					days = days + 30;
					break;
				}
			}
			for (i = y; i < m2; i++)
			{
				switch (i)
				{

				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					days = days + 31;
					break;
				case 2:
					if ((y1 % 4 == 0 && y1 % 100 != 0) || y1 % 400 == 0)
						days = days + 29;
					else
						days = days + 28;
					break;
				
				case 4:
				case 6:
				case 9:
				case 11:
					days = days + 30;
					break;
			
				}
			}
		}
	}
	
	if (d1 != d2)
	{
		if (m1 == m2)
		{
			if (d1>d2)
				days = days + (d1 - d2) - 1;
			else
				days = days + (d2 - d1) - 1;
			m1 = 0;
			m2 = 0;
		}
		switch (m1)
		{
		case 0:
			days = days + 0;
			break;

		case 1:
			days = days + (31 - d1);
			break;
		case 2:
			if ((y1 % 4 == 0 && y1 % 100 != 0) || y1 % 400 == 0)
				days = days + 29 - d1;
			else
				days = days + 28 - d1;
			break;
		case 3:
			days = days + 31 - d1;
			break;
		case 4:
			days = days + 30 - d1;
			break;
		case 5:
			days = days + 31 - d1;
			break;
		case 6:
			days = days + 30 - d1;
			break;
		case 7:
			days = days + 31 - d1;
			break;
		case 8:
			days = days + 31 - d1;
			break;
		case 9:
			days = days + 30 - d1;
			break;
		case 10:
			days = days + 31 - d1;
			break;
		case 11:
			days = days + 30 - d1;
			break;
		case 12:
			days = days + 31 - d1;
			break;


		}


		switch (m2)
		{
		case 0:
			days = days + 0;
			break;
		case 1:
			days = days + (1 - d2);
			break;
		case 2:
			if ((y1 % 4 == 0 && y1 % 100 != 0) || y1 % 400 == 0)
				days = days + 1 - d2;
			else
				days = days + 1 - d2;
			break;
		case 3:
			days = days + 1 - d2;
			break;
		case 4:
			days = days + 1 - d2;
			break;
		case 5:
			days = days + 1 - d2;
			break;
		case 6:
			days = days + 1 - d2;
			break;
		case 7:
			days = days + 1 - d2;
			break;
		case 8:
			days = days + 1 - d2;
			break;
		case 9:
			days = days + 1 - d2;
			break;
		case 10:
			days = days + 1 - d2;
			break;
		case 11:
			days = days + 1 - d2;
			break;
		case 12:
			days = days + 1 - d2;
			break;


		}


	}
	
	return days;
}