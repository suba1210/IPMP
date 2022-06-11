class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int color){
        if(image[sr][sc]==color){
            image[sr][sc] = newColor;
            if(sr-1>=0 && image[sr-1][sc]==color)
                dfs(image, sr-1, sc, newColor, color);
            if(sc-1>=0 && image[sr][sc-1]==color)
                dfs(image, sr, sc-1, newColor, color);
            if(sc+1<image[0].size() && image[sr][sc+1]==color)
                dfs(image, sr, sc+1, newColor, color);
            if(sr+1<image.size() && image[sr+1][sc]==color)
                dfs(image, sr+1, sc, newColor, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color!=newColor)
            dfs(image, sr, sc, newColor, color);
        return image;        
    }
};