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
    void boundaryDfs(int row, int col, vector<vector<int>>& grid){
        if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size())
            grid[row][col] = 0;
        if(row-1>=0 && grid[row-1][col]==1){
            boundaryDfs(row-1, col, grid);
        }
        if(row+1<grid.size() && grid[row+1][col]==1){
            boundaryDfs(row+1, col, grid);
        }       
        if(col-1>=0 && grid[row][col-1]==1){
            boundaryDfs(row, col-1, grid);
        }
        if(col+1<grid[0].size() && grid[row][col+1]){
            boundaryDfs(row, col+1, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i=0;i<col;i++){
            if(grid[0][i]==1){
                boundaryDfs(0, i, grid);
            }
            if(grid[row-1][i]){
                boundaryDfs(row-1, i, grid);
            }
        }
        for(int i=0;i<row;i++){
            if(grid[i][0]==1){
                boundaryDfs(i, 0, grid);
            }
            if(grid[i][col-1]){
                boundaryDfs(i, col-1, grid);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    count += 1 + dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};