#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        int m = isWater.size() , n = isWater[0].size();
        vvi dist(m , vi(n , 0));
        using state = pair<int , pi>;
        queue<state> q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(isWater[i][j])
                    q.push(mp(0 , mp(i , j)));
            }
        }
        while(!q.empty()){
            state it = q.front();
            q.pop();
            int d = it.F , x = it.S.F , y = it.S.S;
            for(int k = 0;k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && isWater[nx][ny] == 0){
                    dist[nx][ny] = 1 + d;
                    q.push(mp(dist[nx][ny] , mp(nx , ny)));
                    isWater[nx][ny] = 1;
                }
            }
        }
        return dist;
    }
};