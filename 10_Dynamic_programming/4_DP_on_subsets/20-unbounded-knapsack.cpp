// memoization
class Solution
{
    public:    
    int findAllWays(int index, int weight, int wt[], int val[], int n, vector<vector<int>> dp){
        if(index==0){
            return ((int)weight/wt[0])*val[0];
        }
        if(dp[index][weight]!=-1){
            return dp[index][weight];
        }
        int maxi = INT_MIN;
        if(weight>=wt[index]){
            maxi = max(maxi, val[index] + findAllWays(index-1, weight-wt[index], wt, val, n, dp));
        }
        maxi = max(maxi, findAllWays(index-1, weight, wt, val, n, dp));
        return dp[index][weight] = maxi;
    }
   
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return findAllWays(n-1, W, wt, val, n, dp);
    }
};

// tabulation
class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        for(int i=0;i<=W;i++){ // this base case alone will differ in this prob compared to 0/1 knapsack 
            dp[0][i] = ((int) i/wt[0]) * val[0];
        }
        for(int item=1;item<n;item++){
            for(int weight=0;weight<=W;weight++){
                int maxi = INT_MIN;
                if(weight>=wt[item]){
                    maxi = max(maxi, val[item] + dp[item][weight-wt[item]]);
                }
                maxi = max(maxi, dp[item-1][weight]);
                dp[item][weight] = maxi;
            }
        }
        return dp[n-1][W];
    }
};

// space optimisation
class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<int> dp(W+1, 0);
        for(int i=0;i<=W;i++){
            dp[i] = ((int) i/wt[0]) * val[0];
        }
        for(int item=1;item<n;item++){
            for(int weight=0;weight<=W;weight++){
                int maxi = INT_MIN;
                if(weight>=wt[item]){
                    maxi = max(maxi, val[item] + dp[weight-wt[item]]);
                }
                maxi = max(maxi, dp[weight]);
                dp[weight] = maxi;
            }
        }
        return dp[W];
    }
};
