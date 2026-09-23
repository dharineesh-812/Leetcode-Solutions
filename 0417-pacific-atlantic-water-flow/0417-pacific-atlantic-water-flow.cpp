class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>

    int m , n;

    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    void dfs(int x , int y , vvi & vis , vvi &grid){
          vis[x][y] = 1;

          for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[x][y] <= grid[nx][ny] && !vis[nx][ny])
                dfs(nx , ny , vis , grid);
          }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size() , n = heights[0].size();
        vvi pacific(m , vi(n , 0));
        vvi atlantic(m , vi(n , 0));
        vvi result;
        for(int j = 0; j < n;j++)
            dfs(0 , j , pacific , heights);
        for(int i = 0; i < m;i++)
            dfs(i , 0 , pacific , heights);
        for(int j = 0; j < n;j++)
            dfs(m - 1 , j  , atlantic ,heights);
        for(int i = 0; i < m;i++)
            dfs(i , n - 1 , atlantic ,heights);
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
        }
        return result;
    }
};