class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num = rooms.size();
        vector<bool> visited(num, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : rooms[node]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        for(auto x: visited){
            if(x==false)
                return false;
        }
        return true;
    }
};