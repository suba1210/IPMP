class Solution {
public:
    int dirx[4] = {1,-1,0,0};
    int diry[4] = {0,0,1,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        int steps=0;
        while(!q.empty()){
            steps++;
            int qsize = q.size();
            while(qsize--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(!(i==entrance[0] && j==entrance[1]) && (i==0 || i==maze.size()-1 || j==0 || j==maze[0].size()-1)){
                    return steps-1;
                }
                for(int d=0;d<4;d++){
                    int x = i + dirx[d];
                    int y = j + diry[d];
                    if(x>=0 && y>=0 && x<maze.size() && y<maze[0].size() && maze[x][y]=='.'){
                        maze[x][y] = '+';
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};