// recursive solution
class Solution{
	public:
	
	int findAllPaths(int index, int targetSum, int n, int arr[]){
        // this base case should not be added, because this does not pass the case: sum = 0, arr = {1,0}
	    // if(targetSum==0){ 
	    //     return 1;
	    // } 
        if(index == n-1){
            if(targetSum==0 && arr[n-1]==0)
                return 2;
            if(targetSum==0 || targetSum == arr[n-1])
                return 1;
            return 0;
        }
	    int pick = 0;
	    if(targetSum >= arr[index]){
	        pick = findAllPaths(index+1, targetSum-arr[index], n, arr);
	    }
	    int notPick = findAllPaths(index+1, targetSum, n, arr);
	    
	    return pick + notPick;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        return findAllPaths(0, sum, n, arr);
	} 
};

// memoization 
class Soltuion{
	public:
	
	int findAllPaths(int index, int targetSum, int n, int arr[], vector<vector<int>> dp){
        // this base case should not be added, because this does not pass the case: sum = 0, arr = {1,0}
	    // if(targetSum==0){ 
	    //     return 1;
	    // } 
        if(index == n-1){
            if(targetSum==0 && arr[n-1]==0)
                return dp[index][targetSum] = 2;
            if(targetSum==0 || targetSum == arr[n-1])
                return dp[index][targetSum] = 1;
            return dp[index][targetSum] = 0;
        }
        if(dp[index][targetSum]!=-1){
            return dp[index][targetSum];
        }
	    int pick = 0;
	    if(targetSum >= arr[index]){
	        pick = findAllPaths(index+1, targetSum-arr[index], n, arr, dp);
	    }
	    int notPick = findAllPaths(index+1, targetSum, n, arr, dp);
	    
	    return dp[index][targetSum] = pick + notPick;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return findAllPaths(0, sum, n, arr, dp);
	}
};

// tabulation
class Solution{
	public:
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        if(sum>=arr[0]){
            dp[0][arr[0]] = 1;
        }
        for(int index=1;index<n;index++){
            for(int targetSum = 0; targetSum<=sum; targetSum++){
        	    int pick = 0;
        	    if(targetSum >= arr[index]){
        	        pick = dp[index-1][targetSum-arr[index]];
        	    }
        	    int notPick = dp[index-1][targetSum];
                dp[index][targetSum] = pick + notPick;                
            }
        }
        return dp[n-1][sum];
	}
};
