#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define mpp make_pair
#define F first
#define S second

#define len(x) (int)x.size()

class Solution {
public:

    int m , n;

    bool isSafe(int x , int y , vector<string>& classroom){
        if(x >= 0 && x < m && y >= 0 && y < n && classroom[x][y] != 'X')
            return true;
        return false;
    }

    int minMoves(vector<string>& classroom, int energy) {
        m = len(classroom) , n = len(classroom[0]);

        int litter = 0;
        vii mp(m , vi(n));

        pi start;

        for(int i = 0;i < m;i++){
            for(int j = 0; j < n;j++){
                if(classroom[i][j] == 'S')
                    start = {i , j};
                else if(classroom[i][j] == 'L')
                    mp[i][j] = litter++;
            }
        }
        if(litter == 0)
            return 0;
        
        int totalmask = (1 << litter) - 1; 
        vector<vector<vii>> vis(m , vector(n , vii(energy + 1 , vi(1 << litter))));

        using state = pair<pair<pi , int> , pi>;
        queue<state> q;

        const int dx[4] = {-1 , 0 , 1 , 0};
        const int dy[4] = {0 , 1 , 0 , -1};

        vis[start.F][start.S][energy][0] = 1;
        q.push(mpp(mpp(mpp(start.F , start.S) , energy) , mpp(0 , 0)));

        while(!q.empty()){
            state node = q.front();
            q.pop();

            int x = node.F.F.F , y = node.F.F.S , e = node.F.S , mask = node.S.F , moves = node.S.S;
            
            for(int k = 0;k < 4;k++){

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(isSafe(nx , ny , classroom)){
                    int ne = e - 1;
                    int nmask = mask;

                    if(classroom[nx][ny] == 'L')
                        nmask |= (1 << mp[nx][ny]);

                    if(nmask == totalmask)
                        return moves + 1;

                    if(classroom[nx][ny] == 'R')
                        ne = energy;
                    
                    if(ne == 0 && classroom[nx][ny] != 'R')
                        continue;

                    if(!vis[nx][ny][ne][nmask]){
                        vis[nx][ny][ne][nmask] = 1;
                        q.push(mpp(mpp(mpp(nx , ny) , ne),mpp(nmask , moves + 1)));                        
                    }
                }
            }
        }
        return -1;
    }
};