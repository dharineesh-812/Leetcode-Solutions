#define pi pair<int,int>
#define F first
#define S second
class Solution {
public:
    int m , n; 
    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    using state = pi;
    queue<state> q;

    void dfs(int i , int j ,vector<vector<int>>& grid){
        q.push({i , j});
        grid[i][j] = 2;
        for(int k = 0; k < 4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                dfs( nx , ny , grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        bool found = false;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1 && !found){
                    found = true;
                    dfs(i , j , grid);
                    break;
                }
            }
            if(found) break;
        }
        while(!q.empty()){
            int si = q.size();
            while(si--){
                state it = q.front();
                q.pop();
                int i = it.F;
                int j = it.S;
                for(int k = 0; k < 4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                        if(grid[nx][ny] == 1)
                            return cnt;
                        if(grid[nx][ny] == 0){
                            grid[nx][ny] = 2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};   