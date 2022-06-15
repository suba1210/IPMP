#include <bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    void insertHeap(int &x)
    {
        if(maxHeap.size() == 0 && minHeap.size() == 0){
            maxHeap.push(x);
            return;
        }
        
        if(maxHeap.size() > minHeap.size()){
            if(x < maxHeap.top()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
            }
        } else {
            if(x <= maxHeap.top() || x < minHeap.top()){
                maxHeap.push(x);
            }  else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
        }
        
    }
    
    double getMedian()
    {
        if(maxHeap.size() > minHeap.size()){
            return (double)maxHeap.top();
        } else {
            return ((double)((maxHeap.top() + minHeap.top())/2));
        }
    }
};


int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}