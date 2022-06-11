class Solution {
public:
    bool bipartiteBfs(int src, vector<vector<int>> adj, int color[]) {
        queue<int>q;
        q.push(src); 
        color[src] = 1; 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop();

            for(auto it : adj[node]) {
                if(color[it] == -1) {
                    color[it] = 1 - color[node]; 
                    q.push(it); 
                } else if(color[it] == color[node]) {
                    return false; 
                }
            }
        }
        return true; 
    }
    bool checkBipartite(vector<vector<int>> adj, int n) {
        int color[n];
        memset(color, -1, sizeof color); 
        for(int i = 0;i<n;i++) {
            if(color[i] == -1) {
                if(!bipartiteBfs(i, adj, color)) {
                    return false;
                }
            }
        }
        return true; 
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        
        for(auto x : dislikes){
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }
        
        return checkBipartite(adj,n);
        
    }
};