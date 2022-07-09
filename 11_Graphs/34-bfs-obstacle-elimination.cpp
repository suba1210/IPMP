class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>> q;
        q.push({0, 0, k});
        int steps = 0, row = grid.size(), col = grid[0].size();
        int d[] = {0, 1, 0, -1, 0};
        vector<vector<vector<bool>>> visited(row, vector<vector<bool>>(col, vector<bool>(k+1, false)));
        visited[0][0][k] = true;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                vector<int> arr = q.front();
                q.pop();
                
                int x = arr[0], y = arr[1], obs = arr[2];
                
                if(x == row-1 && y == col-1)
                    return steps;
                
                for(int i=0; i<4; i++){
                    int newX = x + d[i];
                    int newY = y + d[i+1];
                    if( min(newX, newY)>=0 && newX<row && newY<col ){
                        if(grid[newX][newY] == 0 && !visited[newX][newY][obs]){
                            visited[newX][newY][obs] = true;
                            q.push({newX, newY, obs});
                        } else if(grid[newX][newY] == 1 && obs > 0 && !visited[newX][newY][obs-1]){
                            visited[newX][newY][obs-1] = true;
                            q.push({newX, newY, obs-1});                        
                        }                        
                    }
                }
            }            
            steps++;
        }       
        return -1;
    }
};