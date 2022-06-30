class Solution {
public:
    void findPermutations(vector<int>& nums, vector<int>& ds, vector<vector<int>>& result, unordered_map<int, int> &um){
        if(ds.size()==nums.size()){
            result.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){ // it is not subset or subsequence finding problem, so that's why we started from 0 instead of some index
            if(!um[i]){
                um[i] = 1; // this map is used to check whether that index had been taken or not
                ds.push_back(nums[i]);
                findPermutations(nums, ds, result, um);
                ds.pop_back();
                um[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        unordered_map<int, int> um;
        findPermutations(nums, ds, result, um);
        return result;
    }
};
