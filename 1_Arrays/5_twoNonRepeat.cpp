/*
Approach 1 : 
sort, linear scan and print odd occuring elements

Approach2 : 
Hashing using hash maps

Approach 3 : 
by bitwise xor operation (refer notes) - Implemented it in code

Approach 4 : 
using maps to store value and their frequencies */

#include<bits/stdc++.h>
using namespace std;

void printTwoOdd(int arr[],int n)
{
    int i,xor_val=0,x1=0,x2=0; // don't forget to initialise x1 and x2 with 0

    for(i=0;i<n;i++)
    {
        xor_val = xor_val ^ arr[i];
    }

    int xor_another = (xor_val) & ~(xor_val-1);

    for(i=0;i<n;i++)
    {
        if(arr[i] & xor_another)
        {
            x1 = x1^arr[i];
        }
        else{
            x2 = x2^arr[i];
        }
    }

    cout<<x1<<" "<<x2<<endl;
}

int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printTwoOdd(arr, arr_size);
    return 0;
}