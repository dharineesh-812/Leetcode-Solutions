<<<<<<< HEAD
class Solution {
public:
    vector<vector<int>> vis;
    void dfs (vector<vector<char>>& grid , int i ,int j){
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int k = 0;k < 4;k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >=0 && nr < n && nc >=0 && nc < m && grid[nr][nc]=='1' && ! vis [nr][nc])
                dfs(grid,nr,nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vis.resize(n,vector<int>(m));
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(grid , i , j);
                }
            }
        }
        return cnt;
    }
=======
class Solution {
public:
    vector<vector<int>> vis;
    void dfs (vector<vector<char>>& grid , int i ,int j){
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int k = 0;k < 4;k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >=0 && nr < n && nc >=0 && nc < m && grid[nr][nc]=='1' && ! vis [nr][nc])
                dfs(grid,nr,nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vis.resize(n,vector<int>(m));
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(grid , i , j);
                }
            }
        }
        return cnt;
    }
>>>>>>> 03bc897aadced6bfc241f255a432774cf3182193
};