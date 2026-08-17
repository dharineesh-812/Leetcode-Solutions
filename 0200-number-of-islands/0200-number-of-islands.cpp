#define vi vector<int>
#define vvi vector<vi>
class Solution {
public:
    void dfs(vector<vector<char>>& grid , int i , int j , vvi &vis){
        vis[i][j] = 1;
        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        for(int k = 0; k < 4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[i][j] == '1' && !vis[nx][ny])
                dfs(grid , nx , ny , vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size() , cnt = 0;
        vvi vis(m,vi(n,0));
        for(int i= 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(grid , i , j , vis);
                }                    
            }
        }
        return cnt;
    }
};