class Solution {
public:
    int m , n;
    int dx[4] = {-1 , 0 , 1 ,0};
    int dy[4] = {0 , 1 , 0, -1};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color , int c){
        image[sr][sc] = color;
        for(int i = 0; i < 4;i++){
            int nx = sr + dx[i];
            int ny = sc + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == c)
                dfs(image , nx , ny , color , c);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];
        if(c == color)
            return image;
        m = image.size() , n = image[0].size();
        dfs(image , sr , sc , color , c);
        return image;
    }
};