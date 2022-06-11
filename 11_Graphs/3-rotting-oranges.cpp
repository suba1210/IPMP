class Solution {
public:
    // uses bfs
    int bfs(int row, int col, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int countFresh=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1)
                    countFresh++;
            }
        }
        if(countFresh==0){
            return 0;
        }
        int ans = 0;
        while(!q.empty()){
            int countNodes = q.size();           
            while(countNodes--){
                pair<int,int> node = q.front();
                q.pop();
                int nodeRow = node.first;
                int nodeCol = node.second;
                if(nodeRow-1>=0 && grid[nodeRow-1][nodeCol]==1){
                    grid[nodeRow-1][nodeCol] = 2;
                    q.push({nodeRow-1,nodeCol});
                }
                if(nodeRow+1<row && grid[nodeRow+1][nodeCol]==1){
                    grid[nodeRow+1][nodeCol] = 2;
                    q.push({nodeRow+1,nodeCol});
                } 
                if(nodeCol-1>=0 && grid[nodeRow][nodeCol-1]==1){
                    grid[nodeRow][nodeCol-1] = 2;
                    q.push({nodeRow,nodeCol-1});
                }
                if(nodeCol+1<col && grid[nodeRow][nodeCol+1]==1){
                    grid[nodeRow][nodeCol+1] = 2;
                    q.push({nodeRow,nodeCol+1});
                } 
            }
            ans++;
        }    
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        return bfs(row, col, grid);
    }
};
