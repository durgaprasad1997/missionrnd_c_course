/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
#include<malloc.h>
int size = 0;
int output[100];
void oneround(int **input,int *output,int startx,int endx,int starty,int endy,int max)
{
	if (size >= max)
		return;
	int i;
	for (i = startx; i < endx; i++)
		output[size++] = input[startx][i];

	for (i = starty+1; i < endy; i++)
		output[size++] = input[i][endx-1];

	for (i = endx-2; i >=startx; i--)
		output[size++] = input[endy-1][i];

	for (i = endy-2; i >=starty+1; i--)
		output[size++] = input[i][startx];

	startx++;
	endx--;
	starty++;
	endy--;
	oneround(input, output, startx, endx, starty, endy, max);


}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows<=0||columns<=0||input_array==NULL)
	return NULL;

	
	//output = (int *)malloc(rows*columns*sizeof(int));
	oneround(input_array,output,0,columns,0,rows,rows*columns);

	size = 0;
	int i;
	
	for (i = 0; i < rows*columns; i++)
		printf("%d ",output[i]);
	return output;

}
