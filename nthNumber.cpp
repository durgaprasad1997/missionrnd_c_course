/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n <= 0)
		return -1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return nthFibonacci(n - 1) + nthFibonacci(n - 2);

	return 0;
}

bool isPrime(int x)
{
	int i;
	for (i = 2; i <= x / 2; i++)
	{
		if (x%i == 0)
		{
			return 0;

		}
	}
	return 1;
}
int nthPrime(int num)
{
	int i = 2;
	int count = 0;
	if (num <= 0)
		return -1;
	while (true)
	{
		if (isPrime(i))
		{
			count++;
		}
		if (count == num)
			return i;

		i++;
	}

}