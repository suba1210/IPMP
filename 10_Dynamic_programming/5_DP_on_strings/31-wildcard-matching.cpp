// memoisation
class Solution
{
public:
  bool isAllStars(string &S1, int i)
  {
    for (int j = 0; j <= i; j++)
    {
      if (S1[j] != '*')
        return false;
    }
    return true;
  }
  bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
  {
    if (i < 0 && j < 0) // we have exhauseted all characters of pattern and string
      return true;
    if (i < 0 && j >= 0) // we have exhauseted all characters of pattern but have some characters in string
      return false;
    if (j < 0 && i >= 0) // we have exhauseted all characters of string but have some in pattern, so check if remaining characters of pattern are all stars
      return isAllStars(S1, i);

    if (dp[i][j] != -1)
      return dp[i][j];

    if (S1[i] == S2[j] || S1[i] == '?')
      return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

    else
    {
      if (S1[i] == '*')
        return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
      else
        return false;
    }
  }

  bool isMatch(string s, string p)
  {
    int n = p.size();
    int m = s.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return wildcardMatchingUtil(p, s, n - 1, m - 1, dp);
  }
};

// tabulation
class Solution
{
public:
  bool isAllStars(string &S1, int i)
  {

    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++)
    {
      if (S1[j - 1] != '*')
        return false;
    }
    return true;
  }

  bool wildcardMatching(string &S1, string &S2)
  {

    int n = S1.size();
    int m = S2.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

    dp[0][0] = true;

    for (int j = 1; j <= m; j++)
    {
      dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
      dp[i][0] = isAllStars(S1, i);
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {

        if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
          dp[i][j] = dp[i - 1][j - 1];

        else
        {
          if (S1[i - 1] == '*')
            dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

          else
            dp[i][j] = false;
        }
      }
    }

    return dp[n][m];
  }
};