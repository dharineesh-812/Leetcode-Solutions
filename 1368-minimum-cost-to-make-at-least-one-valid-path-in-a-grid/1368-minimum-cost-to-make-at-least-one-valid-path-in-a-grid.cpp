#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define mp make_pair
#define F first
#define S second
const int inf = 1e9;

class Solution {
public:
    int dx[4] = {-1 ,0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vvi cost(m,vi(n,inf));

        using state = pair<int,pi>;
        set<state>st;
        cost[0][0] = 0;
        st.insert(mp(0 , mp(0 , 0)));

        while(!st.empty()){
            state it = *st.begin();
            st.erase(st.begin());
            int c = it.F , x = it.S.F , y = it.S.S;
            for(int k = 0; k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nc = 0;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if((k == 0 && grid[x][y] != 4) || (k == 1 && grid[x][y] != 1) || (k == 2 && grid[x][y] != 3) || (k == 3 && grid[x][y] != 2))
                        nc = 1;
                    if(c + nc < cost[nx][ny]){
                        st.erase(mp(cost[nx][ny] , mp(nx , ny)));
                        cost[nx][ny] = c + nc;
                        st.insert(mp(cost[nx][ny] , mp(nx , ny)));
                    }
                }
            }
        }
        return cost[m - 1][n - 1];
    }
};