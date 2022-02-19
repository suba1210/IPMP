// -> do binary search
// -> after finding that element, compare it with its previous and next element, 
//     and decide on the direction of binary search

#include<bits/stdc++.h>
using namespace std;

int first(int arr[], int x, int n){
    int low=0;
    int high=n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(x>arr[mid]){
            low=mid+1;
        }
        else if(x<arr[mid]){
            high=mid-1;
        }
        else{
            if(mid==0 || arr[mid-1]!=arr[mid])
                return mid;
            else
                high=mid-1;
        }
    }
    return -1;

}

int last(int arr[], int x, int n){
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(x>arr[mid]){
            low=mid+1;
        }
        else if(x<arr[mid]){
            high=mid-1;
        }
        else{
            if(mid==n-1 || arr[mid]!=arr[mid+1])
                return mid;
            else
                low=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
 
    int x = 2;
    cout <<"First Occurrence = " << first(arr, x, n);
    cout <<"\nLast Occurrence = "<< last(arr, x, n);
 
    return 0;
}