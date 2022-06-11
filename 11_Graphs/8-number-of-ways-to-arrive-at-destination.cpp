class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<int> ways(n,0), dist(n, INT_MAX);
        dist[0] = 0;
        ways[0] = 1;
        
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});            
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int wt = it.second;
                int adjNode = it.first;
                if(wt + dis < dist[adjNode]){
                    dist[adjNode] = wt + dis;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if(wt + dis == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
        
    }
};
