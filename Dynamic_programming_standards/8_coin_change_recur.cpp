#include<bits/stdc++.h>
using namespace std;

int coinCount(int n, int coins[], int sum){
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    int res = coinCount(n-1, coins, sum);
    if(coins[n-1]<=sum){
        res += coinCount(n, coins, sum-coins[n-1]);
    }
    return res;
}

int main(){
    int n = 4;
    int coins[] = {2,5,3,6}, sum=10;
    cout<<"Count of coins : "<<coinCount(n, coins, sum);
}