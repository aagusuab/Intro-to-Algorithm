//Youn Jae Kim
//ykim121
//pa4
//FindPath.c - This program prints out necessary statements.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

#ifndef MAX_LEN
#define MAX_LEN 160
#endif
typedef char *string;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if (in == NULL) {
		printf("Unable to open file %s for reading.\n", argv[1]);
		exit(1);
	} if (out == NULL) {
		printf("Unable to open file %s for writing.\n", argv[2]);
		exit(1);
	}
	int v;
	fscanf(in, "%d", &v);
	Graph G = newGraph(v);

	int x, y;
	while (fscanf(in, "%d %d", &x, &y) == 2) {
		if (x == 0 && y == 0) break;
		addEdge(G, x, y);
	}

	printGraph(out, G);

	List L = newList();
	int source, dest;
	while (fscanf(in, "%d %d", &source, &dest)) {
		if (source == 0 && dest == 0) break;
		BFS(G, source);
		getPath(L, G, dest);
		fprintf(out, "\nThe distance from %d to %d is ", source, dest);
		if (length(L) == 0 || getDist(G,dest) == INF) {
			fprintf(out, "infinity\nNo %d-%d path exists\n", source, dest);
		}
		else {
			fprintf(out, "%d\n", getDist(G, dest));
			fprintf(out, "A shortest %d-%d path is: ", source, dest);
			printList(out, L);
		}
		clear(L);
	}
	freeGraph(&G);
	freeList(&L);
	fclose(in);
	fclose(out);
}