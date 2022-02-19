#include<bits/stdc++.h>
using namespace std;

int findMajority(int arr[], int n){
    int res=0, count=1,i;

    for(i=1;i<n;i++){
        if(arr[res]==arr[i])
            count++;
        else
            count--;
        if(count==0)
        {
            res=i;
            count=1;
        }
    }

    return arr[res];

    
}

int main(){
    int arr[] = { 1, 2, 2, 2, 2, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int majority = findMajority(arr, n);
    cout << " The majority element is : " << majority;
    return 0;   
}