#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[],int n)
{
    int curr = arr[0],res=arr[0],i;

    for(i=0;i<n;i++)
    {
        curr = max(arr[i],curr+arr[i]);
        res = max(res,curr);
    }
    return res;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}