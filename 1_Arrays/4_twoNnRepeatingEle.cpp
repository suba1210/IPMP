/* Approach 1 : 
Sort the array, and look for the adjacent elements to be same, if not they are the 
non repeating elements

Approach 2 : 
use maps, store frequency in maps and find the non repeating elements
*/

#include<bits/stdc++.h>
using namespace std;

void get2NonRepeatingNos(int arr[], int n)
{
    map<int,int> m;
    int i;

    for(i=0;i<n;i++)
    {
        m[arr[i]]++;
    }

    for(auto& x : m)
    {
        if(x.second==1)
        {
            cout<<x.first<<" ";
        }
    }

}

int main()
{
    int arr[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    get2NonRepeatingNos(arr, n);
}