/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int length(char *x)
{
	int i = 0;
	while (x[i] != '\0')
		i++;
	return i;
}
int isOlder(char *dob1, char *dob2) {
	if (dob1 == '\0' || dob2 == '\0')
		return -1;
	int l1 = length(dob1);
	int l2 = length(dob2);
	if (l1 != 10 || l2 != 10)
		return -1;

	int i;
	int y1 = 0;
	int y2 = 0;
	for (i = 6; i <= 9; i++)
	{
		y1 = y1 * 10 + (dob1[i] - '0');
		y2 = y2 * 10 + (dob2[i] - '0');
	}
	int m1 = 0, m2 = 0;
	for (i = 3; i <=4; i++)
	{
		m1 = m1 * 10 + (dob1[i] - '0');
		m2 = m2 * 10 + (dob2[i] - '0');
	}
	int d1 = 0, d2 = 0;
	for (i = 0; i <= 1; i++)
	{
		d1 = d1 * 10 + (dob1[i] - '0');
		d2 = d2 * 10 + (dob2[i] - '0');
	}
	if (d1>31 || d2>31 || m1 > 12 || m2 > 12 || (y1 % 4 != 0 && m1 == 2 && d1 == 29) || (y2 % 4 != 0 && m2 == 2 && d2 == 29) ||
		m1 <= 0 || m2 <= 0 )
		return -1;
	if (y1 > y2)
		return 2;
	if (y1 < y2)
		return 1;
	if (m1 > m2)
		return 2;
	if (m1 < m2)
		return 1;
	if (d1 > d2)
		return 2;
	if (d1 < d2)
		return 1;
	else
	return 0;
}