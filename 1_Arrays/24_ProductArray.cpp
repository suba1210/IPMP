#include<bits/stdc++.h>
using namespace std;


void productArray(int arr[], int n)
{
    if(n==1)
    {
        cout<<"0";
        return;
    }
    int product[n],i,temp=1;

    memset(product,1,n);


    // in this loop, temp array keeps track of previous sum
    for(i=0;i<n;i++)
    {
        product[i] = temp;
        temp *= arr[i];
    }
    temp=1;

    // in this loop, temp keeps track of prev sum
    for(i=n-1;i>=0;i--)
    {
        product[i] *= temp;
        temp *= arr[i]; 
    }

    for(i=0;i<n;i++)
    {
        cout<<product[i]<<" ";
    }
}

int main()
{
    int arr[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    productArray(arr, n);
}