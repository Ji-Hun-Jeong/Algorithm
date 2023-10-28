#include "List.h"
void initNode(Node* const pNode)
{
	pNode->data.num = 0;
	pNode->data.weight = 0;
	pNode->pNextNode = NULL;
}

void initList(List* const pList)
{
	pList->numOfNode = 0;
	pList->pFirstNode = NULL;
	pList->pLastNode = NULL;
}

void pushBack_List(List* const pList, int num,int weight)
{
	if (pList->numOfNode >= MAX_VERTICES)
	{
		printf("Full");
		return;
	}
	Node* pNewNode = NULL;
	pNewNode = (Node*)calloc(1, sizeof(Node));
	initNode(pNewNode);
	pNewNode->data.num = num;
	pNewNode->data.weight = weight;
	if (!pList->pFirstNode)
	{
		pList->pFirstNode = pNewNode;
		pList->pLastNode = pNewNode;
	}
	else
	{
		pList->pLastNode->pNextNode = pNewNode;
		pList->pLastNode = pList->pLastNode->pNextNode;
	}
	++pList->numOfNode;
}

void deleteList(List* const pList)
{
	Node* pNode = pList->pFirstNode;
	while (pNode)
	{
		Node* pNextNode = pNode->pNextNode;
		free(pNode);
		pNode = pNextNode;
	}
}