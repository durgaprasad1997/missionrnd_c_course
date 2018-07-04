/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int noOfBits(long int n)
{
	int i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return i;
}
int octalToHexadecimal(long int num)
{
	if (num < 0)
		return 0;
	if (num <= 7)
		return num;
	bool a1[24];
	int i;
	for (i = 0; i < 24; i++)
		a1[i] = 0;
	int arraycounter = 23;
	int size = noOfBits(num);
	
	for (i = 0; i < size; i++)
	{
		int digit = num % 10;
		int j = 3;
		while (j)
		{
			a1[arraycounter--] = digit % 2;
			digit /= 2;
			j--;

		}
		
		num /= 10;

	}

	
	arraycounter = 24;
	int output = 0;
	int result = 0;
	int count = 6;
	for (i = arraycounter; i >= 0; i--)
	{
		int j = 4;
		while (j != 0)
		{
			output = output * 2 + a1[i - j];
			j--;
		}
		if (count == 0)
			break;
		result = result * 10 + output;
		
		i = i - 3;
		count--;

		output = 0;
	}

	int r = 0;
	while (result != 0)
	{
		r = r * 10 + result % 10;
		result /= 10;
	}



	return r;
}



float octalToHexadecimalFraction(float num)
{
	return 0.0;
}