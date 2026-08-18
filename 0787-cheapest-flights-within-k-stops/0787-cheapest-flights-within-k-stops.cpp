#define vi vector<int>
#define pi pair<int, int>
#define F first
#define S second
const int inf = 1e9;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector<vector<pi>> adj(n);
        int res = inf;
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0], v = flights[i][1], c = flights[i][2];
            adj[u].push_back({v, c});
        }
        using state = pair<int, pi>;
        set<state> st;
        vi dist(n, inf);
        dist[src] = 0;
        st.insert({0, {0, src}});
        while (!st.empty()) {
            state it = *st.begin();
            st.erase(st.begin());
            int used = it.F, c = it.S.F, u = it.S.S;
            for (auto [v, d] : adj[u]) {
                int nc = d + c;
                if(v == dst)
                    res = min(res , nc);
                if (used >= k) 
                    continue;
                if(nc < dist[v]) {
                    dist[v] = nc;
                    st.insert({used + 1 ,{nc, v}});
                } 
            }
        }
        if (res != inf)
            return res;
        return -1;
    }
};