#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int lb, int ub){
    int pivot=arr[ub];
    int i =lb-1;
    for(int j=lb;j<=ub-1;j++){
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[ub], arr[i+1]);
    return i+1; 
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