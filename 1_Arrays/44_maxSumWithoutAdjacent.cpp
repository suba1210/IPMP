#include<bits/stdc++.h>
using namespace std;

int FindMaxSum(vector<int> arr,int n)
{
    int incl=arr[0],excl=0,i,exclNew;

    for(i=0;i<n;i++)
    {
        exclNew=max(incl,excl);
        incl = excl+arr[i];
        excl = exclNew;
    }

    return max(incl,excl);
}

int main()
{
    vector<int> arr = {5, 5, 10, -100, 10, 5};
    cout<<FindMaxSum(arr, arr.size());    
}