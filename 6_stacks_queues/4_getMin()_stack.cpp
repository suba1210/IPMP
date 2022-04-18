#include <bits/stdc++.h>
using namespace std;

class Solution{
    int minEle;
    stack<int> s;
    public:
       int getMin(){
           if(s.empty()){
             return -1;
           }
           else{
             return minEle;
           }
       }
       
       int pop(){
           if(s.empty()){
                return -1;
            }
            int t = s.top();
            s.pop();
            if(t<minEle)
            {
                int k = minEle;
                minEle = 2*minEle-t;
                return k;
            }
            else{
                return t;
            }
       }
       
       void push(int x){
           if(s.empty())
           {
             minEle =x ;
             s.push(x);
             return ;
            }
            if(x<minEle)
            {
                s.push(2*x-minEle);
                minEle = x;
            }
            else{
                s.push(x);
            }
       }
};


int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
