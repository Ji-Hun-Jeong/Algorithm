#ifndef GRAPH_H
#define GRAPH_H
#include "List.h"
typedef struct Graph
{
	int numOfVertex;
	List* pList;
}Graph;

void initGraph(Graph* const pGraph, int n);
void insertEdge(Graph* const pGraph, int start, int end, int weight);
void print_status(const Graph* const pGraph);
void shortest_path(const Graph* const pGraph, int start);
void deleteGraph(Graph* const pGraph);
#endif

