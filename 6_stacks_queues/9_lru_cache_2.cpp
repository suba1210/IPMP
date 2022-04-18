// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    int capacity;
    unordered_map<int,int> data;
    list<int> dataList;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->capacity = cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(data.find(key)!=data.end()){
            dataList.remove(key);
            dataList.push_back(key);           
            return data[key];
        }
        return -1;
    }
    
    //Function for storing key-value pair. 
    void set(int key, int value)
    {
        if(data.find(key)!=data.end()){
            data.erase(key);
            dataList.remove(key);
        }
        if(data.size()==capacity){
            int lru = dataList.front();
            data.erase(lru);
            dataList.pop_front();
        }
        dataList.push_back(key);
        data[key]=value;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
