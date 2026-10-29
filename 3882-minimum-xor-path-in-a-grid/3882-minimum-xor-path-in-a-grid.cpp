#define vi vector<int>
#define vvi vector<vi>

const int inf = 1e9;

class Solution {
public:
    vector<vvi> dp;
    int  m, n;
    int rec(int x , int y , int xr , vector<vector<int>>& grid){
        if(x >= m || y >= n)
            return inf;

        xr = xr ^ grid[x][y];

        if(dp[x][y][xr] != -1)
            return dp[x][y][xr];    
        
        if(x == m - 1 && y == n - 1)
            return dp[x][y][xr] = xr;
        
        int ans = inf;

        ans = min({ans , rec(x + 1 , y , xr , grid) , rec(x , y + 1 , xr , grid)});

        return dp[x][y][xr] = ans ;
        
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size() , n = grid[0].size();
        dp.resize(m , vvi(n , vi(1024 , -1)));

        return rec(0 , 0 , 0 , grid);
    }
};