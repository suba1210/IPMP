#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right){

    vector<int> leftArray, rightArray;

    for(int i=left; i<=mid; i++){
        leftArray.push_back(arr[i]);
    }

    for(int i=mid+1; i<=right; i++){
        rightArray.push_back(arr[i]);
    }

    int leftSize = leftArray.size(), rightSize = rightArray.size();
    int i=0, j=0, index=left;

    while(i<leftSize && j<rightSize){
        if(leftArray[i] < rightArray[j]){
            arr[index++] = leftArray[i++];
        } else {
            arr[index++] = rightArray[j++];
        }
    }

    while(i<leftSize){
        arr[index++] = leftArray[i++];
    }

    while(j<rightSize){
        arr[index++] = rightArray[j++];
    }

}

void mergeSort(int a[], int left, int right){
    if(left >= right)
        return;
    int mid = (left + right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, left, mid, right);
}

int main(){
    int a[]={10, 3, 1, 9, 15, 5};
    int size = sizeof(a)/sizeof(a[0]);
	int l=0,r=size-1;
	
	mergeSort(a,l,r);
	for(int x: a)
	    cout<<x<<" ";    
}