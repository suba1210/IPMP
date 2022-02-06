#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n)
{
    int max=arr[0];
    int min=arr[0];
    int b[n];
    for(int i=0;i<n;i++)
    {
        if(arr[i]> max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    int count[max]={0};
    for(int i=0;i<n;i++)
    {
        ++count[arr[i]];
    }
    for(int i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=0;i<n;i++)
    {
        b[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
       arr[i]=b[i];
    }
}

int main(){
    int arr[] = { 1,4,4,1,0,1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    countSort(arr, n );   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";       
    return 0;   
}