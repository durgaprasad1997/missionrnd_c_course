/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :i checked for every number less than N

Way 2 :i checked for only odd numbers excluding 2 and less than N

Way 3:i checked divisibility condition for a given number with previous primes

Conclusion :
*/

#include <stdio.h>
#include <math.h>
#include<malloc.h>

/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
bool isPrime(int x)
{
	int i;
	for (i = 2; i <=sqrt(x*1.0); i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int* nPrimeBruteForce(int N)
{
	
	if (N<2)
		return NULL;
	int *a = (int *)malloc(sizeof(int)*N / 2);
	int i, j = 0;
	for (i = 2; i <= N; i++)
	{
		if (isPrime(i))
			a[j++] = i;
	}

	return a;

}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	
	if (N<2)
		return NULL;
	int *a = (int *)malloc(sizeof(int)*N / 2);
	int i, j = 0;
	a[j++] = 2;
	for (i = 3; i <= N; i=i+2)
	{
		if (isPrime(i))
			a[j++] = i;
	}

	return a;
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{
	if (N<2)
	return NULL;

	int *a = (int *)malloc(sizeof(int)*N / 2);
	int j = 0, i, k, count = 0;
	a[j++] = 2;
	for (i = 3; i <= N; i=i+2)
	{
		count = 0;
		for (k = 0; k < j; k++)
		{
			if (i%a[k] == 0)
			{
				count++;
				break;
			}
		}
		if (count == 0)
			a[j++] = i;

	}

	return a;
}