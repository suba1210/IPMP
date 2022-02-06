#include<bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int n){
    int i, j ,gap;

    for(gap = n/2;gap>=1;gap/=2){
        for(j=gap;j<n;j++){
            for(i=j-gap;i>=0;i-=gap){
                if(arr[i+gap]>arr[i])
                    break;
                else
                    swap(arr[i+gap], arr[i]);
            }
        }
    }
}

int main(){
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, n);
 
    cout << "After sort : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}