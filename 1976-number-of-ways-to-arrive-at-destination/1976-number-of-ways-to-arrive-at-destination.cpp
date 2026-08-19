#define vi vector<int>
#define vl vector<long long>
#define pi pair<long long,int>
#define vpi vector<vector<pi>>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const long long inf = 1e18;
const int mod = 1e9 + 7;
using ll = long long;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vpi adj(n);

        for(int i = 0; i < roads.size();i++){
            int u = roads[i][0] , v = roads[i][1] , w = roads[i][2];
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
        }
        vl dis(n,inf);
        vl ways(n,0);
        
        dis[0] = 0;
        ways[0] = 1;
        using state = pi;
        set<state>st;
        st.insert(mp(0,0));

        while(!st.empty()){
            state it = *st.begin();
            st.erase(st.begin());

            ll dsrc = it.F , node = it.S;
            if(dsrc > dis[node])
                continue;
            for(pi nei : adj[node]){
                ll v = nei.F;
                ll w = nei.S;

                if(dis[node] + w == dis[v])
                    ways[v] = (ways[v] + ways[node]) % mod;
                else if(dis[node] + w < dis[v]){
                    ways[v] = ways[node];
                    st.erase(mp(dis[v] , v));
                    dis[v] = dis[node] + w;
                    st.insert(mp(dis[v] , v));
                }
            }
        }
        return ways[n - 1];
    }
};