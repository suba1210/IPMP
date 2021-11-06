#include<bits/stdc++.h>
using namespace std;

void moveAll0sToEnd(int arr[], int n)
{
    int right=n-1,i;

    for(i=0;i<right;i++)
    {
        while(arr[i]==0)
        {
            swap(arr[i],arr[right--]);
        }
    }
    return;
}

int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    moveAll0sToEnd(arr, n);
 
    cout << "array after segregation ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}