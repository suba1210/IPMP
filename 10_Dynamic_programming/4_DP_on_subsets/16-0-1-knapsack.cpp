// recursive
class Solution
{
    public:
    
    int findAllWays(int index, int weight, int wt[], int val[], int n){
        if(index==0){
            if(wt[0]<=weight)
                return val[0];
            return 0;
        }
        int maxi = INT_MIN;
        if(weight>=wt[index]){
            maxi = max(maxi, val[index] + findAllWays(index-1, weight-wt[index], wt, val, n));
        }
        maxi = max(maxi, findAllWays(index-1, weight, wt, val, n));
        return maxi;
    }    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return findAllWays(n-1, W, wt, val, n);
    }
};

// memoization
class Solution
{
    public:    
    int findAllWays(int index, int weight, int wt[], int val[], int n, vector<vector<int>> dp){
        if(index==0){
            if(wt[0]<=weight)
                return dp[index][weight] = val[0];
            return dp[index][weight] = 0;
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
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        if(wt[0]<=W){
            for(int i=wt[0];i<=W;i++){
                dp[0][i] = val[0];
            }
        }
        for(int item=1;item<n;item++){
            for(int weight=0;weight<=W;weight++){
                int maxi = INT_MIN;
                if(weight>=wt[item]){
                    maxi = max(maxi, val[item] + dp[item-1][weight-wt[item]]);
                }
                maxi = max(maxi, dp[item-1][weight]);
                dp[item][weight] = maxi;
            }
        }
        return dp[n-1][W];
    }
};

// 2 arrays space optimisation
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> prev(W+1, 0), curr(W+1, 0);
        if(wt[0]<=W){
            for(int i=wt[0];i<=W;i++){
                prev[i] = val[0];
            }
        }
        for(int item=1;item<n;item++){
            for(int weight=0;weight<=W;weight++){
                int maxi = INT_MIN;
                if(weight>=wt[item]){
                    maxi = max(maxi, val[item] + prev[weight-wt[item]]);
                }
                maxi = max(maxi, prev[weight]);
                curr[weight] = maxi;
            }
            prev = curr;
        }
        return prev[W];
    }
};

// 1 array Space optimisation
// since we are accessing only indices less than current index in prev array
// instead of having it in seperate array, we can access the previous index elements of the current array
// For that to work, we should iterate the weight from W to 0 not from 0 to W
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> dp(W+1, 0);
        if(wt[0]<=W){
            for(int i=wt[0];i<=W;i++){
                dp[i] = val[0];
            }
        }
        for(int item=1;item<n;item++){
            for(int weight=W;weight>=0;weight--){
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
