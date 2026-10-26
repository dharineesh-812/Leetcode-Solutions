class Solution {
public:
    int m , n;

    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    long long dfs(int x , int y , vector<vector<int>>& grid){
        long long sum = grid[x][y];
        grid[x][y] = 0;
        for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0)
                sum += dfs(nx , ny , grid);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        long long ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] > 0){
                    long long sum = dfs(i , j , grid);
                    if(sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};