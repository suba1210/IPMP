#include<bits/stdc++.h>
using namespace std;

int minDiff(int arr[], int n, int m){
    if(n<m)
        return -1; //edge cases
    sort(arr, arr+n);
    int res = arr[m-1] - arr[0];
    for(int i=1;i<n-m+1;i++)
    {
        res=min(res,(arr[i+m-1]-arr[i]));
    }
    return res;
}

int main(){
    int arr[]={7,3,2,4,9,12,56}; //packets
	int n=sizeof(arr)/sizeof(arr[0]);
    int m=3; //children
	cout<<minDiff(arr,n,m);
}