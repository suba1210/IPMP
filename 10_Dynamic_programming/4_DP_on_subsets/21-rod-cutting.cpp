// recursive
class Solution{
  public:
    int allWays(int index, int target, int n, int price[]){
        if(index==0){
            return target*price[index];
        }
        int maxi = INT_MIN;
        int rodLength = index+1;
        if(target>=rodLength){
            maxi = max(maxi, price[index]+allWays(index, target-rodLength, n, price));
        }
        maxi = max(maxi, allWays(index-1, target, n, price));
        return maxi;
    }
    int cutRod(int price[], int n) {
        return allWays(n-1, n, n, price);
    }
};

// memoization
class Solution{
  public:
    int allWays(int index, int target, int n, int price[], vector<vector<int>> dp){
        if(index==0){
            return dp[index][target] = target*price[index];
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int maxi = INT_MIN;
        int rodLength = index+1;
        if(target>=rodLength){
            maxi = max(maxi, price[index]+allWays(index, target-rodLength, n, price, dp));
        }
        maxi = max(maxi, allWays(index-1, target, n, price, dp));
        return dp[index][target] = maxi;
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return allWays(n-1, n, n, price, dp);
    }
};

// tabulation
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int i=0;i<=n;i++){
            dp[0][i] = i*price[0];
        }
        for(int index = 1;index<n;index++){
            for(int target=0;target<=n;target++){
                int maxi = INT_MIN;
                int rodLength = index+1;
                if(target>=rodLength){
                    maxi = max(maxi, price[index]+dp[index][target-rodLength]);
                }
                maxi = max(maxi, dp[index-1][target]);
                dp[index][target] = maxi;               
            }
        }        
        return dp[n-1][n];       
    }
};

//  single 1D array space optimisation
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1, 0);
        for(int i=0;i<=n;i++){
            dp[i] = i*price[0];
        }
        for(int index = 1;index<n;index++){
            for(int target=0;target<=n;target++){
                int maxi = INT_MIN;
                int rodLength = index+1;
                if(target>=rodLength){
                    maxi = max(maxi, price[index]+dp[target-rodLength]);
                }
                maxi = max(maxi, dp[target]);
                dp[target] = maxi;               
            }
        }        
        return dp[n];
    }
};
