class Solution {
public:
    bool compare(string& high, string& low){
        if(high.length() != low.length()+1){
            return false;
        }
        int highIndex = 0, lowIndex = 0;
        while(highIndex<high.length()){
            if( lowIndex<low.length() && high[highIndex]==low[lowIndex]){
                highIndex++;
                lowIndex++;
            } else {
                highIndex++;
            }
        }
        if(highIndex==high.length() && lowIndex==low.length())
            return true;
        return false;       
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b){return a.length() < b.length();});
        vector<int> dp(words.size(), 1);       
        int maxi = 1;
        for(int i=0;i<words.size();i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev]) && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;      
    }
};