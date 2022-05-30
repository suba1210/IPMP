class Solution {
public:
    void findPermutes(vector<vector<int> >& ans, vector<int> nums, int index)
    {
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size();i++){
            swap(nums[index], nums[i]);
            findPermutes(ans, nums, index+1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        findPermutes(ans, nums, 0);
        return ans;
    }
};