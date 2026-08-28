#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define F first
#define S second
#define mp make_pair
const int inf = 1e9;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();

        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1}; 

        using state = pair<int,pi>;
        vvi cost(m , vi(n , inf));
        cost[0][0] = 0;

        priority_queue<state , vector<state> , greater<state>> q;

        q.push(mp(0 , mp(0 , 0)));

        while(!q.empty()){
            state it = q.top();
            q.pop();

            int c = it.F , x  = it.S.F , y = it.S.S;
            if(x == m - 1 && y == n - 1)
                return c;

            for(int k = 0;k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int nc = c + grid[nx][ny];
                    if(nc < cost[nx][ny]){
                        cost[nx][ny] = nc;
                        q.push(mp(nc , mp(nx , ny)));
                    }
                }
            }
        }
        return 0;
    }
};