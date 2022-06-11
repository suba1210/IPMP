class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        while(!q.empty()){
            pair<int,int> grid = q.front();
            q.pop();
            int gridRow = grid.first;
            int gridCol = grid.second;
            if(gridRow==destination[0] && gridCol==destination[1]){
                return true;
            }
            int dirX[] = {0,+1,0,-1};
            int dirY[] = {+1,0,-1,0};
            for(int i=0;i<4;i++){
                int newRow = gridRow;
                int newCol = gridCol;
                while(newRow>=0 && newRow<row && newCol>=0 && newCol<col && maze[newRow][newCol]==0){
                    newRow += dirX[i];
                    newCol += dirY[i];                   
                }
                newRow -= dirX[i];
                newCol -= dirY[i];
                if(visited[newRow][newCol]==0){
                    visited[newRow][newCol]=true;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }
};