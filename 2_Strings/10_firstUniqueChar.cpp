#include<bits/stdc++.h>
using namespace std;

int firstNonRepeating(string str)
{
    int i,n=str.length(),res,index;
    int fr[26]={0};

    for(i=0;i<n;i++)
    {
        index=str[i]-'a';
        fr[index]++;
    }

    for(i=0;i<n;i++)
    {
        index=str[i]-'a';
        if(fr[index]==1)
        {
            res = i;
            break;
        }
    }

    return res;
}

int main(){
    string str;
    str = "geeksforgeeks";
    int firstIndex = firstNonRepeating(str);
    if (firstIndex == -1)
        cout<<"Either all characters are repeating or string is empty";
    else
        cout<<"First non-repeating character is "<< str[firstIndex];
    return 0;
}