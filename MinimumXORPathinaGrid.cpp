class Solution {
public:
    int m , n;
    vector<vector<vector<int>>>dp;
    int rec(vector<vector<int>>& grid,int i ,int j,int xr){
        if(i>=m || j>=n)
            return 1e9;
        xr = xr^grid[i][j];
        if(dp[i][j][xr] != -1)
            return dp[i][j][xr];
        if(i == m-1 && j == n-1)
          return dp[i][j][xr] = xr;
        int ans = 1e9;
        ans = min({ans ,rec(grid,i,j+1,xr),rec(grid,i+1,j,xr)});
        return dp[i][j][xr] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return rec(grid,0,0,0);
    }
};