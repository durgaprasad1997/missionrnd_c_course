/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 :checked divisibilty condition until less than number

Way 2 :checked divisibilty condition until less than or equal to squareroot(number)

Way 3:checked divisibilty condition until less than or equal to squareroot(number)and filtered even numbers


Conclusion : 
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){

	if (number < 2)
		return 0;
	int i;
	for (i = 2; i <number; i++)
	{
		if (number%i == 0)
			return 0;
	}
	return 1;
}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number){
	if (number < 2)
		return 0;
	int i;
	for (i = 2; i <= sqrt(number*1.0); i++)
	{
		if (number%i == 0)
			return false;
	}
	return true;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){
	if (number < 2 || number % 2 == 0)
		return 0;
	
	int i;
	for (i = 2; i <= sqrt(number*1.0); i++)
	{
		if (number%i == 0)
			return false;
	}
	return true;
}


