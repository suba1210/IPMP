class Solution {
public:
    int dfs(int src, vector<vector<int>>& adj, vector<int>& informTime, int mx = 0){
        for(auto x : adj[src]){
            mx = max(mx, dfs(x, adj, informTime));
        }
        return mx + informTime[src];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1)
            return 0;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        int src = headID;
        return dfs(src, adj, informTime);
    }
};
