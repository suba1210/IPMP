#include<bits/stdc++.h>
using namespace std;

int firstNonRepeating( string str)
{
    int len = str.length();

    if(len==0)
        return -1;
    else
    {
        int fr[256],i;

        for(i=0;i<256;i++)
            fr[i]=-1;

        for(i=0;i<256;i++)
        {
            if(fr[str[i]]==-1)
                fr[str[i]]=i;
            else{
                fr[str[i]]=-2;
            }
        }

        int res=INT_MAX;
        for(i=0;i<256;i++)
        {
            if(fr[i]>=0)
            {
                res=min(res,fr[i]);
            }
        }
        
        if(res==INT_MAX)
            return -1;
        else
            return res;
    }
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