#include<bits/stdc++.h>
using namespace std;
int memo[1000][1000];

int lcs(string s1, string s2, int ns1, int ns2){
    memo[0][0] = 0;
    int i,j;
    for(i=0;i<=ns1;i++){
        memo[i][0] = 0;
    }
    for(i=0;i<=ns2;i++){
        memo[0][i] = 0;
    }

    for(i=1;i<=ns1;i++){
        for(j=1;j<=ns2;j++){
            if(s1[i-1]==s2[j-1]){
                memo[i][j] = 1 + memo[i-1][j-1];
            }
            else{
                memo[i][j] = max(memo[i][j-1],memo[i-1][j]);
            }
        }
    }

    return memo[ns1][ns2];
}

int main(){
    string s1="AXYZ", s2="BAZ";
    int ns1 = s1.length();
    int ns2 = s2.length();

    memset(memo, -1, sizeof(memo));

    cout<<lcs(s1,s2,ns1,ns2);
}