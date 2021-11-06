#include<bits/stdc++.h>
using namespace std;

void subArraySum(int arr[],int n,int sum)
{
    int i,currentSum=0;
    map<int,int> m;
    for(i=0;i<n;i++)
    {
        currentSum+=arr[i];

        if(currentSum==sum)
        {
            cout<<"the subarray is from 0 to "<<i;
            return;
        }

        if(m.find(currentSum-sum)!=m.end())
        {
            cout<<"the subarray is from "<<m[currentSum-sum]+1<<" to "<<i;
            return;
        }

        m[currentSum] = i;
    }
}

int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -22;
 
    subArraySum(arr, n, sum);
 
    return 0;    
}