#include <stdio.h>
#include <stdlib.h>
#include <queue>
using std::queue;
#define SIZE 50
typedef struct Graph
{
	int numOfVertex;
	int matrix[SIZE][SIZE];
}Graph;
void initGraph(Graph* const g)
{
	g->numOfVertex = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			g->matrix[i][j] = INT_MAX;
		}
	}
}
void insertVertex(Graph* g, int n)
{
	g->numOfVertex = n;
}
void insertEdge(Graph* const g, int start, int end, int dist)
{
	g->matrix[start][end] = dist;
	g->matrix[end][start] = dist;
}
int visited[SIZE];
typedef struct Info
{
	int start;
	int distance;
}Info;
Info distance[SIZE];
void prim(Graph* const g, int start)
{
	for (int i = 0; i < g->numOfVertex; ++i)
	{
		distance[i].distance = INT_MAX;
		g->matrix[i][i] = 0;
	}
	int curVertex = start;
	visited[curVertex] = 1;
	while (1)
	{
		for (int i = 0; i < g->numOfVertex; ++i)
		{
			if (!visited[i] && g->matrix[curVertex][i] < distance[i].distance)
			{
				distance[i].start = curVertex;
				distance[i].distance = g->matrix[curVertex][i];
			}
		}
		int minOfDistance = INT_MAX;
		for (int i = 0; i < g->numOfVertex; ++i)
		{
			if (!visited[i] && distance[i].distance < minOfDistance)
			{
				minOfDistance = distance[i].distance;
				curVertex = i;
			}
		}
		printf("%d -> %d\n", distance[curVertex].start, curVertex);
		visited[curVertex] = 1;
		int cnt = 0;
		for (int i = 0; i < g->numOfVertex; ++i)
		{
			if (visited[i])
				++cnt;
		}
		if (cnt == g->numOfVertex)
			break;
	}
}
int main()
{
	Graph* g = (Graph*)calloc(1, sizeof(Graph));
	initGraph(g);

}