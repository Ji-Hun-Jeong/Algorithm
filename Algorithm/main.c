#include "Graph.h"

void main()
{
	Graph* g = (Graph*)calloc(1, sizeof(Graph));
	initGraph(g, 7);
	insertEdge(g, 0, 1, 7);
	insertEdge(g, 0, 4, 3);
	insertEdge(g, 0, 5, 10);
	insertEdge(g, 1, 4, 2);
	insertEdge(g, 1, 5, 6);
	insertEdge(g, 1, 2, 4);
	insertEdge(g, 2, 3, 2);
	insertEdge(g, 3, 4, 11);
	insertEdge(g, 3, 5, 9);
	insertEdge(g, 3, 6, 4);
	insertEdge(g, 4, 6, 5);
	insertEdge(g, 1, 3, 10);
	shortest_path(g, 0);
	deleteGraph(g);
	free(g);
}

