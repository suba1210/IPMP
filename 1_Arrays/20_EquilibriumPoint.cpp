/*
approach 1 : brute force
apprach 2 : maintain prefix and suffix sum arrays, the index at which the prefix sum 
equals to suffix sum, then that is an equilibrium point ( space inefficient )
approach 3 : (coded)
1) Initialize leftsum  as 0
2) Get the total sum of the array as sum
3) Iterate through the array and for each index i, do following.
    a)  Update sum to get the right sum.  
        sum = sum - arr[i] 
       // sum is now right sum
    b) If leftsum is equal to sum, then return current index. 
       // update leftsum for next iteration.
    c) leftsum = leftsum + arr[i]
4) return -1 
*/

#include<bits/stdc++.h>
using namespace std;

int equilibriumPoints(int arr[],int n)
{
    int i,sum=0,leftsum = 0;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    int tempSum = sum;

    for(i=0;i<n;i++)
    {
        tempSum -= arr[i];
        if(tempSum==leftsum)
        {
            return i;
        }
        leftsum += arr[i];
    }
    return -1;
}



int main()
{
    int arr[] = { -7, 1, 5, 2, -4, 3, -3 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    cout << "First Point of equilibrium is at index "<<equilibriumPoints(arr, arr_size); 
    return 0; 
}