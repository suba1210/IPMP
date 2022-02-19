// => very obvious approach : check if mid is a fixed point, 
//                           if not => compare it with its index and proceed with binary search

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end){
    while(start<=end){
        int mid = (start+end)/2;

        if(mid==arr[mid]){
            return arr[mid];
        }
        else if(mid < arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[10] = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Fixed Point is " << binarySearch(arr, 0, n - 1);
    return 0;
}