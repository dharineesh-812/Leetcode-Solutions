class Solution {
public:
    void bfs(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>> &q,int &ans){
        int n = grid.size();
        int dr[] = {-1,-1,0,1,1,1,0,-1};
        int dc[] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();
                for(int a = 0;a < 8;a++){
                    int nr = i + dr[a];
                    int nc = j + dc[a];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                        q.push({{nr,nc},d+1});
                        grid[nr][nc] = 1;
                        if((nr == n-1) && (nc == n-1)){
                        ans = d+1;
                        return ;
                    }
                    }
                }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(),ans =-1;
        if(n == 1 && grid[0][0] == 0)
            return 1;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        bfs(grid,q,ans);
    return ans;
    }
};