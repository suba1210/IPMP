class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n);
        for(auto x : trust){
            adj[x[0]-1].push_back(x[1]-1);
        }
        
        vector<int> inDegree(n);
        for(int i=0;i<n;i++){
            for(auto x : adj[i]){                
                inDegree[x]++;
            }
        }
        int count=0, town;
        for(int i=0;i<n;i++){
            if(inDegree[i]==n-1){
                count++;
                town = i;
            }
        }
        if(count!=1){
            return -1;
        }
        if(adj[town].size()!=0){
            return -1;
        }
        return town+1;

    }
};