class Solution {
public:
// previous problem
    int rob1(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = nums[0];
	    for(int i=1;i<nums.size();i++){
	        int pick = nums[i] + prev2;
	        int notpick = prev1;
	        prev2=prev1;
	        prev1 = max(pick, notpick);
	    }
	    return prev1;        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(rob1(temp1), rob1(temp2)); // find maximum of array leaving first element and array leaving last element
    }
};