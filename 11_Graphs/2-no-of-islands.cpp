class Solution {
public:
    
    void dfs(int row, int col, vector<vector<char>>& grid){
        grid[row][col] = '2';
        
        if(row-1>=0 && grid[row-1][col]=='1')
            dfs(row-1,col,grid);
        if(row+1<grid.size() && grid[row+1][col]=='1'){
            dfs(row+1,col,grid);
        }
        if(col-1>=0 && grid[row][col-1]=='1')
            dfs(row,col-1,grid);
        if(col+1<grid[0].size() && grid[row][col+1]=='1'){
            dfs(row,col+1,grid);
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int countIslands = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    countIslands++;
                }
            }
        }
        
        return countIslands;
    }
};