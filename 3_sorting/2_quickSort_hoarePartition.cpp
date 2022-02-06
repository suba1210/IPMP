#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int lb, int ub){
    int pivot=arr[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub)
{
    if(lb<ub){
        int location=partition(arr, lb, ub);
        quickSort(arr, lb, location-1);
        quickSort(arr, location+1, ub);
    }
}

int main() {
	
    int a[]={10,56,30,15,7};
	int l=0,r=4;
	
	quickSort(a,l,r);
	for(int x: a)
	    cout<<x<<" ";
}