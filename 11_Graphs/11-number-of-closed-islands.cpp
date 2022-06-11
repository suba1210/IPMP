class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid){
        if(grid[row][col]==-1||grid[row][col]==1) return true;
        if(row==0||row==grid.size()-1||col==0||col==grid[0].size()) return false;
        grid[row][col] = -1;
        
        bool left = dfs(row-1,col,grid);
        bool right = dfs(row+1,col,grid);
        bool up = dfs(row,col+1,grid);
        bool down = dfs(row,col-1,grid);
        
        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(grid[i][j]==0){
                    if(dfs(i, j, grid)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};