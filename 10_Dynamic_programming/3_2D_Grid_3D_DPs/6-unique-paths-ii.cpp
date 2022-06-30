// recursion
// consider edge case when [[1]] no possible moves/paths
class Solution
{
public:
    int allPaths(int row, int col, vector<vector<int>> &grid)
    {
        if (grid[row][col] == 1) // consider edge case when [[1]] no possible moves/paths
            return 0; // that is why this condition is above row==0 col==0 condition
        if (row == 0 && col == 0)
            return 1;
        int ans = 0;
        if (row > 0)
            ans += allPaths(row - 1, col, grid);
        if (col > 0)
            ans += allPaths(row, col - 1, grid);
        return ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        return allPaths(m - 1, n - 1, grid);
    }
};

// memoization => TC = O(N*M) , SC = O(N*M) + ( O(path length) == (O(n-1)(m-1)) )
class Solution
{
public:
    int allPaths(int row, int col, vector<vector<int>> &grid, vector<vector<int>> dp)
    {
        if (grid[row][col] == 1)
            return 0;
        if (row == 0 && col == 0)
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];
        int ans = 0;
        if (row > 0)
            ans += allPaths(row - 1, col, grid, dp);
        if (col > 0)
            ans += allPaths(row, col - 1, grid, dp);
        return dp[row][col] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return allPaths(m - 1, n - 1, grid, dp);
    }
};

// tabulation => this answer gives WA in leetcode, try once agin
int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // base conditions
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[n - 1][m - 1];
}

int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return mazeObstaclesUtil(n, m, maze, dp);
}

// space optimisation of tabulation
class Solution
{
public:
    int uniquePaths(int row, int col, vector<vector<int> >& maze)
    {
        vector<int> prev(col, 0);
        for (int i = 0; i < row; i++)
        {
            vector<int> dp(col, 0);
            for (int j = 0; j < col; j++)
            {
                if (i > 0 && j > 0 && maze[i][j] == 1)
                {
                    dp[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0)
                {
                    dp[j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = dp[j - 1];

                dp[j] = up + left;
            }
            prev = dp;
        }
        return prev[col - 1];
    }
};
