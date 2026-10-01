#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int ,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size() , n = land[0].size();

        vvi ans;
        using state = pi;
        queue<state> q;

        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(land[i][j] == 1){
                    int r1 = i;
                    int c1 = j;
                    int r2 = i;
                    int c2 = j;

                    q.push(mp(i , j));
                    vi row;

                    row.pb(r1);
                    row.pb(c1);

                    land[i][j] = -1;

                    while(!q.empty()){
                        state it = q.front();
                        q.pop();
                        int x = it.F , y = it.S;

                        for(int k = 0;k < 4;k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && land[nx][ny] == 1){
                                r2 = max(r2 , nx);
                                c2 = max(c2 , ny);

                                q.push(mp(nx , ny));
                                land[nx][ny] = -1;
                            }
                        }
                    }
                    row.pb(r2);
                    row.pb(c2);
                    ans.pb(row);
                }
            }
        }
        return ans;
    }
};