class Solution {
public:
    int dp[202][202];
    int n;

    const int inf = 1e9;

    int rec(int i , int j , vector<vector<int>>& grid){
        if(j < 0 || j >= n || i >= n)
            return inf;
        if(i == n - 1 && j >= 0 && j < n)
            return grid[i][j];

        if(dp[i][j] != inf)
            return dp[i][j];

        int ans = inf;
        for(int k = 0;k < n;k++){
            if(j == k)
                continue;
            ans = min(ans , rec(i + 1 , k , grid));
        }
        return dp[i][j] = grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        n = grid.size();

        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                dp[i][j] = inf;
        int mn = inf;
        for(int i = 0;i < n;i++)
            mn = min(mn , rec(0 , i , grid));

        return mn;
    }
};