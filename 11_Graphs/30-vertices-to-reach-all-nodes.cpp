class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n, false);
        vector<int> ans;
        
        for(auto x : edges){
            seen[x[1]] = true;
        }
        
        for(int i=0;i<n;i++){
            if(seen[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};