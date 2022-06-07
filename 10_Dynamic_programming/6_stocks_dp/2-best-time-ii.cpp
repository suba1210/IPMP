// recursion tc = O(2^n) sc = O(N)
class Solution {
public:
    int allWays(int index, bool canBuy, vector<int>& prices){
        if(index==prices.size())
            return 0;
        if(canBuy){
            int profit = max(-prices[index]+allWays(index+1, false, prices), allWays(index+1, true, prices));
            return profit;
        } else {
            int profit = max(prices[index]+allWays(index+1, true, prices), allWays(index+1, false, prices));
            return profit;
        }
    }
    int maxProfit(vector<int>& prices) {
        return allWays(0, true, prices);
    }
};

// memoisation tc = O(N*2), sc = O(N*2) + O(N)
class Solution {
public:
    int allWays(int index, bool canBuy, vector<int>& prices, vector<vector<int>> dp){
        if(index==prices.size())
            return 0;
        if(dp[index][canBuy]!=-1){
            return dp[index][canBuy];
        }
        if(canBuy){
            int profit = max(-prices[index]+allWays(index+1, false, prices, dp), allWays(index+1, true, prices, dp));
            return dp[index][canBuy] = profit;
        } else {
            int profit = max(prices[index]+allWays(index+1, true, prices,dp), allWays(index+1, false, prices, dp));
            return dp[index][canBuy] = profit;
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return allWays(0, true, prices, dp);
    }
};

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));        
        for(int index=prices.size()-1;index>=0;index--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                if(canBuy){
                    int profit = max(-prices[index]+dp[index+1][false],dp[index+1][true]);
                    dp[index][canBuy] = profit;
                } else {
                    int profit = max(prices[index]+dp[index+1][true], dp[index+1][false]);
                    dp[index][canBuy] = profit;
                }                
            }
        }
        return dp[0][1];
        
    }
};

// space optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> next(2, 0), curr(2, 0);        
        for(int index=prices.size()-1;index>=0;index--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                if(canBuy){
                    int profit = max(-prices[index]+next[false],next[true]);
                    curr[canBuy] = profit;
                } else {
                    int profit = max(prices[index]+next[true], next[false]);
                    curr[canBuy] = profit;
                }                
            }
            next = curr;
        }
        return next[1];
        
    }
};