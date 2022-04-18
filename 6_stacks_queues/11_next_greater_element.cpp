#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack<long long> st;
        st.push(arr[n-1]);
        vector<long long> ans(n);
        ans[n-1] = -1;
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        
        return ans;
        
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}