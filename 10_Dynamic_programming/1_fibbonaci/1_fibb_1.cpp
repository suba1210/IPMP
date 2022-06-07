// time complexity : O(n) => for every n, fibonacci call is called only once
// space complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& memo){
    if(n<=1){
        return n;
    }
    if(memo[n]!=-1){
        return memo[n];
    }
    return memo[n] = fib(n-1, memo) + fib(n-2, memo);
}

int main(){
	int n = 5;
    vector<int> memo(n+1,-1);
	cout<<fib(5, memo);
}