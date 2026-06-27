class Solution {
public:
    vector<vector<int>> dp;
    int rec(int m , int n){
        if(m < 0 || n < 0)
            return 0;
        if(m == 0 || n == 0){
            return 1;
        }
        if(dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = (rec(m,n-1) + rec(m-1,n));
    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        return rec(m-1,n-1);
    }
};