class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prereq.size();i++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        vector<int> inDegree(numCourses, 0);
        for(int i=0;i<adj.size();i++){
            for(auto x: adj[i]){
                inDegree[x]++;
            }
        }
        queue<int> q;
        int count=0;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                q.push(i);
                count++;
            }
        }
        if(count==0)
            return false;
        count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x:adj[node]){
                if(--inDegree[x]==0){
                    q.push(x);
                }
            }
            count++;
        }
        if(count!=numCourses){
            return false;
        }
        else{
            return true;
        }
    }
};