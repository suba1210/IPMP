#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right){
    int leftSize = mid-left+1, rightSize = right-mid;
    int leftPart[leftSize], rightPart[rightSize];

    for(int i=0; i<leftSize; i++){
        leftPart[i] = a[left+i];
    }
    for(int i=0; i<rightSize; i++){
        rightPart[i] = a[mid+1+i];
    }
    int i=0, j=0, k=left;
    while(i<leftSize && j<rightSize){
        if(leftPart[i] < rightPart[j]){
            a[k++] = leftPart[i++];
        } else {
            a[k++] = rightPart[j++];
        }
    }
    while(i<leftSize){
        a[k++] = leftPart[i++];
    }
    while(j<rightSize){
        a[k++] = rightPart[j++];
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
    int a[]={10,5,30,15,7};
    int size = sizeof(a)/sizeof(a[0]);
	int l=0,r=size-1;
	
	mergeSort(a,l,r);
	for(int x: a)
	    cout<<x<<" ";    
}