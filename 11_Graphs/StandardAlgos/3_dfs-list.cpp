#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[] ,int i , int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void dfsRecur(vector<int> adj[], int src, vector<bool>& visited){
	visited[src] = true;
	cout<<src<<" ";
	for(auto x : adj[src]){
		if(!visited[x])
			dfsRecur(adj, x, visited);
	}
}

void dfs(vector<int> adj[], int V, int src){
	vector<bool> visited(V, false);
	dfsRecur(adj, src, visited);
}


int main()
{
    int V = 6;
    vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,3); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,2,4);
	addEdge(adj,4,5);
    
    dfs(adj,V,0); //starting from vertex 0  
}
