// memoization
class Solution {
public:
    int allPaths(int index, int target, vector<int>& coins, vector<vector<int>> dp){
        if(target==0)
            return dp[index][target] = 0;
        if(index==0 && target!=0){
            if(target%coins[index]==0)
                return target/coins[index];
            return dp[index][target] = 1e9;
        }
        if(dp[index][target]!=-1)
            return dp[index][target];
        int mini = INT_MAX;
        if(target>=coins[index]){
            mini = min(mini, 1 + allPaths(index, target-coins[index], coins, dp)); 
        }          
        mini = min(mini, allPaths(index-1, target, coins, dp));
        return dp[index][target] = mini;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = allPaths(coins.size()-1, amount, coins, dp);
        if(ans>=1e9)
            return -1;
        return ans;
    }
};

// tabulation
class Solution {
public:    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)
                dp[0][target] = target/coins[0];
            else
                dp[0][target] = 1e9;
        }
        for(int i=0;i<coins.size();i++){
            dp[i][0] = 0;
        }
        for(int index=1;index<coins.size();index++){
            for(int target=0;target<=amount;target++){
                int mini = INT_MAX;
                if(target>=coins[index]){
                    mini = min(mini, 1 + dp[index][target-coins[index]]); 
                }          
                mini = min(mini, dp[index-1][target]);
                dp[index][target] = mini;                
            }
        }
        int ans = dp[coins.size()-1][amount];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};

// space optimisation
class Solution {
public:    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount+1, 0), curr(amount+1, 0); 
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)
                prev[target] = target/coins[0];
            else
                prev[target] = 1e9;
        }
        for(int index=1;index<coins.size();index++){
            for(int target=0;target<=amount;target++){
                int mini = INT_MAX;
                if(target>=coins[index]){
                    mini = min(mini, 1 + curr[target-coins[index]]); 
                }          
                mini = min(mini, prev[target]);
                curr[target] = mini;                
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};

