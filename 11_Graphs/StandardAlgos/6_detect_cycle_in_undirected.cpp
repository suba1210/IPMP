#include<bits/stdc++.h> 
using namespace std; 

bool dfsRecur(int src, int parent, vector<bool>& visited, vector<int> adj[]){
    visited[src] = true;
    for(auto x : adj[src]){
        if(!visited[x]){
            if(dfsRecur(x, src, visited, adj))
                return true;
        } else if(x!=parent) {
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> adj[], int V){
    vector<bool> visited(V, false);
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfsRecur(i, -1, visited, adj))
                return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
} 
