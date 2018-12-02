#include <bits/stdc++.h>
using namespace std;
class Graph
{	int V;
	vector <int> *adj;

public:
	Graph(int V); //constructor

	void addEdge(int v,int w);

	void BFS(int s);

	void DFS(int s);

};

Graph::Graph(int V)
{
	this->V=V;

	adj=new vector <int > [V]; 
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS (int s)
{	cout<<"\n BFS: "<<endl;
	queue <int> q;
	q.push(s);
	bool visited [V]={false};
	int c;

	while(!q.empty())
	{	c=q.front();
		cout<<c<<" ";
		q.pop();
		visited[c]=true;
		for (int i = 0; i < adj[c].size(); ++i)
		{
			if(visited[adj[c][i]]==false)
			{
				q.push(adj[c][i]);
			}
		}

	}
}

void Graph::DFS (int S)
{	cout<<"\n DFS: \n";
	int t;
	stack <int> s;
	s.push(S);
	bool visited[V]={false};
	while(!s.empty())
	{	t=s.top();
		cout<<t<<" ";
		visited[t]=true;
		s.pop();
		for (int i = 0; i < adj[t].size(); ++i)
		{
			if(visited[adj[t][i]] == false)
				s.push(adj[t][i]);
		}

	}

}

int main()
{	Graph g(4);
	g.addEdge(0, 1); 
	 g.addEdge(0, 2); 
	 g.addEdge(1, 2); 
	 g.addEdge(2, 0); 
	 g.addEdge(2, 3); 
	 g.addEdge(3, 3); 
	 g.BFS(2);
	 g.DFS(2);


	return 0;
}