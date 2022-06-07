// recursion
class Solution {
public:
    int findAllPaths(int row, int col, vector<vector<int>>& grid){
        if(row==0 && col==0)
            return grid[row][col];
        if(row<0 || col<0)
            return 1e9;
        int up = grid[row][col] + findAllPaths(row-1, col, grid);
        int left = grid[row][col] + findAllPaths(row, col-1, grid);
        return min(up, left);        
    }
    int minPathSum(vector<vector<int>>& grid) {
        return findAllPaths(grid.size()-1, grid[0].size()-1, grid);
    }
};

// memoization => TC = O(N*M) , SC = O(N*M) + ( O(path-length) == (O(n-1)(m-1)) )
class Solution {
public:
    int findAllPaths(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row==0 && col==0)
            return grid[row][col];
        if(row<0 || col<0)
            return 1e9;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up = grid[row][col] + findAllPaths(row-1, col, grid, dp);
        int left = grid[row][col] + findAllPaths(row, col-1, grid, dp);
        return dp[row][col] = min(up, left);        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> > dp(row, vector<int>(col, -1));
        return findAllPaths(row-1, col-1, grid, dp);
    }
};

// tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> > dp(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int up = grid[i][j];
                if(i>0)
                    up += dp[i-1][j];
                else
                    up += 1e9;
                
                int left = grid[i][j];
                if(j>0)
                    left += dp[i][j-1];
                else
                    left += 1e9;
                
                dp[i][j] = min(up, left);
            }
        }
        return dp[row-1][col-1];
    }
};

// space optimisation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> prev(col,0);
        vector<vector<int> > dp(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
            vector<int> dp(col,0);
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    dp[j] = grid[i][j];
                    continue;
                }
                int up = grid[i][j];
                if(i>0)
                    up += prev[j];
                else
                    up += 1e9;
                
                int left = grid[i][j];
                if(j>0)
                    left += dp[j-1];
                else
                    left += 1e9;
                
                dp[j] = min(up, left);
            }
            prev = dp;
        }
        return prev[col-1];
    }
};
