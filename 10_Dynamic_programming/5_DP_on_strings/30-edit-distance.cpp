// recursion
class Solution {
public:

    // return 1+f(i-1,j) Insertion of character.
    // return 1+f(i,j-1) Deletion of character.
    // return 1+f(i-1,j-1) Replacement of character.

    int allWays(int i, int j, string word1, string word2){
        if(i<0)
            return j+1; // if word1 gets exhausted insert j+1 characters
        if(j<0)
            return i+1; // if word2 gets exhausted delete i+1 characters
        if(word1[i]==word2[j])
            return allWays(i-1, j-1, word1, word2);
        return min(1+allWays(i-1, j-1, word1, word2), min(1+allWays(i, j-1, word1, word2), 1 + allWays(i-1, j, word1, word2)));
    }

    int minDistance(string word1, string word2) {
        return allWays(word1.length()-1, word2.length()-1, word1, word2);
    }
};

// memoization
class Solution {
public:
    int allWays(int i, int j, string word1, string word2, vector<vector<int>> dp){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j] = allWays(i-1, j-1, word1, word2, dp);
        return dp[i][j] = min(1+allWays(i-1, j-1, word1, word2, dp), min(1+allWays(i, j-1, word1, word2, dp), 1 + allWays(i-1, j, word1, word2, dp)));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return allWays(word1.length()-1, word2.length()-1, word1, word2, dp);
    }
};

// tabulation
class Solution {
public:

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        for(int i=0;i<=word1.length();i++){
            dp[i][0] = i;
        }
        for(int i=0;i<=word2.length();i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

//space optimisation
class Solution {
public:
    int minDistance(string S1, string S2) {
        int n = S1.size();
        int m = S2.size();

        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0);

        for(int j=0;j<=m;j++){
            prev[j] = j;
        }

        for(int i=1;i<n+1;i++){
            cur[0]=i;
            for(int j=1;j<m+1;j++){
                if(S1[i-1]==S2[j-1])
                    cur[j] = 0+prev[j-1];

                else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
            }
            prev = cur;
        }

        return prev[m];
    }
};
