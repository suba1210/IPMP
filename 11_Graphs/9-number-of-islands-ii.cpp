/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
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
class Solution {
public:

    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<subset> subsets(n*m+1);
        vector<int> ans;
        int count = 0;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i=0;i<subsets.size();i++){
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
        int dx[] = {-1, +1, 0, 0};
        int dy[] = {0,0,-1,1};
        for(auto it: operators){
            int x = it.x;
            int y = it.y;
            if(grid[x][y]==1){
                ans.push_back(count);
                continue;
            }
            count++;
            grid[x][y] = 1;
            int ind1 = x*m + (y+1); // 1D cordinate
            for(int dir=0;dir<4;dir++){
                int newX = x+dx[dir];
                int newY = y+dy[dir];
                int ind2 = newX*m + (newY+1);
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1 && find(subsets,ind1)!=find(subsets,ind2)){
                    count--;
                    union1(subsets,ind1, ind2);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
