// recursion
class Solution {
public:
    int f(int i, int j, vector<int>& nums){
        if(i>j)
            return 0;
        int maxi = INT_MIN;
        for(int index = i;index<=j;index++){
            int cost = nums[i-1]*nums[index]*nums[j+1] + f(i,index-1,nums) + f(index+1, j, nums);
            maxi = max(maxi, cost);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return f(1,size,nums);
    }
};

// memoisation
class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi = INT_MIN;
        for(int index = i;index<=j;index++){
            int cost = nums[i-1]*nums[index]*nums[j+1] + f(i,index-1,nums,dp) + f(index+1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(size+1, vector<int>(size+1, -1));
        return f(1,size,nums,dp);
    }
};

// tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(size+2, vector<int>(size+2, 0));
        for(int i=size;i>=1;i--){
            for(int j=1;j<=size;j++){
                if(i>j) continue;
                int maxi = INT_MIN;
                for(int index = i;index<=j;index++){
                    int cost = nums[i-1]*nums[index]*nums[j+1] + dp[i][index-1] + dp[index+1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;                    
            }
        }
        return dp[1][size];
    }
};