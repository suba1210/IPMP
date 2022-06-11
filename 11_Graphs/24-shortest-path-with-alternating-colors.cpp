class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> res(n,{INT_MAX,INT_MAX});
        res[0]={0,0};
        vector<vector<int>> redAdj(n), blueAdj(n);
        
        for(int i=0;i<redEdges.size();i++){
            redAdj[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        
        for(int i=0;i<blueEdges.size();i++){
            blueAdj[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        
        queue<pair<int,int>> q;
        
        q.push({0,1});
        q.push({0,-1});
        
        int currentDist = 0;
        
        while(!q.empty()){
            int qsize = q.size();
            
            while(qsize--){
                auto [node, edge] = q.front();
                q.pop();
                
                if(edge==1){
                    for(auto x : redAdj[node]){
                        if(res[x].second > currentDist+1){
                            q.push({x, -1});
                            res[x].second = currentDist+1;
                        }
                    }
                } else if(edge==-1){
                    for(auto x : blueAdj[node]){
                        if(res[x].first > currentDist+1){
                            q.push({x, 1});
                            res[x].first = currentDist+1;
                        }
                    }
                }
            }
            
            currentDist++;
        }
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            int mini = min(res[i].first, res[i].second);
            ans[i] = ((mini==INT_MAX) ? -1 : mini);
        }
        
        return ans;
        
    }
};