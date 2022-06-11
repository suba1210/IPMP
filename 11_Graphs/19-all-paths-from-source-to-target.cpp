class Solution {
public:
    void f(int i, int n, vector<int>& path, vector<vector<int>>& result, vector<vector<int>>& graph){
        
        if(i==n){
            result.push_back(path);
            return;
        }
        
        for(auto x : graph[i]){
            path.push_back(x);
            f(x, n, path, result, graph);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        f(0, graph.size()-1, path, result, graph);
        return result;
    }
};