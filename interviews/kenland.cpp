#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

	vector< vector <int>> adj;
	int bfs_a_component(int startNode, unordered_set<int> &visGlobal, int &redundantRoads)
	{
		unordered_set<int> visLocal;
		queue<int> q;
		q.push(startNode);
		visLocal.insert(startNode);
		visGlobal.insert(startNode);
		while(!visLocal.empty())
		{
			int node = q.front();
			q.pop();
			for(int i =0; i < adj[node].size(); i++)
			{
				if(visLocal.find(adj[node][i]) != visLocal.end())
				{
					redundantRoads++;
				}
				else
				{
					// mark as visited
					visLocal.insert(adj[node][i]);
					visGlobal.insert(adj[node][i]);
					//push to queue
					q.insert(adj[node][i]);
				}
			}
		}
		return visLocal.size();
	}

	int countHappiness(set<int> &cL)
	{
		int happiness =0;
		for(auto it = cL.begin(); it != cL.end(); it++)
		{
			int size = *it;
			happiness += (size-1)*size;
		}
		return happiness;
	}
	void maxHappiness()
	{
		int n, m, xi, xj;
		cin>>n>>m;
		adj = vector< vector <int>> (n+1, vector<int>());
		for(int i =0; i < m; i++)
		{
			cin>>xi>>xj;
			adj[xi].push_back(xj);
			adj[xj].push_back(xi);
		}

		// look up connected componenets
		set<int> componentLenghts;
		unordered_set<int> visGlobal;
		int redundantRoads = 0;
		for(int i =1; i<= n; i++)
		{
			if(visGlobal.find(i) == visGlobal.end())
			{
				int size = bfs_a_component(i, visGlobal, redundantRoads);
				if(size > 1)
					componentLenghts.insert(size);
			}
		}
		if(redundantRoads >= 2)
			return countHappiness(componentLenghts);
		else
		{
			while(redundantRoads<2)
			{
				int size = *(componentLenghts.begin());
				componentLenghts.erase(componentLenghts.begin());
				size = size -1;
				redundantRoads++;
				if(size > 1)
					componentLenghts.insert(size);

			}
			return countHappiness(componentLenghts);
		}

	}
};
