// more efficient method needed, as 
// this method does not handle the case when the string is 
// starting with ' '

#include <bits/stdc++.h>
using namespace std;
 
void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    int i=0;

    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
   
    tmp.push_back(str);
 
    int i;
    for (i = tmp.size() - 1; i > 0; i--)
        cout << tmp[i] << " ";
    cout << tmp[0] << endl;
}

int main()
{
    string s = "i like this program very much";
    reverseWords(s);
    return 0;
}