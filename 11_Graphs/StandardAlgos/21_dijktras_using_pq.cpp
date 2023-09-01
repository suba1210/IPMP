class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(vector<int>& road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        vector<int> dist(n, 1e18);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int prev = pq.top().second;
            int prevDist = pq.top().first;
            pq.pop();
            for(auto x : adj[prev]){
                int next = x.first;
                int nextDist = x.second;
				if(dist[next] > prevDist + nextDist){
                    dist[next] = prevDist + nextDist;
                    pq.push({dist[next], next});   
                }
            }
        }
        
        return dist[n-1];

    }
};