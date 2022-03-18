#include<bits/stdc++.h>
using namespace std;
int memo[1000][1000];

int lcs(string s1, string s2, int ns1, int ns2){
    if(memo[ns1][ns2]==-1){
        int res;
        if(ns1==0 || ns2==0){
            return 0;
        }
        else if(s1[ns1-1]==s2[ns2-1]){
            res = 1 + lcs(s1,s2,ns1-1,ns2-1);
        }
        else{
            res = max(lcs(s1,s2,ns1,ns2-1),lcs(s1,s2,ns1-1,ns2));
        }
        memo[ns1][ns2]=res;
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