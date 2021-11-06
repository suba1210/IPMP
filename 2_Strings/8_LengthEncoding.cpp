#include<bits/stdc++.h>
using namespace std;

void printRLE(string str)
{
    string dest = "";
    int i,n=str.length(),count=1;
    dest+=str[0];

    for(i=1;i<n;i++)
    {
        if(str[i]==str[i-1])
        {
            count++;
        }
        else{
            dest+=to_string(count);
            dest+=str[i];
            count=1;
        }
    }
    dest+=to_string(count);

    cout<<dest;
}

int main()
{
    string str = "wwwwaaadexxxxxxywww";
    printRLE(str);
    return 0;    
}