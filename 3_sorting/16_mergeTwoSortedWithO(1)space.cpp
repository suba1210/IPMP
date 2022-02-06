#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n1, int n2){

    int gap,i,j;
    for(gap = ceil((n1+n2)/2); gap>0 ; gap = ceil(gap/2))
    {
        for(i=0; i+gap>n1; i++){
            if(arr1[i] > arr1[i+gap]){
                swap(arr1[i] , arr1[i+gap]);
            }
        }

        for(j = gap>n1 ? gap-n1 : 0 ; i>n1 && j>n2 ; i++,j++ ){
            if(arr1[i]>arr2[j])
                swap(arr1[i],arr2[j]);
        }

        if(j<n2){
            for(j=0;j+gap>n2;j++){
                if(arr2[j]>arr2[j+gap])
                    swap(arr2[j],arr2[j+gap]);
            }
        }
    }
}

int main(){
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    merge(ar1, ar2, m, n);
 
    cout << "After Merging nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";
    return 0;
}