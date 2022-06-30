// refer notes for printing LIS

// recursion
class Solution {
public:
    int findAllLis(int index, int prev, vector<int>& arr){
        if(index==arr.size())
            return 0;
        int len = findAllLis(index+1, prev, arr); // not take 
        if(prev == -1 || arr[index] > arr[prev]){
            len = max(len, 1 + findAllLis(index+1, index, arr)); // take
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return findAllLis(0, -1, nums);
    }
};

// memoisation
class Solution {
public:
    int findAllLis(int index, int prev, vector<int>& arr, vector<vector<int>>& dp){
        if(index==arr.size())
            return 0;
        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];
        int len = findAllLis(index+1, prev, arr, dp); // not take 
        if(prev == -1 || arr[index] > arr[prev]){
            len = max(len, 1 + findAllLis(index+1, index, arr, dp)); // take
        }
        return dp[index][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return findAllLis(0, -1, nums, dp);
    }
};

// tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));       
        for(int index=nums.size()-1;index>=0;index--){
            for(int prev=index-1;prev>=-1;prev--){
                int len = dp[index+1][prev+1]; // not take 
                if(prev == -1 || nums[index] > nums[prev]){
                    len = max(len, 1 + dp[index+1][index+1]); // take
                }
                dp[index][prev+1] = len;                
            }
        }
        return dp[0][0];
        
    }
};

// space optimisation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> next(nums.size()+1, 0), curr(nums.size()+1, 0);       
        for(int index=nums.size()-1;index>=0;index--){
            for(int prev=index-1;prev>=-1;prev--){
                int len = next[prev+1]; // not take 
                if(prev == -1 || nums[index] > nums[prev]){
                    len = max(len, 1 + next[index+1]); // take
                }
                curr[prev+1] = len;                
            }
            next = curr;
        }
        return next[0];
        
    }
};

// another way of tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);       
        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i] && (1 + dp[prev]) > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
        }
        return maxi;
    }
};
