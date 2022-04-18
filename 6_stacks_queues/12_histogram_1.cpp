// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> prev(n), suff(n);
        stack<long long> prevStk, suffStk;
        
        for(int i=0;i<n;i++){
            while(!prevStk.empty() && arr[prevStk.top()]>=arr[i]){
                prevStk.pop();
            }
            if(prevStk.empty()){
                prev[i]=i;
            }
            else{
                prev[i]=i-prevStk.top()-1;
            }
            prevStk.push(i);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!suffStk.empty() && arr[suffStk.top()]>=arr[i]){
                suffStk.pop();
            }
            if(suffStk.empty()){
                suff[i]=n-i-1;
            }
            else{
                suff[i]=suffStk.top()-i-1;
            }
            suffStk.push(i);
        }
        
        long long maxi = (prev[0]+suff[0]+1)*arr[0], area;
        
        for(int i=1;i<n;i++){
            area = (prev[i]+suff[i]+1)*arr[i];
            if(area>maxi){
                maxi = area;
            }
        }
        
        return maxi;

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