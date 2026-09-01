#define pi pair<int , int>
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size() , n = maze[0].size();
        int er = entrance[0] , ec = entrance[1];

        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        using state = pair <int , pi>;
        queue<state> q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == er && j == ec)
                    continue;
                if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && maze[i][j] == '.')
                    q.push(mp(0 , mp(i , j)));

            }
        }
        while(!q.empty()){
            state it = q.front();
            q.pop();
            int st = it.F , x = it.S.F , y = it.S.S;

            if(x == er && y == ec)
                return st;
            
            for(int k = 0;k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] =='.'){
                    q.push(mp(st + 1 , mp(nx , ny)));
                    maze[nx][ny] = '+';
                }

            }
        }
        return -1;
    }
};