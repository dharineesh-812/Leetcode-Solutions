#define pi pair<int,int>
#define F first
#define S second
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0 , fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        using state = pair<int,int>;
        queue<state> q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2)
                    q.push({i , j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        while(!q.empty() && fresh > 0){
            int si = q.size();
            int initial = fresh;
            for(int i = 0;i < si;i++){
                state st = q.front();
                q.pop();
                int x = st.F , y = st.S ;
                for(int k = 0; k < 4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx , ny});
                    }

                }
            }
            if(initial > fresh)
                ans++;
        }
        
        return fresh > 0 ? -1 : ans;
    }
};