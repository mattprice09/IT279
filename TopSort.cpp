

#include <iostream>
#include <vector>
#include <queue>
#include <list>



using namespace std;

class topSort
{
	void topoSort(Graph graph, int[] adjList)
	{
		int vertices = graph -> vertices;

		int visitCount = 0;

		queue<int> mainQueue;
		
		//vector of size however many vertices there are, all set to 0
		vector <int> inDegrees(vertices, 0);

		vector <int> topResult;

		for (int i = 0; i < vertices; i++)
		{
			list<int>::iterator iter;

			for (iter = adjList[i].begin(); iter != adjList[i].end(); iter++)
			{
				inDegrees[*iter]++;
			}
		}

		for (int i = 0; i < vertices; i++)
		{
			if (inDegrees[i] == 0)
			{
				mainQueue.push(i);
			}
		}

		while (!mainQueue().empty)
		{
			int temp = mainQueue.front();
			mainQueue.pop();

			topResult.push_back(temp);

			list<int>::iterator iter;

			for (iter = adjList[u].begin(); iter != adjList[temp].end(); iter++)
			{
				if (inDegrees[*iter] == 0)
				{
					q.push(*iter);
				}

				visitCount++;
			}
		}

		if (visitCount != vertices)
		{
			cout << "Error: Cycle in the graph\n";
			return;
		}

		for (int i = 0; i < topResult.size(); i++)
		{
			cout << topResult[i] << " ";
		}
		cout << endl;
	}
};