class Solution {
public:
    int m , n;

    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    bool isValid(int x ,int y){
        if(x >= 0 && x < m && y >= 0 && y < n)
            return true;
        return 0;
    }

    int dfs(int x , int y , vector<vector<int>>& grid){

        int ans = grid[x][y];
        grid[x][y] = 0;

        for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(isValid(nx , ny) && grid[nx][ny] > 0)
                ans += dfs(nx , ny , grid);
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size() , n = grid[0].size();
        int mx = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] > 0){
                    int fish = dfs(i , j , grid);
                    mx = max(mx , fish);
                }
            }
        }
        return mx;
    }
};