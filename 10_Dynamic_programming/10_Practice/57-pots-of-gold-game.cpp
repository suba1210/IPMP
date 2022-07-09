class Solution{
public:
    int allWays(int start, int end, vector<int>& A, vector<vector<int>>& dp){
        if(start==end)
            return A[start];
        if(end == start+1)
            return max(A[start],A[end]);
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int chooseStart = A[start] + min(allWays(start+2, end, A, dp), allWays(start+1, end-1, A, dp));
        int chooseEnd = A[end] +min(allWays(start+1, end-1, A, dp), allWays(start, end-2, A, dp));
        
        return dp[start][end] = max(chooseStart, chooseEnd);
    }
    int maxCoins(vector<int>&A, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
	    return allWays(0, n-1, A, dp);
    }
};