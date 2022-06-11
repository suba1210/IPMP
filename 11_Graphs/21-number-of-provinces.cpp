class Solution {
public:
    void dfs(int src, vector<int>& visited, vector<vector<int>>& isConnected){
        visited[src] = true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[src][i]==1 && !visited[i]){
                dfs(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int> visited(size, false);
        int count = 0;
        for(int i=0;i<size;i++){
            if(!visited[i]){
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};