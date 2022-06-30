class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        for(int i=k;i<n;i++){
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
                
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};