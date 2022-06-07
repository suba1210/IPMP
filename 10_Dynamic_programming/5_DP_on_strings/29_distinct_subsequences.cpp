// recursion
class Solution {
public:
    int allWays(int i, int j, string s, string t){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(s[i]==t[j])
            return allWays(i-1, j-1, s, t) + allWays(i-1, j, s, t);
        return allWays(i-1, j, s, t);
    }
    int numDistinct(string s, string t) {
        return allWays(s.length()-1, t.length()-1, s, t);
    }
};

// memoisation
class Solution {
public:
    int allWays(int i, int j, string s, string t, vector<vector<int>> dp){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = allWays(i-1, j-1, s, t, dp) + allWays(i-1, j, s, t, dp);
        return dp[i][j] = allWays(i-1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return allWays(s.length()-1, t.length()-1, s, t, dp);
    }
};

// tabulation
class Solution {
    int prime = 1e9+7;
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
        for(int i=0;i<s.length()+1;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};

// single 1D array space optimisation
class Solution {
    int prime = 1e9+7;
public:
    int numDistinct(string s, string t) {
        vector<int> dp(t.length()+1, 0);
        dp[0] = 1;
        for(int i=1;i<=s.length();i++){
            for(int j=t.length();j>=1;j--){
                if(s[i-1]==t[j-1]){
                    dp[j] = (dp[j-1] + dp[j])%prime;
                }
            }
        }
        return dp[t.length()];
    }
};
