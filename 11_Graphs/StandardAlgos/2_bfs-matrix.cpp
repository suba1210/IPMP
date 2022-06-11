#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
void addEdge(int x,int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void bfs(int start)
{
	vector<bool> visited(adj.size(), false);
    visited[start] = true;
    queue<int> que;
    que.push(start);
    while(!que.empty()){
        int node = que.front();
        cout<<node<<" ";
        que.pop();
        for(int i=0;i<adj.size();i++){
            if(adj[node][i]==1 && !visited[i]){
                visited[i] = true;
                que.push(i);
            }
        }
    }
}

int main()
{
    int v = 5;
    adj= vector<vector<int>>(v,vector<int>(v,0));
	addEdge(0,1); 
	addEdge(0,2); 
	addEdge(1,2); 
	addEdge(2,3); 
	addEdge(1,3);
	addEdge(3,4);
	addEdge(2,4);
    bfs(0);
}
