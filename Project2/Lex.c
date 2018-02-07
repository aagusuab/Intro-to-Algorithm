/*Youn Jae Kim
  ykim121
  Programming Assignment 2: List.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define MAX_LEN 160
typedef char *string;

int main(int argc, char* argv[]) {
	// Check for correct number of arguments
	if (argc != 3) {
		return -1;
	}
	// Init Variables
	FILE *in, *in1, *out;
	char line[MAX_LEN];
	char Test[MAX_LEN];
	int numlineArray = 0;
	int i = 0 , j;
	int count = 0;
	
	in1 = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if (in1 == NULL) {
		exit(1);
	} if (out == NULL) {
		exit(1);
	}
	while (fgets(Test, MAX_LEN, in1) != NULL) {
		numlineArray++;
	}
	string lineArray[numlineArray];
	//char **lineArray = malloc(numlineArray * sizeof(char*));
	fclose(in1);
	in = fopen(argv[1], "r");
	if (in1 == NULL) {
		exit(1);
	}
	i = 0;
	while (fgets(line, MAX_LEN, in) != NULL) {
		lineArray[count] = malloc(sizeof(char)*i);
		i = strlen(line) + 1;
		strcpy(lineArray[count], line);
		count++;
	}
	List A = newList();
	append(A , 0);
	
	for (j = 1; j < numlineArray; j++) {
		moveFront(A);
		for (i = 0; i<length(A); i++) {
			string temp = lineArray[get(A)];
			if (strcmp(lineArray[j], temp)< 0) {
				
				insertBefore(A, j);
				break;
			}
			else if (i == length(A) - 1) {
				append(A, j);
				break;
				
			}
			
			moveNext(A);
		}
	}
	moveFront(A);
	for (int p = 0; p < numlineArray; p++){
		fprintf(out,"%s", lineArray[get(A)]);
		moveNext(A);

		
		
	}
	for (j = 0; j< numlineArray; j++) 
	{free(lineArray[j]);}
	freeList(&A);
	fclose(in);
	fclose(out);
	return(0);
};