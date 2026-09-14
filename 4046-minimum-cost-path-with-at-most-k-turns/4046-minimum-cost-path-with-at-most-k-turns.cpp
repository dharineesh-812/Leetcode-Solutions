#define vi vector<int>
#define vvi vector<vi>

#define len(x) x.size()
int dp[76][76][5][76];

class Solution {
public:
    int m , n;

    // up , right , down , left 
    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    int turncost(int last , int dir){
        if(last == -1)
            return 0;
        return last != dir;
    }

    int rec(int i , int j , int last , int turns , vvi &grid){
        if(turns < 0)
            return 1e9;
        
        if(i < 0 || i >= m || j < 0 || j >= n )
            return 1e9;

        if(i == m - 1 && j == n - 1)
            return grid[i][j];
        
        if(dp[i][j][last + 1][turns] != -1)
            return dp[i][j][last + 1][turns];

        int ans = 1e9;

        for(int k = 0;k < 4;k++){

            int nx = i + dx[k];
            int ny = j + dy[k];

            ans = min(ans , grid[i][j] + rec(nx , ny , k , turns - turncost(last , k) , grid));
        }
        return dp[i][j][last + 1][turns] = ans;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        memset(dp , -1 , sizeof(dp));
        
        m = len(grid) , n = len(grid[0]); 

        int ans = rec(0 , 0 , -1 , k ,grid);
        if(ans == 1e9)
            return -1;
        
        return ans;
    }
};