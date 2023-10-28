#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct Info
{
	int num;
	int weight;
}Info;

typedef struct Node
{
	Info data;
	struct Node* pNextNode;
}Node;

void initNode(Node* const pNode);

typedef struct List
{
	int numOfNode;
	Node* pFirstNode;
	Node* pLastNode;
}List;

void initList(List* const pList);
void pushBack_List(List* const pList, int num,int weight);
void deleteList(List* const pList);

#endif
