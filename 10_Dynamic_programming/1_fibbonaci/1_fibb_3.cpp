// space optimisation
// dp[i] needs prev and prevofprev, so don't need to store 
// array, just store these two variables

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=8;
    int prev1 = 1, prev2 = 0, result;

    for(int i=2;i<=n;i++){
        result = prev1 + prev2;
        prev2 = prev1;
        prev1 = result;
    }
    cout<<prev1;
}