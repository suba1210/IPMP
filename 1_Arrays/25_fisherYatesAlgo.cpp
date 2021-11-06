#include<bits/stdc++.h>
using namespace std;

void  randomize(int arr[], int n)
{
    int i,j;
    srand(time(NULL)); // this gives more shuffling

    for(i=0;i<n-1;i++)
    {
        j = rand()%(i+1);
        swap(arr[i],arr[j]);
    }

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    randomize (arr, n);
    return 0;    
}