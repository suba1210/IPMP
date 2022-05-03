// time complexity : O(n) => for every n, fibonacci call is called only once
// space complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& memo){
    if(memo[n]==-1){
        int res;
        if(n==0 || n==1){
            return n;
        }
        else{
            res = fib(n-1, memo)+fib(n-2, memo);
        }
        memo[n]=res;
    }
    return memo[n];
}

int main(){
	int n = 10;
    vector<int> memo(n+1,-1);
	cout<<fib(5, memo);
}