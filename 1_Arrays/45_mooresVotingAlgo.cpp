/*
Lessons from moore's voting algorithm : 
1. this algorithm is designed in such a way that the majority element outweighs the frequency of
remaining elements in the array.
2. With that kept in mind, we can easily find the majority element
*/

#include<bits/stdc++.h>
using namespace std;

int findMajorityCandidate(int arr[],int n)
{
    int i,count=1,major_index=0;

    for(i=1;i<n;i++)
    {
        if(arr[i]==arr[major_index])
            count++;
        else
            count--;

        if(count==0)
        {
            major_index=i;
            count=1;
        }      
    }
    return arr[major_index];
}

void printMajority(int arr[], int n)
{
    int cand = findMajorityCandidate(arr,n),i,count=0;

    for(i=0;i<n;i++)
    {
        if(arr[i]==cand)
            count++;
    }

    if(count>n/2)
    {
        cout<<"Majority";
    }
    else{
        cout<<"Not Majority";
    }
}



int main()
{
    int a[] = {3,2,2,2,4,2};
    int size = (sizeof(a)) / sizeof(a[0]);
    printMajority(a, size);
    return 0;    
}