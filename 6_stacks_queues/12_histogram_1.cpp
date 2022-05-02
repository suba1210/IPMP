/*
Approach:

1. area = (area of the bar)*(smallest in the right - smallest on the left -1 )

smallest on the right => found while traversing through the array
smallest on the left => stored in the stack top
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    long long getMaxArea(long long arr[], int n)
    {
        long long max_area = 0, i=0, tp, area;
        stack<long long> stk;
        
        while(i<n){
            if(stk.empty() || arr[stk.top()] <= arr[i] ){
                stk.push(i++);
            }
            else{
                tp = stk.top();
                stk.pop();
                area = arr[tp]*(stk.empty() ? i : (i - stk.top() - 1));
                max_area = max(area, max_area);
            }
        }
        
        while(!stk.empty()){
                tp = stk.top();
                stk.pop();
                area = arr[tp]*(stk.empty() ? i : (i - stk.top() - 1));
                max_area = max(area, max_area);           
        }
        
        return max_area;
    }
    
};

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}