class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    q.push({i-1,j}), q.push({i+1,j}) ,q.push({i,j-1}),q.push({i,j+1});
                }
            }
        }
        int steps = 0;
        while(!q.empty()){
            steps++;
            int qsize = q.size();
            while(qsize--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>=0 && x<row && y>=0 && y<col && grid[x][y]==0){
                    grid[x][y] = steps;
                    q.push({x-1,y}), q.push({x+1,y}) ,q.push({x,y-1}),q.push({x,y+1});
                }
            }
        }
        return ((steps<=1) ? -1 : steps-1);
    }
};