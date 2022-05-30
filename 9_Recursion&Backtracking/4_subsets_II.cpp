class Solution {
public:
    void findSubsets(vector<int>& nums,  vector<vector<int>>& result, vector<int>& ds, int index){
        result.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i] == nums[i-1])
                continue;
            ds.push_back(nums[i]);
            findSubsets(nums, result, ds, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> ds;
        findSubsets(nums, result, ds, 0);
        return result;
    }
};