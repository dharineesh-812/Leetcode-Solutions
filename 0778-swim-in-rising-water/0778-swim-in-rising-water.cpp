#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define F first
#define S second
#define mp make_pair
const int inf = 1e9;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vvi dist(n , vi(n , 1e9));

        using state = pair<int,pi>;
        multiset<state> st;

        dist[0][0] = grid[0][0];
        st.insert(mp(grid[0][0] , mp(0,0)));
        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        while(!st.empty()){
            state it = *st.begin();
            st.erase(st.begin());

            int time = it.F , x = it.S.F , y = it.S.S;
            if(time > dist[x][y])
                continue;
            for(int k = 0; k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny < n && ny >= 0){
                    int ntime = max(time , grid[nx][ny]);
                    if(ntime < dist[nx][ny]){
                        st.erase(mp(dist[nx][ny] , mp(nx , ny)));
                        dist[nx][ny] = ntime;
                        st.insert(mp(dist[nx][ny] , mp(nx , ny)));
                    }
                } 
            }
        }
        return dist[n-1][n-1];
    }
};