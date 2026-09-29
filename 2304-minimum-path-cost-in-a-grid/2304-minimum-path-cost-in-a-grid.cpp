class Solution {
public:
    int  m , n;
    int dp[55][55];

    const int inf = 1e9;

    int rec(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& moveCost){
        if(i == m - 1)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int val = grid[i][j];
        int ans = inf;
        for(int k = 0;k < n;k++){
            ans = min(ans , moveCost[val][k] + rec(i + 1 , k , grid , moveCost));
        }
        return dp[i][j] = ans + val;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m = grid.size() , n = grid[0].size();
        memset(dp , -1 , sizeof(dp));

        int ans = inf;

        for(int i = 0; i < n;i++){
            ans = min(ans , rec(0 , i , grid , moveCost));
        }
        return ans;
    }
};