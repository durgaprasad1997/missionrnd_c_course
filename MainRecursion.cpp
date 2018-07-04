/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>
#include<malloc.h>
#include<stdio.h>

#include "FunctionHeaders.h"

struct student
{
	char letter;
	struct student *first;
	struct student *second;
	struct student *third;
};


struct student * new_node_spec_p5(char letter){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	temp->letter = letter;
	temp->first = NULL;
	temp->second = NULL;
	temp->third = NULL;
	return temp;
}
struct student * constructFormation_spec(char *students){
	struct student *root = NULL;
	struct student *nodes[2005];
	int i = 0;
	while (students[i] != '\0'){
		nodes[i] = new_node_spec_p5(students[i]);
		i++;
	}

	char invalidLetter = 'X';
	int mid = (i / 3);
	for (int i = 0; i < mid; i++){
		struct student *curnode = nodes[i];
		struct student *firstnode = nodes[(i * 3) + 1];
		struct student *secondnode = nodes[(i * 3) + 2];
		struct student *thirdnode = nodes[(i * 3) + 3];
		if (curnode->letter != invalidLetter){
			if (firstnode->letter != invalidLetter){
				curnode->first = firstnode;
			}
			if (secondnode->letter != invalidLetter){
				curnode->second = secondnode;
			}
			if (thirdnode->letter != invalidLetter){
				curnode->third = thirdnode;
			}
		}
	}
	root = nodes[0];
	return root;
}

void createFormationAndTest(char *students, int expectedMax, int expectedMin) {
	struct student * leaderStudent = constructFormation_spec(students);
	int actualMaxBallDistance = 0;
	int actualMinBallDistance = 0;
	findBallDistance(leaderStudent, &actualMinBallDistance, &actualMaxBallDistance);

	printf("%d %d", actualMaxBallDistance, actualMinBallDistance);
}



int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*
	int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);
	*/

/*	int rows = 5, columns =6;
	int **input_array = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++)
		input_array[i] = (int *)malloc(columns * sizeof(int));
	int i, j, k = 1;
	for (i = 0; i < rows; i++)
	{
		int j;
		for (j = 0; j < columns; j++)
			input_array[i][j] = k++;
	}

	int *output_array = spiral(rows, columns, (int**)input_array);

	//int i;
	//for (i = 0; i < rows*columns; i++)
	//	printf("%d ",output_array[i]);  */



	char students[100] = "ABXXCXXXXXXXX";
	int expectedMinBallDistance = 1;
	int expectedMaxBallDistance = 3;
	createFormationAndTest(students, expectedMaxBallDistance, expectedMinBallDistance);


	return 0;
}