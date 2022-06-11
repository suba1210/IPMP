#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int src){
    vector<bool> visited(V, false);
    visited[src]=true;
	queue<int> que;
	que.push(src);
	while(!que.empty()){
		int node = que.front();
		cout<<node<<" ";
		que.pop();
		for(auto x : adj[node]){
			if(!visited[x]){
				visited[x] = true;
				que.push(x);
			}
		}
	}
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);
	cout << "Following is Breadth First Traversal: "<< endl; 
	BFS(adj,V,0); 
	return 0; 
} 
