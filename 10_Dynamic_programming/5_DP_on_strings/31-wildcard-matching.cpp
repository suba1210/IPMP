// memoisation
class Solution {
public:
    bool isAllStars(string & S1, int i) {
      for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
          return false;
      }
      return true;
    }
    bool wildcardMatchingUtil(string & S1, string & S2, int i, int j, vector < vector < int >> & dp) {
      if (i < 0 && j < 0)
        return true;
      if (i < 0 && j >= 0)
        return false;
      if (j < 0 && i >= 0)
        return isAllStars(S1, i);

      if (dp[i][j] != -1) return dp[i][j];

      if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

      else {
        if (S1[i] == '*')
          return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else return false;
      }
    }
    
    bool isMatch(string s, string p) {
      int n = p.size();
      int m = s.size();

      vector < vector < int >> dp(n, vector < int > (m, -1));
      return wildcardMatchingUtil(p, s, n - 1, m - 1, dp);
    }
};

// tabulation
class Solution {
public:
    bool isMatch(string S2, string S1) {
        
        vector < vector < bool >> dp(S1.size()+1, vector < bool > (S2.size()+1, false));
        dp[0][0] = true;
        for(int i=1;i<=S1.size();i++){
            bool flag = true;
            for(int k=1;k<=i;k++){
                if(S1[k-1]!='*'){
                    flag = false;
                    break;
                }
            }
            if(flag)
                dp[i][0] = true;
        }
        
        for(int i=1;i<=S1.length();i++){
            for(int j=1;j<=S2.length();j++){
              if (S1[i-1] == S2[j-1] || S1[i-1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
              else {
                if (S1[i-1] == '*')
                  dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else 
                  dp[i][j] = false;
              }
            }
        }
        return dp[S1.size()][S2.size()];
        
    }
};