/*
Approach 1 : maintain a temperary array 
Approach 2 : rotate one by one
Approach 3 : Reversing approach


*/

#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int low,int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }

}

void rotateArray(int arr[],int n,int d)
{
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]),i;
    int d = 2;
    rotateArray(arr,n,d);
    cout<<"After Rotation : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;

}