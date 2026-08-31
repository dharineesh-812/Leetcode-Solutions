#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define F first
#define S second
#define mp make_pair

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int mx = 0;
        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        int n = grid.size();
        vvi dist(n , vi(n , 0));
        using state = pair<int, pi>;
        queue<state> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    q.push(mp(0 , mp(i , j)));
                }
            }
        }
        while(!q.empty()){
            state it = q.front();
            q.pop();
            int d = it.F , x = it.S.F , y = it.S.S;
            for(int k = 0; k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                    dist[nx][ny] = 1 + d;
                    q.push(mp(dist[nx][ny] , mp(nx , ny)));
                    grid[nx][ny] = 1;
                    mx = max(mx , dist[nx][ny]);
                }
            }
        }
        return mx == 0 ? -1 : mx;
    }
};