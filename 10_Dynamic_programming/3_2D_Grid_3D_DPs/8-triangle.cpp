// recursion
class Solution {
public:
    int minOfAllPaths(int row, int col, int rowSize, vector<vector<int>>& triangle){
        if(row==rowSize-1)
            return triangle[row][col];        
        int down = triangle[row][col] + minOfAllPaths(row+1, col, rowSize, triangle);  
        int diagonalRight = triangle[row][col] + minOfAllPaths(row+1, col+1, rowSize, triangle);
        return min(down, diagonalRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        return minOfAllPaths(0,0,row,1,triangle);
    }
};


// memoization
class Solution {
public:
    int minOfAllPaths(int row, int col, int rowSize, vector<vector<int>>& triangle,  vector<vector<int>> dp){
        if(row==rowSize-1)
            return dp[row][col] = triangle[row][col];        
        int down = triangle[row][col] + minOfAllPaths(row+1, col, rowSize, triangle, dp);  
        int diagonalRight = triangle[row][col] + minOfAllPaths(row+1, col+1, rowSize, triangle, dp);
        return dp[row][col] = min(down, diagonalRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        vector<vector<int>> dp(row, vector<int>(row, -1));
        return minOfAllPaths(0,0,row,1,triangle, dp);
    }
};


// tabulation
class Solution {
public:    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, 0));
        
        for(int i=row-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                if(i==row-1){
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                dp[i][j] = min(triangle[i][j]+dp[i+1][j], triangle[i][j]+dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// space optimisation
class Solution {
public:    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        
        vector<int> next(row,0);
        for(int i=0;i<row;i++){
            next[i] = triangle[row-1][i];
        }
        
        for(int i=row-2;i>=0;i--){
            vector<int> dp(row,0);
            for(int j=0;j<triangle[i].size();j++){
                dp[j] = min(triangle[i][j]+next[j], triangle[i][j]+next[j+1]);
            }
            next = dp;
        }
        return next[0];
    }
};