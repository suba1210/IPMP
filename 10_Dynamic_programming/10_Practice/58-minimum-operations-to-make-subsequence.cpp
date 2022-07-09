class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> umap;
        
        for(int i=0; i<target.size(); i++){
            umap[target[i]] = i;
        }
        
        vector<int> temp;
        for(int i=0; i<arr.size(); i++){
            if(umap.find(arr[i])==umap.end())
                continue;
            int ind = lower_bound(temp.begin(), temp.end(), umap[arr[i]]) - temp.begin();
            if(ind == temp.size())
                temp.push_back(umap[arr[i]]);
            else
                temp[ind] = umap[arr[i]];
        }
        return target.size() - temp.size(); 
    }
};