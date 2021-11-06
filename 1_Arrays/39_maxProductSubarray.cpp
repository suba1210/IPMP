/* mostly like kadane algo, but here extra min is maintained for cases like : 
multiplying minus with minus to get a positive value 
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(int arr[], int n)
{
    int maxEnding = arr[0],minEnding = arr[0],max_overall=arr[0],i;

    for(i=1;i<n;i++)
    {
        int tmp = maxEnding;
        maxEnding = max({arr[i],maxEnding*arr[i],minEnding*arr[i]});
        minEnding = min({arr[i],tmp*arr[i],minEnding*arr[i]});
        max_overall = max(max_overall,maxEnding);
    }

    return max_overall;
}

int main()
{
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "<<maxSubarrayProduct(arr, n);
    return 0;    
}