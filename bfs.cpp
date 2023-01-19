#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &arr)
{
	for(auto i:arr)
		cout<<" "<<i;
}

void bfs(vector<vector<int>>adj, int V)
{
	int n = V;
	vector<int>output;
	int vis[n]={0};
	queue<int> q;
	q.push(0);

	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		output.push_back(node);
		vis[node]=1; 

		for(auto i:adj[node])
		{
			if(!vis[i])
			{
				vis[i]=1;
				q.push(i);
			}
		}
	}

	print_vector(output);
}

int main()
{
	int V = 5 ; // V is the no of nodes
	vector<vector<int>>adj(V); // adjacency list
	// 0 based graph !!

	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[0].push_back(3);
	adj[2].push_back(4);

	// bfs traversal
	bfs(adj,V);

	return 0;
}

// TIME COMPLEXITY !!
// O(N) + O(2E)
// 2E is the total degree = twice the no of edges in the graph !!

// SPACE COMPLEXITY
// O(N) (visited array  +  queue)