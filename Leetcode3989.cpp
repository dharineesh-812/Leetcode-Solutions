class Solution {
public:
    int m , n , l;
    int dp[255][255];
    bool check(int i , int j,vector<vector<int>>& grid){
        for(int k = 0;k < m;k++){
            if(abs(grid[k][j] - grid[k][i]) > l)
                return false;
        }
        return true;
    }
    int rec(int prev, int curr ,vector<vector<int>>& grid){
        if(curr >= n)
            return 0;
        if(dp[prev+1][curr] != -1)
            return dp[prev+1][curr];
        int take = -1e9;
        if( prev == -1 || check(prev , curr ,grid))
            take = 1 + rec(curr , curr + 1, grid);
        int ntake = rec(prev , curr+1,grid);
        return dp[prev+1][curr] = max(take,ntake);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        m = grid.size() , n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        l = limit;
        return rec(-1,0,grid);
    }
};