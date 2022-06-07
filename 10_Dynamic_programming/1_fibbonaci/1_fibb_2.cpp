#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=8; // find 8th fibonacci number
    int table[n+1];
    table[0]=0, table[1]=1;

    for(int i=2;i<=n;i++){
        table[i]=table[i-1]+table[i-2];
    }

    cout<<table[n];

}