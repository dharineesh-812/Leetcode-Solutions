#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define F first
#define S second
#define mp make_pair
const int inf = 1e9;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m  = heights.size();
        int n = heights[0].size();
        vvi dist(m , vi(n , inf));

        using state = pair<int,pi>;
        multiset<state> st;
        st.insert(mp(0,mp(0,0)));

        dist[0][0] = 0;
        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};

        while(!st.empty()){
            state it = *st.begin();
            st.erase(st.begin());

            int effort = it.F , r = it.S.F , c = it.S.S;

            if(effort > dist[r][c])
                continue;
            for(int k = 0;k < 4;k++){
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int cost = abs(heights[r][c] - heights[nr][nc]);
                    int neffort = max(effort , cost);

                    if(neffort < dist[nr][nc]){
                        st.erase(mp(dist[nr][nc],mp(nr,nc)));
                        dist[nr][nc] = neffort;
                        st.insert(mp(neffort , mp(nr , nc)));
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};