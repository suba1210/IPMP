/*
Here we have to handle -ve values alos that's why, we are following such a 
complicated approach


It can also be solevd by using two pointer approach as : 
1) Sort all the elements of the input array. 
2) Use two index variables l and r to traverse from left and right ends respectively. 
Initialize l as 0 and r as n-1. 
3) sum = a[l] + a[r] 
4) If sum is -ve, then l++ 
5) If sum is +ve, then r– 
6) Keep track of abs min sum. 
7) Repeat steps 3, 4, 5 and 6 while l < r

Used Approach:
1) Sort all the elements of the input array using their absolute values. 
2) Check absolute sum of arr[i-1] and arr[i] if their absolute sum is 
less than min update min with their absolute value. 
3) Use two separate variables to store the index of the elements.
*/

#include<bits/stdc++.h>
using namespace std;

bool compare(int x, int y)
{
    return abs(x) < abs(y);
}

void minAbsSumPair(int arr[],int n)
{
    sort(arr,arr+n,compare);

    int i,min=INT_MAX,x,y;
    for(i=1;i<n;i++)
    {
        if(abs(arr[i-1]+arr[i])<min)
        {
            min = abs(arr[i]+arr[i-1]);
            x = i-1;
            y=i;
        }
    }

    cout<<arr[x]<<" "<<arr[y];

}

int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    minAbsSumPair(arr, n); 
    return 0;    
}