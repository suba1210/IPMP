#include<bits/stdc++.h>
using namespace std;

int maxRepeating(int arr[],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        arr[arr[i]%k]+=k;
    }

    int maxi = arr[0],result_ind=0;

    for(i=0;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            maxi = arr[i];
            result_ind = i;
        }
    }

    // for(i=0;i<n;i++) to retrieve back the original array
    //     arr[i]=arr[i]%k;

    return result_ind;
}

int main()
{
    int arr[] = {2, 3, 3, 5, 3, 4, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;
 
    cout << "The maximum repeating number is " <<maxRepeating(arr, n, k) << endl;
 
    return 0;    
}