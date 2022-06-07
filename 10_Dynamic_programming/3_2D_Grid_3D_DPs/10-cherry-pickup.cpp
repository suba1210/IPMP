// recursion tc = O(3^col * 3^col) sc = O(row)
class Solution
{
public:
    int maxOfAllPaths(int row, int col1, int col2, int rowSize, int colSize, vector<vector<int>> &grid)
    {
        if (col1 < 0 || col1 >= colSize || col2 < 0 || col2 >= colSize)
        {
            return -1e8;
        }
        if (row == rowSize - 1)
        {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
        int maxi = -1e8;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (col1 == col2)
                    maxi = max(maxi, grid[row][col1] + maxOfAllPaths(row + 1, col1 + i, col2 + j, rowSize, colSize, grid));
                else
                    maxi = max(maxi, grid[row][col1] + grid[row][col2] + maxOfAllPaths(row + 1, col1 + i, col2 + j, rowSize, colSize, grid));
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        return maxOfAllPaths(0, 0, col - 1, row, col, grid);
    }
};

// memoization tc=O(product of number of states) => O(row*col*col)
// sc =>  O(row*col*col) + O(row) (O(row) is recusrion stack space)
class Solution
{
public:
    int maxOfAllPaths(int row, int col1, int col2, int rowSize, int colSize, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (col1 < 0 || col1 >= colSize || col2 < 0 || col2 >= colSize)
        {
            return -1e8;
        }
        if (row == rowSize - 1)
        {
            if (col1 == col2)
                return dp[row][col1][col2] = grid[row][col1];
            return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
        }
        if (dp[row][col1][col2] != -1)
        {
            return dp[row][col1][col2];
        }
        int maxi = -1e8;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (col1 == col2)
                    maxi = max(maxi, grid[row][col1] + maxOfAllPaths(row + 1, col1 + i, col2 + j, rowSize, colSize, grid, dp));
                else
                    maxi = max(maxi, grid[row][col1] + grid[row][col2] + maxOfAllPaths(row + 1, col1 + i, col2 + j, rowSize, colSize, grid, dp));
            }
        }
        return dp[row][col1][col2] = maxi;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        return maxOfAllPaths(0, 0, col - 1, row, col, grid, dp);
    }
};

// tabulation tc=O(product of number of states) => O(row*col*col)
// sc =>  O(row*col*col)
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j1 = 0; j1 < col; j1++)
            {
                for (int j2 = 0; j2 < col; j2++)
                {
                    if (i == row - 1)
                    {
                        if (j1 == j2)
                        {
                            dp[i][j1][j2] = grid[i][j1];
                        }
                        else
                        {
                            dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                        }
                        continue;
                    }
                    int value = 0;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            if (j1 == j2)
                            {
                                if (j1 + dj1 < col && j1 + dj1 >= 0 && j2 + dj2 < col && j2 + dj2 >= 0)
                                {
                                    value = max(value, grid[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2]);
                                }
                                else
                                {
                                    value = max(value, (int)(-1e8));
                                }
                            }
                            else
                            {
                                if (j1 + dj1 < col && j1 + dj1 >= 0 && j2 + dj2 < col && j2 + dj2 >= 0)
                                {
                                    value = max(value, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2]);
                                }
                                else
                                {
                                    value = max(value, (int)(-1e8));
                                }
                            }
                        }
                    }
                    dp[i][j1][j2] = value;
                }
            }
        }
        return dp[0][0][col - 1];
    }
};

// space optimization on tabulation tc=O(product of number of states) => O(row*col*col)
// sc =>  O(col*col)
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> next(col, vector<int>(col, 0));
        
        for (int i = row - 1; i >= 0; i--)
        {
            vector<vector<int>> dp(col, vector<int>(col, 0));
            
            for (int j1 = 0; j1 < col; j1++)
            {
                for (int j2 = 0; j2 < col; j2++)
                {
                    if (i == row - 1)
                    {
                        if (j1 == j2)
                        {
                            dp[j1][j2] = grid[i][j1];
                        }
                        else
                        {
                            dp[j1][j2] = grid[i][j1] + grid[i][j2];
                        }
                        continue;
                    }
                    int value = 0;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            if (j1 == j2)
                            {
                                if (j1 + dj1 < col && j1 + dj1 >= 0 && j2 + dj2 < col && j2 + dj2 >= 0)
                                {
                                    value = max(value, grid[i][j1] + next[j1 + dj1][j2 + dj2]);
                                }
                                else
                                {
                                    value = max(value, (int)(-1e8));
                                }
                            }
                            else
                            {
                                if (j1 + dj1 < col && j1 + dj1 >= 0 && j2 + dj2 < col && j2 + dj2 >= 0)
                                {
                                    value = max(value, grid[i][j1] + grid[i][j2] + next[j1 + dj1][j2 + dj2]);
                                }
                                else
                                {
                                    value = max(value, (int)(-1e8));
                                }
                            }
                        }
                    }
                    dp[j1][j2] = value;
                }
            }
            next = dp;
        }
        return next[0][col - 1];
    }
};
