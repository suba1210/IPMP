// recursion
	int findAllPossible(int index, int n, vector<int> vec){
	    if(index==n-1){
	        return vec[n-1];
	    }
	    if(index>=n){
	        return 0;
	    }
	    int pick = vec[index] + findAllPossible(index+2, n, vec);
	    int notPick = findAllPossible(index+1, n, vec);
	    
	    return max(pick, notPick);
	}

// memoization tc = O(n), sc = O(n)+O(n)
	int findAllPossible(int index, vector<int>& dp, int n, vector<int> vec){
	    if(index<n && dp[index]!=-1){
	        return dp[index];
	    }
	    if(index==n-1){
	        return vec[n-1];
	    }
	    if(index>=n){
	        return 0;
	    }
	    int pick = vec[index] + findAllPossible(index+2, dp, n, vec);
	    int notPick = findAllPossible(index+1, dp, n, vec);
	    
	    return dp[index] = max(pick, notPick);
	}

// tabulation tc = O(n), sc = O(n)
	int findAllPossible(vector<int>& dp, int n, vector<int> vec){
	    dp[0] = vec[0];
	    for(int i=1;i<n;i++){
	        int pick = vec[i] + ((i-2 >= 0) ? dp[i-2] : 0);
	        int notpick = ((i-1 >= 0) ? dp[i-1] : 0);
	        dp[i] = max(pick, notpick);
	    }
	    return dp[n-1];
	    
	}

// space optimisation for tabulation tc = (n), sc = O(1)
	int findAllPossible(vector<int>& dp, int n, vector<int> vec){
	    int prev2 = 0;
	    int prev1 = vec[0];
	    for(int i=1;i<n;i++){
	        int pick = vec[i] + prev2;
	        int notpick = prev1;
	        prev2=prev1;
	        prev1 = max(pick, notpick);
	    }
	    return prev1;
	    
	}

// starter function
	int findMaxSum(int *arr, int n) {
	    vector<int> vec(n);
	    for(int i=0;i<n;i++){
	        vec[i] = arr[i];
	    }
	    return findAllPossible(0, n, vec);
	}