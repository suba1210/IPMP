// recursion
class Solution {
public:
    int cutAllWays(int i, int j, vector<int>& cuts){
        if(i>j)
            return 0;
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1] - cuts[i-1] + cutAllWays(i,k-1,cuts) + cutAllWays(k+1, j, cuts);
            mini = min(mini, cost);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        return cutAllWays(1,c,cuts);
    }
};

// memoisation
class Solution {
public:
    int cutAllWays(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1] - cuts[i-1] + cutAllWays(i,k-1,cuts,dp) + cutAllWays(k+1, j, cuts,dp);
            mini = min(mini, cost);
        }
        return  dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return cutAllWays(1,c,cuts,dp);
    }
};

//tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j)
                    continue;
                int mini = INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;                
            }
        }
        
        return dp[1][c];
    }
};
