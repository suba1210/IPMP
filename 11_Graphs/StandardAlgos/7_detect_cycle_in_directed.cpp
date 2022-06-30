#include <bits/stdc++.h>
using namespace std;

bool dfsRecur(int s, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[])
{
    visited[s] = true;
    recStack[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false && dfsRecur(u, visited, recStack, adj) == true)
        {
            return true;
        }
        else if (recStack[u] == true)
        {
            return true;
        }
    }
    recStack[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false), recStack(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfsRecur(i, visited, recStack, adj))
                return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if (DFS(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}
