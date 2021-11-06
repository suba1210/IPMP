#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a,pair<int,int>& b)
{
    return a.second < b.second;
}


void sortFunc(int arr[], int n)
{
    int i;
    map<int,int> m;

    for(i=0;i<n;i++)
    {
        m[arr[i]]++;
    }

    vector<pair<int,int> > v;

    for(auto& x : m)
    {
        v.push_back(x);
    }

    sort(v.begin(),v.end(),cmp);

    for(auto& x : v)
    {
        int temp= x.second;
        while(temp--)
            cout<<x.first<<" ";
    }

}

int main()
{
    int arr[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sortFunc(arr, n);
 
    return 0;   
}