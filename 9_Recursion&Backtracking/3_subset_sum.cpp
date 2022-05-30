// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void findSubsets(vector<int>& arr, int N, vector<int>& result, int index, int sum){
        if(index>=N){
            result.push_back(sum);
            return;
        }
        // pick the element at index
        sum += arr[index];
        findSubsets(arr, N, result, index+1, sum);
        // not pick the element at index
        sum -= arr[index];
        findSubsets(arr, N, result, index+1, sum);

        // these 4 lines can be alternatively written as:
        // findSubsets(arr, N, result, index+1, sum+arr[index]); // pick condition 
        // findSubsets(arr, N, result, index+1, sum); // not pick condition
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> result;
        findSubsets(arr,N,result,0,0);
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends