#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L
typedef struct Info
{
	int weight;
	int path;
}Info;
typedef struct Graph
{
	int numOfVertex;
	int weightMatrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

void initGraph(Graph* g, int n)
{
	g->numOfVertex = n;
	for (int i = 0; i < MAX_VERTICES; ++i)
	{
		for (int j = 0; j < MAX_VERTICES; ++j)
		{
			if (i == j)
				g->weightMatrix[i][j] = 0;
			else
				g->weightMatrix[i][j] = INF;
		}
	}
}

void insertEdge(Graph* g, int start, int end, int weight)
{
	g->weightMatrix[start][end] = weight;
	g->weightMatrix[end][start] = weight;
}

Info A[MAX_VERTICES][MAX_VERTICES];

void printA(Graph* g, int k)
{
	printf("===========================\n");
	for (int i = 0; i < g->numOfVertex; ++i)
	{
		for (int j = 0; j < g->numOfVertex; ++j)
		{
			if (A[i][j].weight == INF)
				printf(" * ");
			else
				printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("===========================\n");
}

void floyd(Graph* g)
{
	for (int i = 0; i < g->numOfVertex; ++i)
	{
		for (int j = 0; j < g->numOfVertex; ++j)
		{
			A[i][j].weight = g->weightMatrix[i][j];
			A[i][j].path = -1;
		}
	}
	for (int k = 0; k < g->numOfVertex; ++k)
	{
		for (int i = 0; i < g->numOfVertex; ++i)
		{
			for (int j = 0; j < g->numOfVertex; ++j)
			{
				if (A[i][k].weight + A[k][j].weight < A[i][j].weight)
				{
					A[i][j].weight = A[i][k].weight + A[k][j].weight;
					A[i][j].path = k;
				}
			}
		}
		printA(g, k);
	}
}

void showPath(Graph* g, int start, int end)
{
	if (-1 == A[start][end].path)
	{
		printf(" -> %d", end);
		return;
	}
	showPath(g, start, A[start][end].path);
	showPath(g, A[start][end].path, end);
}

void floydPath(Graph* g, int start)
{
	printf("%d부터의 최단경로\n", start);
	for (int i = 0; i < g->numOfVertex; ++i)
	{
		printf("%d : %d", i, start);
		showPath(g, start, i);
		printf(" 최단거리 : %d\n", A[start][i]);
	}

}
int main()
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
	floyd(g);
	floydPath(g, 0);
}