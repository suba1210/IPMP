// recursion

class Solution {
public:
    int tribonacci(int n) {
        if(n<=0)
            return 0;
        if(n==1 || n==2)
            return 1;
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};

// memoization

class Solution {
public:
    int tribonacciHelper(int n, vector<int>& dp){
        if(n<=0)
            return dp[n] =  0;
        if(n==1 || n==2)
            return dp[n] = 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);        
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return tribonacciHelper(n, dp);
    }
};

// tabulation

class Solution {
public:
    
    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        
        if(n >= 1)
            dp[1] = 1; 
        
        if(n >= 2)
            dp[2] = 1;
        
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
                
        return dp[n];
    }
};

// space optimization

class Solution {
public:
    
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        
        int prev2 = 0, prev1 = 1, curr = 1; 
        
        for(int i=3; i<=n; i++){
            int temp = curr;
            curr = temp + prev1 + prev2;
            prev2 = prev1;
            prev1 = temp;
        }
                
        return curr;
    }
};