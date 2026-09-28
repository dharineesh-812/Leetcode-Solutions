class Solution {
public:
    int dp[104][104];
    int n;

    int inf = 1e9;

    int rec(int i , int j , vector<vector<int>>& matrix){

        if(j < 0 || j >= n || i >= n)
            return inf;

        if(i == n - 1 &&  j >= 0 && j < n)
            return matrix[i][j];

        if(dp[i][j] != inf)
            return dp[i][j];

        int down = rec(i + 1 , j , matrix);
        int left = rec(i + 1 , j - 1 , matrix);         
        int right = rec(i + 1 , j + 1 , matrix);

        return dp[i][j] = matrix[i][j] + min({down , left , right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        n = matrix.size();

        for(int i = 0;i < n;i++){
            for(int j = 0; j < n;j++)
                dp[i][j] = inf;
        }
        int mn = inf;
        for(int i = 0;i < n;i++){
            mn = min(mn , rec(0 , i , matrix));
        }
        return mn;
    }
};