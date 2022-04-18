// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> kv;  // key -> (value, pointer to key_recency position)
    list<int> key_recency; // list from least recent to most recent keys.
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    // make key last (most recent) in recency list.
    void make_recent(int key){
        if (kv.count(key)){
            key_recency.erase(kv[key].second);
        }
        key_recency.push_back(key);
        kv[key] = {kv[key].first, --key_recency.end()};
    }
    
    int get(int key) {
        if (!kv.count(key)) return -1;
        make_recent(key);
        return kv[key].first;
    }
    
    void set(int key, int value) {
       
        if (kv.size() == cap && !kv.count(key)){
            kv.erase(*key_recency.begin());
            key_recency.pop_front();
        }
        
        make_recent(key);
        kv[key].first = value;
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