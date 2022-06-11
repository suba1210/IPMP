class subset{
public:
    int parent, rank;
};
int find(vector<subset>& subsets, int i){
    if(subsets[i].parent!=i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    } 
    return subsets[i].parent;
}
void union1(vector<subset>& subsets, int x, int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    if(subsets[xroot].rank>subsets[yroot].rank){
        subsets[yroot].parent=xroot;
    }
    else if(subsets[xroot].rank<subsets[yroot].rank){
        subsets[xroot].parent=yroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<subset> subsets(n);
        for(int i=0;i<n;i++){
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
        int extraConnection = 0;
        for(auto x : connections){
            int node1 = x[0];
            int node2 = x[1];
            if(find(subsets, node1)!=find(subsets, node2)){
                union1(subsets, node1, node2);
            } else {
                extraConnection++;
            }
        }
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(find(subsets, i));
        }
        int components = st.size();
        if(components-1<=extraConnection){
            return components-1;
        }
        else
            return -1;
    }
};