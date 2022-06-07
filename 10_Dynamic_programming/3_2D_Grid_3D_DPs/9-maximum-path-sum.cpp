// memoization Time Complexity: O(N*N) , Space Complexity: O(N) + O(N*M)
//Reason: We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M’.

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int> > &dp){    
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = -1e9;
    
    for(int j=0; j<m;j++){
        int ans = getMaxUtil(n-1,j,m,matrix,dp);
        maxi = max(maxi,ans);
    }    
    return maxi;
}

// tabulation Time Complexity: O(N*N) , Space Complexity: O(N*M)
//Reason for sc : We are using an external DP Array of size ‘N*M’.
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    
    vector<vector<int>> dp(row,vector<int>(col,-1));
    
    for(int i=0;i<col;i++)
        dp[0][i] = matrix[0][i];
    
    for(int i=1;i<row;i++){
        for(int j=0;j<col;j++){
            int up = matrix[i][j] + dp[i-1][j];
            int leftDiagonal = matrix[i][j];
            if(j-1>=0)
                leftDiagonal += dp[i-1][j-1];
            else
                leftDiagonal += -1e8;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<col)
                rightDiagonal += dp[i-1][j+1];
            else
                rightDiagonal += -1e8;
            
           dp[i][j]= max(up,max(leftDiagonal,rightDiagonal)); 
        }
    }
    
    int maxi = -1e8;
    for(int i=0;i<col;i++){ // pick the maximum of last row elements
        maxi = max(maxi, dp[row-1][i]);
    }
    
    return maxi;
}

// space optimisation
// Time Complexity: O(row*col)
// Space Complexity: O(col)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    
    vector<int> prev(col);
    
    for(int i=0;i<col;i++)
        prev[i] = matrix[0][i];
    
    for(int i=1;i<row;i++){
        vector<int> dp(col);
        for(int j=0;j<col;j++){
            int up = matrix[i][j] + prev[j];
            int leftDiagonal = matrix[i][j];
            if(j-1>=0)
                leftDiagonal += prev[j-1];
            else
                leftDiagonal += -1e8;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<col)
                rightDiagonal += prev[j+1];
            else
                rightDiagonal += -1e8;
            
           dp[j]= max(up,max(leftDiagonal,rightDiagonal)); 
        }
        prev = dp;
    }
    
    int maxi = -1e8;
    for(int i=0;i<col;i++){
        maxi = max(maxi, prev[i]);
    }
    
    return maxi;
}