#include<bits/stdc++.h>
using namespace std;

void printDups(string str)
{
    int i;
    map<char,int> m;

    for(i=0;i<str.length();i++)
    {
        if(str[i]!=' ')
            m[str[i]]++;
    }

    cout<<"Duplicates : "<<endl;

    for(auto& x: m)
    {
        cout<<x.first<<" - "<<x.second<<'\n';
    }
}

int main()
{
    string str = "test string";
    printDups(str);
    return 0;    
}