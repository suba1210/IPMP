/*
approach 1 : sorting
approach 2 : maintain 3 count variables by running a loop and 
run another loop and fill the array respectively
appraoch 3 : 

Algorithm: 
Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low 
(the range containing 0), low to mid (the range containing 1), mid to high 
(the range containing unknown elements) and high to N (the range containing 2).

Traverse the array from start to end and mid is less than high. (Loop counter is i)

If the element is 0 then swap the element with the element at index low and update 
low = low + 1 and mid = mid + 1

If the element is 1 then update mid = mid + 1

If the element is 2 then swap the element with the element at index high and update 
high = high – 1 and update i = i – 1. As the swapped element is not processed
Print the output array.

*/

#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n)
{
    int left=0,mid=0,right=n-1,i;

    while(mid<=right)
    {
        if(arr[mid]==0)
            swap(arr[left++],arr[mid++]);
        else if(arr[mid]==1)
            mid++;
        else if(arr[mid]==2)
            swap(arr[mid],arr[right--]);
    
    }
}

int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sort012(arr, n);
 
    cout << "array after segregation ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}