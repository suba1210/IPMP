#include<bits/stdc++.h>
using namespace std;

void segregatePosNeg(int arr[], int n){
    int start=0, end=n-1;
    while(start<end){
        while(arr[start]<0)
            start++;
        while(arr[end]>=0)
            end--;
        if(start<end)
            swap(arr[start],arr[end]);
    }
}

int main(){
    int arr[]={13,-12,7,-3,5,-7,6,5,-2,18,-10,0};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	segregatePosNeg(arr,n);
	
	for(int x:arr)
	    cout<<x<<" ";   
}