// recursive
class Solution {
public:
    bool isPalindrome(int start, int end, string& s){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int allCuts(int index, int n, string& s){
        if(index==n)
            return 0;
        int minCost = INT_MAX;
        for(int k=index;k<n;k++){
            if(isPalindrome(index, k, s)){
                int cuts = 1 + allCuts(k+1, n, s);
                minCost = min(minCost, cuts);
            }
        }
        return minCost;
    }
    int minCut(string s) {
        int n = s.length();
        return allCuts(0, n, s) - 1; // don't consider the partition done at last position that's why - 1
    }
};

//memoisation
class Solution {
public:
    bool isPalindrome(int start, int end, string& s){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int allCuts(int index, int n, string& s, vector<int>& dp){
        if(index==n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int minCost = INT_MAX;
        for(int k=index;k<n;k++){
            if(isPalindrome(index, k, s)){
                int cuts = 1 + allCuts(k+1, n, s, dp);
                minCost = min(minCost, cuts);
            }
        }
        return dp[index] = minCost;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return allCuts(0, n, s, dp) - 1; // inorder not to consider the partition done at last position
    }
};

// tabulation
class Solution {
public:
    bool isPalindrome(int start, int end, string& s){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1;i>=0;i--){
            int minCost = INT_MAX;
            for(int k=i;k<n;k++){
                if(isPalindrome(i, k, s)){
                    int cuts = 1 + dp[k+1];
                    minCost = min(minCost, cuts);
                }
            }
            dp[i] = minCost;            
        }
        return dp[0] - 1;
    }
};