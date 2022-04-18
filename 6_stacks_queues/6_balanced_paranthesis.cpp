#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}


bool valid(string s)
{
    if(s.length()==0 || s.length()==1){
        return true;
    }
    stack<int> stk;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stk.push(s[i]);
        }
        else{
            if(stk.empty()){
                return false;
            }
            else{
                if(stk.top()=='(' && s[i]==')'){
                    stk.pop();
                }
                else if(stk.top()=='[' && s[i]==']'){
                    stk.pop();
                }
                else if(stk.top()=='{' && s[i]=='}'){
                    stk.pop();
                }                
            }
            
        }
    }
    if(!stk.empty()){
        return false;
    }
    return true;
}