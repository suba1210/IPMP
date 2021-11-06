#include<bits/stdc++.h>
using namespace std;

void findSubArray(int arr[], int n)
{
    int i,currentSum=0,longest_length=0;
    map<int,int> mymap;

    for(i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            currentSum+=-1;
        }
        else{
            currentSum+=1;
        }

        if(currentSum==0)
        {
            longest_length=i+1;
        }
        else if(mymap.find(currentSum)!=mymap.end())
        {
            if(longest_length<(i-mymap[currentSum]))
            {
                longest_length=i-mymap[currentSum];
            }
        }
        else{
            mymap[currentSum]=i;
        }
    }

    cout<<"Longest subarray with 0s and 1s : "<<longest_length;

}

int main()
{
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
 
    findSubArray(arr, size);
    return 0;    
}