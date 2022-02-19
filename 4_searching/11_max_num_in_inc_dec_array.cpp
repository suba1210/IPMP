// Approach:
// i) If the mid element is greater than both of its adjacent elements, then mid is the maximum. 
// ii) If mid element is greater than its next element and smaller than the previous element then maximum lies on left side of mid. Example array: {3, 50, 10, 9, 7, 6} 
// iii) If mid element is smaller than its next element and greater than the previous element then maximum lies on right side of mid. Example array: {2, 4, 6, 8, 10, 3, 1} 

#include<bits/stdc++.h>
using namespace std;

int findMaximum(int arr[], int start, int end, int size){
    while(start<=end){
        int mid=(start+end)/2;
        if(mid==0 || mid==size-1)
            return arr[mid];
        else if(arr[mid]>arr[mid+1] && arr[mid-1]<arr[mid]){
            return arr[mid];
        }
        else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
            end = mid-1;
        }
        else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 50, 10, 9, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The maximum element is " << findMaximum(arr, 0, n-1, n);
    return 0;
}