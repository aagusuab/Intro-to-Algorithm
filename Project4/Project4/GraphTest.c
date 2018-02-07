//Youn Jae Kim
//ykim121
//pa4
//GraphTest.c- This program tests out the Graph objects.
#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char **argv) {
	int i, s, max, min, d, n = 35;
	List  A1 = newList(); 
	List  A2 = newList(); 
	List  A3 = newList();
	Graph A4 = NULL;

	// Create graph G 
	A4 = newGraph(n);
	for (i = 1; i<n; i++) {
		if (i % 7 != 0) addEdge(A4, i, i + 1);
		if (i <= 28) addEdge(A4, i, i + 7);
	}
	addEdge(A4, 9, 31);
	addEdge(A4, 17, 13);
	addEdge(A4, 14, 33);

	// Adjacent Matrices
	printGraph(stdout, A4);

	// vertex
	for (s = 1; s <= n; s++) {
		BFS(A4, s);
		max = getDist(A4, 1);
		for (i = 2; i <= n; i++) {
			d = getDist(A4, i);
			max = (max<d ? d : max);
		}
		append(A3, max);
	}

	// Determine the Radius and Diameter of G.
	append(A1, 1);
	append(A2, 1);
	min = max = front(A3);
	moveTo(A3, 0);
	moveNext(A3);
	for (i = 2; i <= n; i++) {
		d = getElement(A3);
		if (d == min) {
			append(A1, i);
		}
		else if (d<min) {
			min = d;
			clear(A1);
			append(A1, i);
		}
		if (d == max) {
			append(A2, i);
		}
		else if (d>max) {
			max = d;
			clear(A2);
			append(A2, i);
		}
		moveNext(A3);
	}

	// Printtest results
	printf("\n");
	printf("Radius = %d\n", min);
	printf("Central vert%s: ", length(A1) == 1 ? "ex" : "ices");
	printList(stdout, A1);
	printf("\n");
	printf("Diameter = %d\n", max);
	printf("Peripheral vert%s: ", length(A2) == 1 ? "ex" : "ices");
	printList(stdout, A2);
	printf("\n");

	// Free objects 
	freeList(&A1);
	freeList(&A2);
	freeList(&A3);
	freeGraph(&A4);

	return(0);
}