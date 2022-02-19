// Approach:
// 1) Find middle point mid = (l + h)/2
// 2) If key is present at middle point, return mid.
// 3) Else If arr[l..mid] is sorted
//     a) If key to be searched lies in range from arr[l]
//        to arr[mid], recur for arr[l..mid].
//     b) Else recur for arr[mid+1..h]
// 4) Else (arr[mid+1..h] must be sorted)
//     a) If key to be searched lies in range from arr[mid+1]
//        to arr[h], recur for arr[mid+1..h].
//     b) Else recur for arr[l..mid] 

#include<bits/stdc++.h>
using namespace std;

int pivotedBinarySearch(int arr[],  int start, int end, int key){
    
    if(start>end)
        return -1;

    int mid = (start+end)/2;

    if(arr[mid]==key)
        return mid;

    // if l to mid is sorted ?
    if(arr[start]<=arr[mid]){
        if(key>=arr[start] && key<=arr[mid]){
            return pivotedBinarySearch(arr,0,mid-1, key);
        }
        return pivotedBinarySearch(arr,mid+1,end,key);
    }

    // if mid to r is sorted ?
    else{
        if(key>=arr[mid] && key<=arr[end]){
            return pivotedBinarySearch(arr,mid+1,end,key);
        }
        return pivotedBinarySearch(arr,start, mid-1,key);
    }
    
}

int main(){
    int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;
    cout << "Index of the element is : "<< pivotedBinarySearch(arr1,0, n-1, key);
    return 0;    
}
