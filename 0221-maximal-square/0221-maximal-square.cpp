class Solution {
public:
    int dp[303][303];
    int rec(vector<vector<char>>& mat , int i , int j){
        if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size())
            return 0;
        if(mat[i][j] == '0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = 1 + min({rec(mat , i + 1 , j) , rec(mat , i , j + 1) , rec(mat , i + 1 , j + 1)});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp , -1 , sizeof(dp));
        int ans = 0;
        int n = matrix.size() , m = matrix[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                ans = max(ans , rec(matrix , i , j));
            }
        }
        return ans * ans;
    }
};