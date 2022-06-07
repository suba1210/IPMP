// recursion tc = 2^n sc = O(n)
class Solution{   
public:
    bool findAllSubsets(int index, int sum, vector<int>arr){
        if(sum==0)
            return true;
        if(index==0)
            return arr[0]==sum;
        bool pick = findAllSubsets(index-1, sum-arr[0], arr);
        bool notPick = findAllSubsets(index-1, sum, arr);
        
        return pick || notPick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        return findAllSubsets(arr.size()-1, sum, arr);
    }
};

// memoisation tc = O(sum*target) sc = O(sum*target) + O(n)
class Solution{   
public:
    bool findAllSubsets(int index, int sum, vector<int>arr, vector<vector<int>> dp ){
        if(sum==0)
            return true;
        if(index==0)
            return arr[0]==sum;
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        bool pick = findAllSubsets(index-1, sum-arr[0], arr, dp);
        bool notPick = findAllSubsets(index-1, sum, arr, dp);
        
        return dp[index][sum] = pick || notPick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        return findAllSubsets(arr.size()-1, sum, arr, dp);
    }
};

// tabulation tc = O(sum*target) sc = O(sum*target)
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int size = arr.size();
        vector<vector<bool>> dp(size, vector<bool>(sum+1, false));
        for(int i=0;i<size;i++){
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        for(int i=1;i<size;i++){
            for(int j=1;j<=sum;j++){
                bool pick = false;
                if(j>=arr[i])
                    pick = dp[i-1][j-arr[i]];
                bool notPick = dp[i-1][j];
                dp[i][j] = pick || notPick;
            }
        }
        return dp[size-1][sum];
    }
};

// space optimisation
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int size = arr.size();
        vector<bool> prev(sum+1, false), curr(sum+1, false);
        prev[0] = curr[0] = true; // if sum = 0, then we can return true
        prev[arr[0]] = true; 
        for(int i=1;i<size;i++){
            for(int j=1;j<=sum;j++){
                bool pick = false;
                if(j>=arr[i])
                    pick = prev[j-arr[i]];
                bool notPick = prev[j];
                curr[j] = pick || notPick;
            }
            prev = curr;
        }
        return prev[sum];
    }
};