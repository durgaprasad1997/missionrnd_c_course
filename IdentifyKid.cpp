/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
/                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
/    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>
#include<math.h>

char goToGen(int, int, int, char[]);
void rot(char[], int);

char identifyKid(int N, int K) {

	if (N < 1 || K < 1 || K>pow(3.0, N))
		return '\0';

	char order[3] = { 'A', 'B', 'C' };
	char res = goToGen(N, K, 1, order);

	return res;
}

char goToGen(int n, int k, int level, char order[3])
{
	int rem = 0, index = 0, tmp = pow(3.0, n - level);
	index = k / tmp;
	if (level < n)
	{
		if (k%tmp == 0)
			index--;
		if (index > 0)
			rot(order, index);
		char res = goToGen(n, k, level + 1, order);
		return res;
	}
	if (level == n){
		int res = index % 3;
		if (res == 0)
			return order[2];
		return order[res - 1];
	}
	else
		return '\0';
}

void rot(char order[3], int noOfRot)
{
	int min = noOfRot % 3;

	for (int i = 0; i < noOfRot; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			char tmp = order[j];
			order[j] = order[j + 1];
			order[j + 1] = tmp;
		}
	}
}