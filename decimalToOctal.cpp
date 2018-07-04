/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	int a[10];
	int l = 0;
	int i;
	if (num < 0)
		return 0;
	if (num == 0)
		return 0;
		
	while (num > 0)
	{
		a[l] = num % 8;
		num /= 8;
		l++;
	}
	int res = 0;
	for (i = l-1; i >= 0; i--)
	{
		res = res * 10 + a[i];
	}

	return res;
}

float decimalToOctalFraction(float num)
{
	return 0.0;
}

