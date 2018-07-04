/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<stdbool.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? ___O(n^2)_______
*/
int *result;

int* sumoftwoBF(int *nums, int target, int len){
	if (nums==NULL||len<0)
	return NULL;
	int i, j;
	result = (int *)malloc(2 * sizeof(int));
	for (i = 0; i < len-1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				if (nums[i] <= nums[j])
				{
					result[0] = nums[i];
					result[1] = nums[j];
				}
				else
				{
					result[0] = nums[j];
					result[1] = nums[i];
				}
				return result;
				free(result);
			}
		}
	}
	return NULL;
	free(result);
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? __________
*/
int partition(int *arr, int low, int  high)
{

	int pivot = arr[high];

	int i = (low - 1);
	int j;
	for (j = low; j <= high - 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			
			

		}
	}
	int t1 = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = t1;
	


	return (i + 1);
}
void quickSort(int *arr, int low, int  high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}



bool search(int *a, int len, int index, int key)
{
	int i = index+1, j = len - 1;
	while (1)
	{
		int mid = (i + j) / 2;

		if (a[mid] == key)
			return true;
		if (i >= j&&a[i] != key)
			return false;
		if (a[mid] > key)
		{
			j = mid;
		}
		if (a[mid] < key)
			i = mid;

	}
}
int *firsttime;
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	if (nums == NULL || len < 0)
	{
		return NULL;
	}
	if (firsttime != nums)
	{
		quickSort(nums, 0, len - 1);
		firsttime = nums;
	}
	result = (int *)malloc(2 * sizeof(int));
	
	int i;
	for (i = 0; i < len; i++)
	{
		if (nums[i]>0)
		{
			int rem = target - nums[i];
			if (search(nums, len, i, rem))
			{
				if (nums[i] <= rem)
				{
					result[0] = nums[i];
					result[1] = rem;
				}
				else
				{
					result[0] = rem;
					result[1] = nums[i];
				}
				return result;
			}
		}
	}


	
	return NULL;
}

/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/

int* sumoftwoExtraArray(int *nums, int target, int len) {
	if (nums==NULL||len<0)
	return NULL;
	result = (int *)malloc(2 * sizeof(int));
	bool *temp = (bool *)malloc(101 * sizeof(bool));
	int i;
	for (i = 0; i < 101; i++)
		temp[i] = false;

	for (i = 0; i < len; i++)
	{
		temp[nums[i]] = true;
	}
	for (i = 0; i < len; i++)
	{
		int second = target - nums[i];
		if (temp[second])
		{
			if (nums[i] <= second)
			{
				result[0] = nums[i];
				result[1] = second;
				return result;
				
			}
		}
	}
	return NULL;
	

}


