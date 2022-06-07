#include<bits/stdc++.h>
using namespace std;

// recursion => tc = O(N^k) sc = O(N)+O(N)
int minStepsRecur(int step,int k,vector<int> height){
    if(step==0){
        return 0;
    }
    int mini = INT_MAX;
    for(int i=1;i<=k;i++){
        if((step-i)>=0){
            int jump = minStepsRecur(step-i,k,height) + abs(height[step]-height[step-i]);
            mini = min(mini, jump);
        }
    }
    return mini;
}

// memoization => tc = O(n*K) sc = O(N)+O(N)
int minStepsMemo(int step,int k,vector<int> height,vector<int>& dp){
    if(step==0){
        return 0;
    }
    if(dp[step]!=-1){
        return dp[step];
    }
    int mini = INT_MAX;
    for(int i=1;i<=k;i++){
        if((step-i)>=0){
            int jump = minStepsMemo(step-i,k,height,dp) + abs(height[step]-height[step-i]);
            mini = min(mini, jump);
        }
    }
    return dp[step] = mini;
}

// tabulation => tc = O(n*K) sc = O(N)
int minStepsTable(int n, int k, vector<int>& height, vector<int>& dp){
    dp[0] = 0;
    for(int i=1;i<n;i++){ // for each step
        int mini = INT_MAX;
        for(int j=1;j<=k;j++){ // k possiblity jumps
            if(i-j>=0){ 
                int jump = dp[i-j] + abs(height[i]-height[i-j]);
                mini = min(mini, jump); // find min energy in k possibility jumps
            }
        }
        dp[i] = mini; // min of k possibilities is the correct min step for that position
    }
    return dp[n-1];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<minStepsRecur(n-1,k,height)<<endl;
    vector<int> dp(n,-1);
    cout<<minStepsMemo(n-1,k,height,dp)<<endl;
    vector<int> dp1(n,-1);
    cout<<minStepsTable(n,k,height,dp1)<<endl;
}