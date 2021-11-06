//approach 1 : use two pointer
//approach 2 : swapping if they are in wrong position



#include<bits/stdc++.h>
using namespace std;

void segregate0and1(int arr[], int n)
{
    int i,left=0,right=n-1;

    while(left<right)
    {
        if(arr[left]==1)
        {
            swap(arr[left],arr[right]);
            right--;
        }
        else
            left++;

    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1, 1};
    int i, arr_size = sizeof(arr)/sizeof(arr[0]);
 
    segregate0and1(arr, arr_size);  

    cout << "Array after segregation is ";
    for (i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
 
    return 0;  
}