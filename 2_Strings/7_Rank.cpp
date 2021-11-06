#include<bits/stdc++.h>
using namespace std;

int findRank(string str)
{
    int n = str.length(),rank=0,j;
    int i,fr[256]={0},fact[n];

    for(i=0;i<n;i++)
    {
        fr[str[i]]++;
    }

    fact[0]=1;

    for(i=1;i<n;i++)
    {
        fact[i]=i*fact[i-1];
    }

    
    for(i=0;i<n;i++)
    {
        int countSmallers = 0;
        for(j=0;j<256;j++)
        {
            if(j==str[i])
                break;
            else if(fr[j])
            {
                countSmallers++;
            }
        }
        fr[str[i]]=0;
        rank += countSmallers*fact[n-1-i];

    }

    return rank+1;

}

int main()
{
    string str = "secret";
    cout << findRank(str);
    return 0;    
}