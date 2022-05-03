#include<bits/stdc++.h>
using namespace std;

int coinCount(int n, int coins[], int sum){
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        dp[0][i] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1];
            if(coins[i]<=sum){
                dp[i][j] += dp[i-coins[j-1]][j];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    int n = 4;
    int coins[] = {2,5,3,6}, sum=10;
    cout<<"Count of coins : "<<coinCount(n, coins, sum);    
}
