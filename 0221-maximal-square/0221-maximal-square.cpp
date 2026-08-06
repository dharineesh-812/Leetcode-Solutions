class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n , 0));
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == '0')
                    dp[i][j] = 0;
                else{
                    if(i - 1 >=0 && j -1 >= 0)
                        dp[i][j] = 1 + min({dp[i - 1][j],
                                            dp[i][j-1], 
                                            dp[i - 1][j - 1]});
                    else
                        dp[i][j] = 1;
                }
                ans = max(ans , dp[i][j]);
            }
        }
        return ans * ans;
    }
};