#include<bits/stdc++.h>
using namespace std;

void printLeaders(int arr[],int n)
{
    int maxFromRight = arr[n-1],i;
    cout<<maxFromRight<<" "; // last element is always a leader
    for(i=n-2;i>=0;i--)
    {
        if(maxFromRight<arr[i])
        {
            maxFromRight = arr[i];
            cout<<maxFromRight<<" ";
        }
    }
}

int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}