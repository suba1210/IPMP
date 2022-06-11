class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n);
        vector<vector<bool>> isConnected(n, vector<bool>(n,false));
        for(auto road : roads){
            degrees[road[0]]++;
            degrees[road[1]]++;
            isConnected[road[0]][road[1]] = true;
            isConnected[road[1]][road[0]] = true;
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = degrees[i] + degrees[j] - ((isConnected[i][j]) ? 1 : 0);
                res = max(res,x);
            }
        }
        
        return res;
    }
};