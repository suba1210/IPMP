// recursive
class Solution {
public:
    
    int allChanges(int index, int target, vector<int>& coins){
        if(index==0){
            if(target%coins[0]==0){
                return 1;
            }
            return 0;
        }
        
        int pick = 0;
        if(target>=coins[index]){
            pick = allChanges(index, target-coins[index], coins);
        }
        int notpick = allChanges(index-1, target, coins);
        return pick + notpick;
    }
    
    int change(int amount, vector<int>& coins) {
        return allChanges(coins.size()-1, amount, coins);
    }
};

// memoisation
class Solution {
public:
    
    int allChanges(int index, int target, vector<int>& coins, vector<vector<int>> dp){
        if(index==0){
            if(target%coins[0]==0){
                return dp[index][target] = 1;
            }
            return dp[index][target] = 0;
        }
        if(dp[index][target]!=-1)
            return dp[index][target];
        
        int pick = 0;
        if(target>=coins[index]){
            pick = allChanges(index, target-coins[index], coins, dp);
        }
        int notpick = allChanges(index-1, target, coins, dp);
        return dp[index][target] = pick + notpick;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return allChanges(coins.size()-1, amount, coins, dp);
    }
};

// tabulation
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                dp[0][target] = 1;
            }
            else
                dp[0][target] = 0;
        }
        for(int index=1;index<coins.size();index++){
            for(int target=0;target<=amount;target++){
                int pick = 0;
                if(target>=coins[index]){
                    pick = dp[index][target-coins[index]];
                }
                int notpick = dp[index-1][target];
                dp[index][target] = pick + notpick;                
            }
        }
        return dp[coins.size()-1][amount];
    }
};

// space optimisation
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1, 0), curr(amount+1, 0) ;
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                prev[target] = 1;
            }
            else
                prev[target] = 0;
        }
        for(int index=1;index<coins.size();index++){
            for(int target=0;target<=amount;target++){
                int pick = 0;
                if(target>=coins[index]){
                    pick = curr[target-coins[index]];
                }
                int notpick = prev[target];
                curr[target] = pick + notpick;                
            }
            prev = curr;
        }
        return prev[amount];
    }
};
