#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
private:
	priority_queue<int, vector<int>, greater<int>> m_queueV[100001];
	int m_iNumOfVertex;
	bool m_arrVisited[100001];
	int m_arrOrder[100001];
	int m_iOrder;
public:
	Graph(int n)
		: m_iNumOfVertex(n)
		, m_iOrder(1)
	{
		for (int i = 0; i < 100001; ++i)
		{
			m_arrVisited[i] = false;
			m_arrOrder[i] = 0;
		}
	}
public:
	void insertEdge(int start, int end)
	{
		m_queueV[start].push(end);
		m_queueV[end].push(start);
	}
	void dfs(int start)
	{
		m_arrOrder[start] = m_iOrder++;
		m_arrVisited[start] = true;
		while (!m_queueV[start].empty())
		{
			int i = m_queueV[start].top();
			m_queueV[start].pop();
			if (!m_arrVisited[i])
			{
				dfs(i);
			}
		}
	}
	void showOrder()
	{
		for (int i = 1; i <= m_iNumOfVertex; ++i)
		{
			if (m_arrOrder[i])
				printf("%d\n", m_arrOrder[i]);
			else
				printf("%d\n", 0);
		}
	}
};
int main()
{
	int n, m, r;
	cin >> n >> m >> r;
	Graph* myGraph = new Graph(n);
	int u = 0, v = 0;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		myGraph->insertEdge(u, v);
	}
	myGraph->dfs(r);
	myGraph->showOrder();
}