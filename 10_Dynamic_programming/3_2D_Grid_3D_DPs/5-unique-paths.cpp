// recursion
class Solution {
public:
    int allPaths(int row, int col){
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }
        int up = allPaths(row-1,col);
        int left = allPaths(row,col-1);
        
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return allPaths(m-1,n-1);
    }
}

// memoization => TC = O(N*M) , SC = O(N*M) + ( O(path-length) == (O(n-1)(m-1)) )
class Solution {
public:
    int allPaths(int row, int col, vector<vector<int> > dp){
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int up = allPaths(row-1,col,dp);
        int left = allPaths(row,col-1,dp);
        
        return dp[row][col] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, -1));
        return allPaths(m-1,n-1,dp);
    }
};

// tabulation
class Solution {
public:
    int allPaths(int row, int col, vector<vector<int> > dp){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                    continue;
                }
                int up=0;
                int left=0;
                
                if(i>0)
                    up = dp[i-1][j];
                if(j>0)
                    left = dp[i][j-1];
                
                dp[i][j] = up+left;
            }
        }
        return dp[row-1][col-1];        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        return allPaths(m,n,dp);
    }
};

// space optimisation on tabulation
class Solution {
public:
    int uniquePaths(int row, int col) {
       vector<int> prev(col,0);
       for(int i=0;i<row;i++){
            vector<int> dp(col,0);
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    dp[j] = 1;
                    continue;
                }
                int up=0;
                int left=0;
                
                if(i>0)
                    up = prev[j];
                if(j>0)
                    left = dp[j-1];
                
                dp[j] = up+left;
            }
           prev = dp;
        }
        return prev[col-1]; 
    }
};
