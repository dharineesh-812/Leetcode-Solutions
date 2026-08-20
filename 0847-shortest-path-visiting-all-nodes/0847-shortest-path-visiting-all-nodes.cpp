#define pi pair<int,int>
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        using state = pi;
        queue<state>q;

        bool vis[n][1 << n];
        memset(vis , false , sizeof(vis));

        for(int i = 0; i < n;i++){
            int initialmask = (1 << i);
            q.push(mp(i , initialmask));
            vis[i][initialmask] = 1;
        }
        int distance = 0;

        while(!q.empty()){
            int si = q.size();
            while(si--){
                state it = q.front();
                q.pop();
                int node = it.F , vismask = it.S;
                if(vismask == (1 << n) - 1)
                    return distance;
                for(int nei : graph[node]){
                    int newmask = vismask | (1 << nei);

                    if(!vis[nei][newmask]){
                        vis[nei][newmask] = 1;
                        q.push(mp(nei , newmask));
                    }
                }
            }
            distance++;
        }
        return 0;
    }
};