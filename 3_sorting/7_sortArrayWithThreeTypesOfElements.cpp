#include<bits/stdc++.h>
using namespace std;

void segregate0s1s2s(int arr[], int n){
    int low=0, high=n-1, mid=0;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
            mid++;
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    	
    int arr[]={0,1,1,2,0,1,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	segregate0s1s2s(arr,n);
	for(int x:arr)
	    cout<<x<<" ";
}