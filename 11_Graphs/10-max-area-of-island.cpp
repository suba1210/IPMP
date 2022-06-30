class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        grid[row][col] = 0;
        int dx[] = {+1,-1,0,0};
        int dy[] = {0,0,+1,-1};
        int  count = 0;
        for(int i=0;i<4;i++){
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol]==1){
                count += 1 + dfs(newRow, newCol, grid);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = INT_MIN;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    maxi = max(maxi, 1 + dfs(i, j, grid)); // add 1 to consider current cell
                }
            }
        }
        
        if(maxi==INT_MIN)
            return 0;
        else
            return maxi;
    }
};