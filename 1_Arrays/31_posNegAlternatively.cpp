#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[],int n)
{
    int i,left=-1;

    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            left++;
            swap(arr[i],arr[left]);
        }
    }

    int pos = left+1,neg=0;

    while(pos<n && neg<pos && arr[neg]<0)
    {
        swap(arr[neg],arr[pos]);
        neg+=2;
        pos++;
    }

    return;
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9},i;
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;    
}