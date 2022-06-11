class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& visited, int src){
        int change = 0;
        visited[src] = true;
        for(auto x : adj[src]){
            if(!visited[abs(x)]){
                change += dfs(adj, visited, abs(x)) + (x>0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for(auto x : con){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(-x[0]);
        }
        
        return dfs(adj, visited, 0);
    }
};
