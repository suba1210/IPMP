class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr+n);
        
        long long cost = 0;
        
        while(pq.size() > 1){
            long long rope1 = pq.top();
            pq.pop();
            long long rope2 = pq.top();
            pq.pop();
            cost += rope1 + rope2;
            pq.push(rope1 + rope2);
        }
        
        return cost;
    }
};