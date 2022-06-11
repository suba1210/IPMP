#include<bits/stdc++.h> 
using namespace std; 

void topologicalSort(vector<int> adj[], int V){
    vector<int> inDegree(V, 0);

    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            inDegree[x]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0)
            q.push(i);
    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x:adj[node]){
            if(--inDegree[x]==0){
                q.push(x);
            }
        }
        count++;
    }
    if(count!=V)
        cout<<"Cycle found";
    else
        cout<<"Cycle not found";
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);  
  
    topologicalSort(adj,V);

	return 0; 
} 
