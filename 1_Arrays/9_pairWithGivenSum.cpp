#include<bits/stdc++.h>
using namespace std;

bool hasArrayTwoCandidates(int arr[],int size,int num)
{
    int i;
    sort(arr,arr+size);

    int l=0,r=size-1;

    while(l<r)
    {
        if(arr[l]+arr[r]==num)
            return true;
        else if((arr[l]+arr[r])<num)
            l++;
        else
            r--;
    }

    return false;

}

int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 200;
    int arr_size = sizeof(A) / sizeof(A[0]);
 
    if (hasArrayTwoCandidates(A, arr_size, n))
        cout << "Array has two elements with given sum";
    else
        cout << "Array doesn't have two elements with given sum";
 
    return 0;
}