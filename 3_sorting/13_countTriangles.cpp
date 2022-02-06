#include<bits/stdc++.h>
using namespace std;

int findNumberOfTriangles(int arr[], int size){
    int count=0;
    int n = size;
    sort(arr, arr+n);
    for( int i=n-1; i>=2; i--){
        int l=0, r=i-1;
        while(r>l){
            if(arr[l]+arr[r] > arr[i])
            {
                count+=(r-l);
                r--;
            }
            else{
                l++;
            }
        }
    }
    return count;
}

int zeroTriplets(int arr[], int size){
    int count=0;
    int n=size;
    sort(arr, arr+n);
    for(int i=n-1;i>=2;i--){
        int l=0, r=i-1;
        while(r>l){
            if(arr[l]+arr[r]+arr[i] ==0){
                count++;
                l++;
                r--;
            }
            else if(arr[l]+arr[r]+arr[i] < 0){
                l++;
            }
            else{
                r--;
            }
        }
    }
    return count;
}

int main(){
    int arr[] = {0, -1, 2, -3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
 
    //cout<<"Total number of triangles possible is "<<findNumberOfTriangles(arr, size)<<'\n';
    cout<<"Total number of zero triplet "<<zeroTriplets(arr, size);
    return 0;    
}