// recursion tc = O(2^text1Length*2^text2Length)
class Solution {
public:
    int checkAllSubsequences(int text1Index, int text2Index, string text1, string text2){
        if(text1Index<0 || text2Index<0){
            return 0;
        }
        if(text1[text1Index]==text2[text2Index]){
            return 1 + checkAllSubsequences(text1Index-1, text2Index-1, text1, text2);
        }
        return max(checkAllSubsequences(text1Index-1, text2Index, text1, text2), checkAllSubsequences(text1Index, text2Index-1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return checkAllSubsequences(text1.length()-1, text2.length()-1, text1, text2);
    }
};

// memoisation tc = O(text1Length*text2Length) sc = O(text1Length*text2Length) + O(text1Length+text2Length)
//Reason: We are using an auxiliary recursion stack space(O(N+M)) (see the recursive tree, in the worst case, we will go till N+M calls at a time) and a 2D array ( O(N*M)).
class Solution {
public:
    int checkAllSubsequences(int text1Index, int text2Index, string text1, string text2, vector<vector<int>> storeLcs){
        if(text1Index<0 || text2Index<0){
            return 0;
        }
        if(storeLcs[text1Index][text2Index]!=-1){
            return storeLcs[text1Index][text2Index];
        }
        if(text1[text1Index]==text2[text2Index]){
            return storeLcs[text1Index][text2Index] = 1 + checkAllSubsequences(text1Index-1, text2Index-1, text1, text2, storeLcs);
        }
        return storeLcs[text1Index][text2Index] = max(checkAllSubsequences(text1Index-1, text2Index, text1, text2, storeLcs), checkAllSubsequences(text1Index, text2Index-1, text1, text2, storeLcs));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> storeLcs(text1.length(), vector<int>(text2.length(), -1));
        return checkAllSubsequences(text1.length()-1, text2.length()-1, text1, text2, storeLcs);
    }
};

// tabulation  tc = O(text1Length*text2Length) sc = O(text1Length*text2Length)
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> storeLcs(text1.length()+1, vector<int>(text2.length()+1, 0));
        for(int i=0;i<=text1.length();i++){
            storeLcs[i][0] = 0;
        }
        for(int i=0;i<=text2.length();i++){
            storeLcs[0][i] = 0;
        }
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1])
                    storeLcs[i][j] = 1 + storeLcs[i-1][j-1];
                else
                    storeLcs[i][j] = max(storeLcs[i][j-1], storeLcs[i-1][j]);
            }
        }
        return storeLcs[text1.length()][text2.length()];
        
    }
};

// space optimised tabulation  tc = O(text1Length*text2Length) sc = O(text2Length)
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        vector<int> storePrevLcs(text2.length()+1, 0), storeCurrLcs(text2.length()+1, 0);
        for(int i=0;i<=text2.length();i++){
            storePrevLcs[i] = 0;
        }
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1])
                    storeCurrLcs[j] = 1 + storePrevLcs[j-1];
                else
                    storeCurrLcs[j] = max(storeCurrLcs[j-1], storePrevLcs[j]);
            }
            storePrevLcs = storeCurrLcs;
        }
        return storePrevLcs[text2.length()];
        
    }
};
