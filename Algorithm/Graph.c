#include "Graph.h"

void initGraph(Graph* const pGraph, int n)
{
	pGraph->numOfVertex = n;
	pGraph->pList = (List*)calloc(n, sizeof(List));
	for (int i = 0; i < n; ++i)
	{
		initList(&pGraph->pList[i]);
	}
}

void insertEdge(Graph* const pGraph, int start, int end, int weight)
{
	pushBack_List(&pGraph->pList[start], end, weight);
	pushBack_List(&pGraph->pList[end], start, weight);
}

int visited[MAX_VERTICES];
int distance[MAX_VERTICES];

void print_status(const Graph* const pGraph)
{
	static int step = 1;
	printf("STEP %d : ", step++);
	printf("distance : ");
	for (int i = 0; i < pGraph->numOfVertex; ++i)
	{
		if (INF == distance[i])
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" found : ");
	for (int i = 0; i < pGraph->numOfVertex; ++i)
	{
		printf("%2d ", visited[i]);
	}
	printf("\n\n");
}

int choose(const Graph* const pGraph)
{
	int min = INT_MAX;
	int minIdx = -1;
	for (int i = 0; i < pGraph->numOfVertex; ++i)
	{
		if (!visited[i])
		{
			if (distance[i] < min)
			{
				min = distance[i];
				minIdx = i;
			}
		}
	}
	return minIdx;
}

void shortest_path(const Graph* const pGraph, int start)
{
	for (int i = 0; i < pGraph->numOfVertex; ++i)
		distance[i] = INF;
	for (Node* pNode = pGraph->pList[start].pFirstNode; pNode; pNode = pNode->pNextNode)
		distance[pNode->data.num] = pNode->data.weight;
	visited[start] = TRUE;
	distance[start] = 0;
	for (int i = 0; i < pGraph->numOfVertex - 1; ++i)
	{
		print_status(pGraph);
		int minValue = choose(pGraph);
		visited[minValue] = TRUE;
		// pNode는 인접정점
		for (Node* pNode = pGraph->pList[minValue].pFirstNode; pNode; pNode = pNode->pNextNode)
		{
			if (!visited[pNode->data.num])
			{
				if (distance[minValue] + pNode->data.weight < distance[pNode->data.num])
				{
					distance[pNode->data.num] = distance[minValue] + pNode->data.weight;
				}
			}
		}
	}
}

void deleteGraph(Graph* const pGraph)
{
	for (int i = 0; i < pGraph->numOfVertex; ++i)
	{
		deleteList(&pGraph->pList[i]);
	}
}
