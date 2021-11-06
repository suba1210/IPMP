#include<bits/stdc++.h>
using namespace std;

int bitonic(int arr[],int n)
{
    int i, inc[n], dec[n];
    inc[0]=1,dec[n-1]=1;

    for(i=1;i<n;i++)
    {
        inc[i] = (arr[i]>=arr[i-1])?inc[i-1]+1:1;
    }

    for(i=n-2;i>=0;i--)
    {
        dec[i] = (arr[i]>=arr[i+1])?dec[i+1]+1:1;
    }

    int maxi = inc[0]+dec[0]-1;

    for(i=0;i<n;i++)
    {
        maxi = max(maxi,inc[i]+dec[i]-1);
    }

    return maxi;

}

int main()
{
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "nLength of max length Bitonic Subarray is " << bitonic(arr, n);
    return 0;    
}