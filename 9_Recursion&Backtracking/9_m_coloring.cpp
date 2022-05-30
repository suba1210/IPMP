bool isValid(int node, bool graph[101][101], vector<int>& color, int n, int col){
    for(int i=0;i<n;i++){
        if(i!=node && graph[i][node]==1 && color[i]==col){
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], int m, int n, vector<int>& color, int node){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isValid(node, graph,color, n, i)){
            color[node] = i;
            if(solve(graph,m,n,color,node+1)){
                return true;
            }
            else{
                color[node]=0;
            }
        }
    }
    return false;
}

// start
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n,0);
    return solve(graph,m,n,color,0);
}