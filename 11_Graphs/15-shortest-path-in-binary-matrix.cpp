class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0){
            return -1;
        }
        int columns = grid[0].size();
        if(columns==0){
            return -1;
        }
        if(grid[0][0]!=0 || grid[rows-1][columns-1]!=0){
            return -1;
        }
        vector<vector<int> > directions = {{1,-1},{-1,0},{-1,1},{0,-1},{0,1},{-1,-1},{1,0},{1,1}};
        queue<pair<int, int> > que;
        que.push(make_pair(0,0));
        grid[0][0] = 1;
        
        while(!que.empty()){
            auto curr = que.front();
            int x = curr.first, y = curr.second;
            if(rows-1 == x && columns-1 == y){
                return grid[x][y];
            }
            
            for(auto direction: directions){
                int nextX = x + direction[0];
                int nextY = y + direction[1];
                
                if(nextX < rows && nextX >=0 && nextY < columns && nextY >=0 && grid[nextX][nextY]==0){
                    que.push(make_pair(nextX, nextY));
                    grid[nextX][nextY] = grid[x][y] + 1;
                }
            }
            
            que.pop();
        }
        
        return -1;
        
    }
};