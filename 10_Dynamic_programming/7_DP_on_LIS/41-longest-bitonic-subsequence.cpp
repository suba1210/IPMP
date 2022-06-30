class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
        vector<int> dp1(nums.size(), 1), dp2(nums.size(), 1);       
        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i] && (1 + dp1[prev]) > dp1[i]){
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            for(int prev=nums.size()-1;prev>i;prev--){
                if(nums[prev] < nums[i] && (1 + dp2[prev]) > dp2[i]){
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }
        
        int maxi = dp1[0] + dp2[0];        
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi, dp1[i] + dp2[i]);
        }       
        return maxi-1; // subtarcting 1 because middle element amy be repeated
	}
};