// recursion
class Solution {
public:
    int allWays(int index, bool canBuy, int transactions, vector<int>& prices)
    {
        if(transactions==0)
            return 0;
        if(index==prices.size())
            return 0;
        if(canBuy){
            int profit = max(-prices[index]+allWays(index+1, false, transactions, prices), allWays(index+1, true, transactions, prices));
            return profit;
        } else {
            int profit = max(prices[index]+allWays(index+1, true, transactions-1, prices), allWays(index+1, false, transactions, prices));
            return profit;
        }
    }
    int maxProfit(vector<int>& prices) {
        return allWays(0, true, 2, prices);
    }
};

// memoisation
class Solution {
public:
    int allWays(int index, bool canBuy, int transactions, vector<int>& prices, vector<vector<vector<int>>>& dp)
{
        if(transactions==0)
            return 0;
        if(index==prices.size())
            return 0;
        if(dp[index][canBuy][transactions]!=-1)
            return dp[index][canBuy][transactions];
        if(canBuy){
            int profit = max(-prices[index]+allWays(index+1, false, transactions, prices, dp), allWays(index+1, true, transactions, prices, dp));
            return dp[index][canBuy][transactions] = profit;
        } else {
            int profit = max(prices[index]+allWays(index+1, true, transactions-1, prices, dp), allWays(index+1, false, transactions, prices, dp));
            return dp[index][canBuy][transactions] = profit;
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return allWays(0, true, 2, prices, dp);
    }
};

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int index=prices.size()-1;index>=0;index--){
            for(int canBuy = 0;canBuy<=1;canBuy++){
                for(int transactions=2;transactions>0;transactions--){
                    if(canBuy){
                        int profit = max(-prices[index]+ dp[index+1][false][transactions], dp[index+1][true][transactions]);
                        dp[index][canBuy][transactions] = profit;
                    } else {
                        int profit = max(prices[index]+dp[index+1][true][transactions-1], dp[index+1][false][transactions]);
                        dp[index][canBuy][transactions] = profit;
                    }                    
                }
            }
        }
        return dp[0][1][2];
    }
};

// space optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        
        for(int index=prices.size()-1;index>=0;index--){
            for(int canBuy = 0;canBuy<=1;canBuy++){
                for(int transactions=2;transactions>0;transactions--){
                    if(canBuy){
                        int profit = max(-prices[index]+ next[false][transactions], next[true][transactions]);
                        curr[canBuy][transactions] = profit;
                    } else {
                        int profit = max(prices[index]+next[true][transactions-1], next[false][transactions]);
                        curr[canBuy][transactions] = profit;
                    }                    
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};
