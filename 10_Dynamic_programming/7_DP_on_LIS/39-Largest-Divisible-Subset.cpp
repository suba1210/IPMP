class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // initially sort the array
        vector<int> dp(nums.size(), 1);       
        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev] == 0 && (1 + dp[prev]) > dp[i]){ // only this line is different form LIS
                    dp[i] = 1 + dp[prev];
                }
            }
        }
        return maxi;
    }
};
