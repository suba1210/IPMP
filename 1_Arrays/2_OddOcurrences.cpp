/* brute force : 
1.finding the frequency array of elememts 
2. finding number which occurs odd in it */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,i,res=0;
    cin>>n1;
    int arr1[n1];
    for(i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }

    for(i=0;i<n1;i++)
    {
        res = res^arr1[i];
    }

    cout<<"The result is : "<<res;

}

//Time complexity : O(n)
//Space complexity : O(1)