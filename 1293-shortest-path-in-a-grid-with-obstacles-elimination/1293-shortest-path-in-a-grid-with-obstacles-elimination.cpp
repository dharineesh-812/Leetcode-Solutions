#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define F first
#define S second
class Solution {
public:
    const int inf = 1e9;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        vector<vii> vis(m , vii(n , vi(k + 1 , 0))) ,
        dist(m , vii (n ,vi(k + 1 ,inf)));
        using state = pair<int,pi>;
        queue<state>q;
        vis[0][0][0] = 1;
        dist[0][0][0] = 0;
        q.push({0,{0,0}});

        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};

        while(!q.empty()){
            state node = q.front();
            q.pop();
            int used = node.F;
            int x = node.S.F;
            int y = node.S.S;
            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if(used + grid[nx][ny] <= k && !vis[nx][ny][used + grid[nx][ny]]){
                        vis[nx][ny][used + grid[nx][ny]] = 1;
                        dist[nx][ny][used + grid[nx][ny]] = 1 + dist[x][y][used];
                        q.push({used + grid[nx][ny] , {nx , ny}});
                    }
                }
            }
        }
        int ans = inf;
        for(int i = 0;i <= k;i++)
            ans = min( ans , dist[m - 1][n - 1][i]);

        if(ans >= inf)
            return -1;
        return ans;
    }
};