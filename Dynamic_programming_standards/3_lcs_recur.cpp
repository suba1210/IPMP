#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int ns1, int ns2){
    if(ns1==0 || ns2==0){
        return 0;
    }
    else if(s1[ns1-1]==s2[ns2-1]){
        return 1 + lcs(s1,s2,ns1-1,ns2-1);
    }
    else{
        return max(lcs(s1,s2,ns1-1,ns2), lcs(s1,s2,ns1,ns2-1));
    }
}


int main(){
    string s1="abcdgh", s2="aedfhr";
    int ns1 = s1.length();
    int ns2 = s2.length();

    cout<<lcs(s1,s2,ns1,ns2);
}
