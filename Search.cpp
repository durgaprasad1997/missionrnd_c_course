/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:

Binary Search :

Conclusion :
*/

int linearSearch(int *arr, int len, int key) {
	
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}



int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.

	int i = 0, j = len - 1;
	while (1)
	{ 
		int mid = (i + j) / 2;

		if (arr[mid] == key)
			return mid;
		if (i>= j&&arr[i] != key)
			return -1;
		if (arr[mid] > key)
		{
			j = mid;
		}
		if (arr[mid] < key)
			i = mid;
	}

}