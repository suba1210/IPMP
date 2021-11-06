#include<bits/stdc++.h>
using namespace std;

bool areAnagram(string str1,string str2)
{
    int count[256]={0},i;

    for(i=0;i<str1.length();i++)
    {
        count[str1[i]]++;
    }
    for(i=0;i<str2.length();i++)
    {
        count[str2[i]]--;
    }

    for(i=0;i<256;i++)
    {
        if(count[i]!=0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str1 = "geeksforgeeks";
    string str2 = "forgeeks";
   

    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each other";
 
    return 0;    
}