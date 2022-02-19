#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int start, int end, int key){

    while(start<=end){

        int mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            end = mid+1;
        }
        else if(arr[mid]>key){
            start = mid-1;
        }

    }
    return -1;
}

int findPos(int arr[], int key){

    if(arr[0]==key)
        return 0;
    
    int i=1;

    while(arr[i]<key)
    {
        i = i*2;
    }

    if(arr[i]==key)
        return i;
    
    return binary_search(arr,i/2+1,i-1,key);
}

int main(){
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170};
    int ans = findPos(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}