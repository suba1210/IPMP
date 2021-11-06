#include<bits/stdc++.h>
using namespace std;

void reverse(string& str,int low,int high)
{
    if(low>=high)
        return;

    swap(str[low],str[high]);
    reverse(str,++low,--high); 
}


int main()
{
    string a = "subasri";
    int n = a.length();
    int low=0,high=n-1;
    reverse(a,low,high);
    cout<<a;
    return 0;
}