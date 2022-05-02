// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> s;
        long long i=0, top, area, max_area = 0;

        while(i<n){
            if(s.empty() || arr[s.top()]<=arr[i]){
                s.push(i++);
            }
            else{
                top = s.top();
                s.pop();
            }
        }
    }
};


// { Driver Code Starts.

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
  // } Driver Code Ends