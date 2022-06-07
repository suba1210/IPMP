// recursion 
class Solution{
public:
    int solvePartitions(int i, int j, int N, int arr[]){
        if(i==j)
            return 0;
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + solvePartitions(i,k,N,arr) + solvePartitions(k+1,j,N,arr);
            mini = min(mini, steps);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solvePartitions(1, N-1, N, arr);
    }
};

// memoisation tc=O(N^3)
class Solution{
public:
    int solvePartitions(int i, int j, int N, int arr[], vector<vector<int>>& dp){
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + solvePartitions(i,k,N,arr,dp) + solvePartitions(k+1,j,N,arr,dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solvePartitions(1, N-1, N, arr, dp);
    }
};

// tabulation
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini = INT_MAX;
                for(int k=i;k<j;k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);                    
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
    }
};
