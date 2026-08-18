#define vi vector<int>
#define pi pair<int,int>
#define F first
#define S second
const int inf = 1e9;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pi>> adj(n);
        for(int i = 0; i < flights.size();i++){
            int u = flights[i][0] , v = flights[i][1] , c = flights[i][2];
            adj[u].push_back({v , c});
        }
        using state = pi;
        queue<state> q;
        vi dist(n , inf);
        dist[src] = 0;
        q.push({0 , src});
        int used = 0;
        while(!q.empty() && used <= k){
            int si = q.size();
            while(si--){
                state it = q.front();
                q.pop();
                int c = it.F , u = it.S;
                for(auto [v , d] : adj[u]){
                    int nc = d + c;
                    if(nc <= dist[v]){
                        dist[v] = nc;
                        q.push({nc , v});
                    }
                }
            }
            used++;
        }
        if(dist[dst] != inf)
            return dist[dst];
        return -1;
    }
};