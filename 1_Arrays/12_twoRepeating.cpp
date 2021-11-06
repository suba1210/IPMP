//this is the best approach.. see other approaches also

#include<bits/stdc++.h>
using namespace std;

void printRepeating(int arr[],int n)
{
    int i,xorbit=0,setBit,x=0,y=0;

    for(i=1;i<=(n-2);i++)
    {
        xorbit = xorbit^i;
    }

    for(i=0;i<n;i++)
    {
        xorbit = xorbit^arr[i];
    }

    setBit = xorbit & ~(xorbit-1);

    for(i=0;i<n;i++)
    {
        if(setBit & arr[i])
            x = x^arr[i];
        else
            y=y^arr[i];        
    }

    for(i=1;i<=(n-2);i++)
    {
        if(setBit & i)
            x = x^i;
        else
            y=y^i; 
    }

    cout<<x<<" "<<y;
}

int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    printRepeating(arr, arr_size); 
    return 0; 
}