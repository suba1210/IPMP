#include<bits/stdc++.h>
using namespace std;

int myAtoi( string str)
{
    int i=0,sign=1,res=0,n=str.length();
    if(str[0]=='-')
    {
        sign=-1;
        i++;
    }

    for(;i<n;i++)
    {
        res=(10*res)+(str[i]-'0');
    }

    return (sign*res);
}

int main()
{
    char str[] = "-123";
    int val = myAtoi(str);
    cout << val;
    return 0;    
}