class Solution {
public:    
    int cnt , fresh;
    queue<pair<int,int>> q;
    void bfs(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int i,j,ini;
        while(!q.empty()){
            ini = fresh;
           
            int si = q.size();
            for(int k = 0 ; k < si ; k++ ){
                i = q.front().first;
                j = q.front().second;
                q.pop();
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int a = 0;a < 4;a++){
                    int nr = i + dr[a];
                    int nc = j + dc[a];
                    if(nr >=0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            if(ini>fresh)
                cnt++;
        }

    }
    int orangesRotting(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
         cnt = 0;
         fresh = 0;
         for(int i =0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
         }
         bfs(grid);
         if(fresh > 0)
            return -1;
        return cnt;
    }
};