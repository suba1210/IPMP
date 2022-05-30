// solution
class Solution{
    public:
    void findAllPossiblePaths(vector<vector<int>> &maze, int n, vector<string>& result, vector<vector<bool> >& visited, int row, int col, string str){
        if(row==n-1 && col==n-1){
            result.push_back(str);
            return;
        }
        
        //down
        if((row+1)<n && maze[row+1][col]==1 && !visited[row+1][col]){
            visited[row][col] = true;
            findAllPossiblePaths(maze, n, result,visited, row+1, col, str+"D");
            visited[row][col] = false;
        }
        
        //left
        if((col-1)>=0 && maze[row][col-1]==1 && !visited[row][col-1]){
            visited[row][col] = true;
            findAllPossiblePaths(maze, n, result,visited, row, col-1, str+"L");
            visited[row][col] = false;
        }
        
        //right
        if((col+1)<n && maze[row][col+1]==1 && !visited[row][col+1]){
            visited[row][col] = true;
            findAllPossiblePaths(maze, n, result,visited, row, col+1, str+"R");
            visited[row][col] = false;
        }
        
        //up
        if((row-1)>=0 && maze[row-1][col]==1 && !visited[row-1][col]){
            visited[row][col] = true;
            findAllPossiblePaths(maze, n, result,visited, row-1, col, str+"U");
            visited[row][col] = false;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> result;
        vector<vector<bool> > visited(n, vector<bool>(n,false));
        if(maze[0][0]==1)
            findAllPossiblePaths(maze, n, result,visited, 0, 0, "");
        return result;
    }
};

//little better
class Solution{
    public:
    void findAllPossiblePaths(vector<vector<int>> &maze, int n, vector<string>& result, vector<vector<bool> >& visited, int row, int col, string str, vector<int>& di, vector<int>& dj){
        if(row==n-1 && col==n-1){
            result.push_back(str);
            return;
        }
        string steps = "DLRU";
        for(int i=0;i<4;i++){
            int next_row = row + di[i];
            int next_col = col + dj[i];
            if(next_row < n && next_row >=0 && next_col<n && next_col>=0 && maze[next_row][next_col]==1 && !visited[next_row][next_col]){
                visited[row][col] = true;
                findAllPossiblePaths(maze, n, result,visited, next_row, next_col, str+steps[i], di, dj);
                visited[row][col] = false;                
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> result;
        vector<vector<bool> > visited(n, vector<bool>(n,false));
        vector<int> di{1,0,0,-1};
        vector<int> dj{0,-1,1,0};
        if(maze[0][0]==1)
            findAllPossiblePaths(maze, n, result,visited, 0, 0, "", di, dj);
        return result;
    }
};