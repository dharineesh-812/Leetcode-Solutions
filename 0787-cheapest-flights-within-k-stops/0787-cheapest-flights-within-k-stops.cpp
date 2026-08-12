#define vi vector<int>
#define vipi vector<vector<pair<int,int>>>
const int inf = 1e9;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vipi adj(n);
        for(int i = 0;i < flights.size();i++){
            int u = flights[i][0] , v = flights[i][1] , c = flights[i][2];
            adj[u].push_back({v , c});
        }
        vi dist(n, inf);
        dist[src] = 0;
        using state = pair<int,int>;
        queue<state> q;
        q.push({0 ,src});
        int used = 0;
        while(!q.empty() && used <= k){
            int size = q.size();
            while(size--){

             auto[d,u]= q.front();
            q.pop();
             
            for(auto[v,c]: adj[u]){
                 int nc = d + c;
                if(nc < dist[v]){
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