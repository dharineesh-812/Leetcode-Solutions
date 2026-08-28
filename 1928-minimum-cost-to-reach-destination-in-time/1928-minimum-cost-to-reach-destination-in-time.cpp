#define vi vector<int>
#define pi pair<int,int>
#define vpi vector<pi>
#define vvi vector<vpi>
#define mp make_pair
#define pb push_back
#define S second
#define F first

const int inf = 1e9;
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vi> cost(maxTime + 1 , vi(n , inf));
        vvi adj(n);
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0] , v = edges[i][1] , t = edges[i][2];
            adj[u].pb(mp(v , t));
            adj[v].pb(mp(u , t));
        }
        cost[0][0] = passingFees[0];
        using state = pair<int,pi>;

        priority_queue<state , vector<state> , greater<state>> st;
        st.push(mp(0, mp(cost[0][0] , 0)));

        while(!st.empty()){
            state it = st.top();
            st.pop();

            int t = it.F , c = it.S.F , u = it.S.S;

            // if(t <= maxTime && u == n - 1)
            //     return c;
            for(pi node : adj[u]){
                int v = node.F , ti = node.S;
                int nt = t + ti;
                int nc = c + passingFees[v];

                if(nt <= maxTime && nc < cost[nt][v]){
                    // if(cost[v] != inf)
                    //     st.erase(mp(ti , mp(cost[v] , v)));
                    cost[nt][v] = nc;
                    st.push(mp(nt , mp(nc , v)));
                }
            }
        }
        int ans = inf;
        for(int i = 0;i <= maxTime;i++){
            ans = min(ans , cost[i][n - 1]);
        }
        if(ans != inf)
            return ans;
        return -1;
    }
};