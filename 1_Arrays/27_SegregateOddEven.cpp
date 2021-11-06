#include<bits/stdc++.h>
using namespace std;

//stable partition

void stablePartition(vector<int> v,int n)
{
    stable_partition(v.begin(),v.end(),[](auto a){return a%2==0;});

    for(auto x : v)
    {
        cout<<x<<" ";
    }
}

//lumunto partition => but this partition is not stable

void rearrangeEvenAndOdd(vector<int> arr, int n)
{
    int i,j=-1;

    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            j++;
            swap(arr[i],arr[j]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; 

    cout<<endl;
}

int main()
{
    vector<int> v{ 12, 10, 9, 45, 2, 10, 10, 45 };
    int n = v.size();
 
    rearrangeEvenAndOdd(v, n);

    stablePartition(v,n);
  
}