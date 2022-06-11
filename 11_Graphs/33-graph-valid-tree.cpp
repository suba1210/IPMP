class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
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
    bool validTree(int n, vector<vector<int>> &edges) {
        vector<subset> subsets(n);

        for(int i=0;i<n;i++){
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        for(auto x : edges){
            if(find(subsets, x[0])!=find(subsets, x[1]))
                union1(subsets, x[0], x[1]);
            else
                return false;
        }
        int par = find(subsets,0);
        for(int i=1;i<n;i++){
            if(par != find(subsets, i))
                return false;
        }
        return true;

    }
};
