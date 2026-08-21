#define pi pair<int,int>
#define F first
#define S second
class Solution {
public:
    int m , n;
    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    int rec(int x , int y ,int empty, pi dest ,vector<vector<int>>& grid){
        if(empty == -1 && pi (x,y)== dest)
            return 1;
        grid[x][y] = -1;

        int ans = 0;
        for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1)
               ans += rec(nx , ny , empty - 1 , dest , grid);
        }
        grid[x][y] = 0;

        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size() , n = grid[0].size();
        pi src , dest;
        int empty = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 0)
                    empty++;
                else if(grid[i][j] == 1)
                    src = {i , j};
                else if(grid[i][j] == 2)
                    dest = {i , j};
            }
        }
        return rec(src.F , src.S ,empty ,dest , grid);
    }
};