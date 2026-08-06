class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int m , n;
    int rec(vector<vector<int>>& grid, int k , int i , int j ,int rem){
        if(i >= m || j >= n)
            return 0;
        rem = (rem + grid[i][j]) % k;
        if(i == m - 1 && j == n - 1){
            return rem == 0 ? 1 : 0;
        }
        if(dp[i][j][rem] != -1)
            return dp[i][j][rem];
        int right = rec(grid , k ,i , j + 1 ,rem);
        int left = rec(grid , k , i + 1 , j , rem);
        return dp[i][j][rem] = (left + right) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size() , n = grid[0].size();
        dp.resize(m , vector<vector<int>>(n,vector<int>(k , -1)));
        return rec(grid , k , 0 , 0 , 0);
    }
};