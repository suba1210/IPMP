#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n){
    sort(arr,arr+n);
    sort(dep,dep+n);
    int arrPointer=0, depPointer=0, platforms=0, currentTime=arr[0], maxi=0;

    while(arrPointer<n && depPointer<n){
        if(arr[arrPointer]<=dep[depPointer]){
            platforms++;
            arrPointer++;
            maxi=max(platforms,maxi);
        }
        else{
            platforms--;
            depPointer++;
            maxi=max(platforms,maxi);
        }
    }

    return maxi;

}

int main(){
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "<< findPlatform(arr, dep, n);
    return 0;   
}