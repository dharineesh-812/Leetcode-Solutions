class Solution {
public:
    int tot;
    int m , n;
    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    void dfs(int x , int y ,vector<vector<int>>& grid){
        grid[x][y] = 0;
        tot--;
        for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                dfs(nx , ny , grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        tot = 0;
        m = grid.size() , n = grid[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1)
                    tot++;
            }
        }
        int mx = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    int ini = tot;
                    dfs(i , j , grid);
                    mx = max(mx , abs(ini - tot));
                }
            }
        }
        return mx;
    }
};