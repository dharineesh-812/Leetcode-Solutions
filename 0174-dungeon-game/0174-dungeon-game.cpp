class Solution {
public:
    int dp[202][202];
    int rec(vector<vector<int>> &mat,int i , int j){
        if(i == mat.size() ||j == mat[0].size())
            return 1e9;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == mat.size() - 1 && j == mat[0].size() - 1)
            return mat[i][j] < 0 ? 1 + (-mat[i][j]) : 1;
        int right = rec(mat , i , j + 1);
        int left = rec(mat , i + 1, j);

        int health = min(right , left) - mat[i][j];
        int ans = health <= 0 ? 1 : health;
        return dp[i][j] = ans;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size() , n = dungeon[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(dungeon , 0 , 0);
    }
};