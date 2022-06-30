#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int left, int mid, int right){
    int leftSize = mid-left+1, rightSize = right-mid;
    int leftPart[leftSize], rightPart[rightSize];

    for(int i=0; i<leftSize; i++){
        leftPart[i] = a[left+i];
    }
    for(int i=0; i<rightSize; i++){
        rightPart[i] = a[mid+1+i];
    }
    int i=0, j=0, k=left, count=0;
    while(i<leftSize && j<rightSize){
        if(leftPart[i] <= rightPart[j]){
            a[k++] = leftPart[i++];
        } else {
            a[k++] = rightPart[j++];
            count += leftSize - i; // this implies all the elements from i to the end of the array
        }
    }
    while(i<leftSize){
        a[k++] = leftPart[i++];
    }
    while(j<rightSize){
        a[k++] = rightPart[j++];
    }

    return count;

}

int mergeSort(int a[], int left, int right){
    int count = 0;
    if(left >= right)
        return count;
    int mid = (left + right)/2;
    count += mergeSort(a, left, mid);
    count += mergeSort(a, mid+1, right);
    count += merge(a, left, mid, right);
    return count;
}

int main(){
    int a[]={2,4,1,3,5};
    int size = sizeof(a)/sizeof(a[0]);
	int l=0,r=size-1;
	
	cout<<mergeSort(a,l,r);

}