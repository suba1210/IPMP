// recursion
class Solution {
public:
    int f(int i, vector<int>& arr, int k){
        if(i==arr.size())
            return 0;
        int len=0, sum, maxi=INT_MIN, maxAns=INT_MIN;
        for(int j=i;j<min((int)arr.size(), i+k);j++){
            len++;
            maxi = max(maxi, arr[j]);
            sum = (len*maxi) + f(j+1, arr, k);
            maxAns = max(maxAns, sum);
        }
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return f(0, arr, k);
    }
};

// memoisation
class Solution {
public:
    int f(int i, vector<int>& arr, int k, vector<int>& dp){
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int len=0, sum, maxi=INT_MIN, maxAns=INT_MIN;
        for(int j=i;j<min((int)arr.size(), i+k);j++){
            len++;
            maxi = max(maxi, arr[j]);
            sum = (len*maxi) + f(j+1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return f(0, arr, k, dp);
    }
};

// tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, 0);      
        for(int i=arr.size()-1;i>=0;i--){
            int len=0, sum, maxi=INT_MIN, maxAns=INT_MIN;
            for(int j=i;j<min((int)arr.size(), i+k);j++){
                len++;
                maxi = max(maxi, arr[j]);
                sum = (len*maxi) + dp[j+1];
                maxAns = max(maxAns, sum);
            } 
            dp[i] = maxAns;
        }
        return dp[0];
    }
};