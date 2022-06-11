#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int src, int dist[]){
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
                dist[x] = dist[node]+1;
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
	int V=4;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,0,2); 
	addEdge(adj,1,3);
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
	dist[0]=0;
	BFS(adj,V,0,dist); 
    
    cout<<"\nDistances : ";
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
	return 0; 
} 
