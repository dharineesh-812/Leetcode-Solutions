class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<vector<int>>& grid,int m, int n){
        if(m == 0 && n == 0)
            return 1;
        if(m < 0 || n < 0)
            return 0;
        if(grid[m][n] == 1)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        return dp[m][n] = rec(grid,m-1,n) + rec (grid,m,n-1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        if(grid[0][0] == 1)
            return 0;
        return rec(grid,m-1,n-1);
    }
};