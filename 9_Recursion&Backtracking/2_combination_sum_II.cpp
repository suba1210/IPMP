class Solution {
public:
    void findCombinations(int index, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int> >& ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && (candidates[i-1]==candidates[i])){
                continue;
            }
            if(target<candidates[i]){
                break; // arr is sorted, so if arr[i] is greater, then all elements from a[i+1] should be greater, so return false
            }
            ds.push_back(candidates[i]);
            findCombinations(i+1, candidates, target-candidates[i], ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sorting is done to prevent duplicates
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ds, ans);
        return ans;
    }
};