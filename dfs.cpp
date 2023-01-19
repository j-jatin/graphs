#include<bits/stdc++.h>
using namespace std;

vector<int>output;
void print_vector(vector<int> &arr)
{
	for(auto i:arr)
		cout<<" "<<i;
}

void dfs(vector<vector<int>>adj, int V, int start, int vis[])
{
	if(vis[start])
		return ;

	vis[start]=1;
	output.push_back(start);

	for(auto i:adj[start])
	{
		if(!vis[i])
			dfs(adj,V,i,vis);
	}
}

int main()
{
	int V = 5 ; // V is the no of nodes
	vector<vector<int>>adj(V); // adjacency list
	// 0 based graph !!

	adj[0].push_back(2);
	adj[0].push_back(3);
	adj[0].push_back(1);
	adj[2].push_back(4);

	// dfs traversal
	int vis[V]={0};
	dfs(adj,V,0,vis);
	// 0 2 4 3 1 op
	print_vector(output);

	return 0;
}
