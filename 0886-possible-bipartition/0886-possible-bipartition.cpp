#define vi vector<int>
#define vvi vector<vi> 
class Solution {
public:
    bool dfs(int node , int c , vi &color , vvi& adj){
        color[node] = c;
        for(int nei : adj[node]){
            if(color[nei] == -1 && !dfs(nei , 1 - c , color , adj))
                return false;
            if(color[nei] == color[node])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vi color(n + 1, -1);
        vvi adj(n + 1);
        for(int i = 0; i < dislikes.size();i++){
            int u = dislikes[i][0] , v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i < n + 1;i++){
            if(color[i] == -1 && !dfs(i, 0 , color , adj))
                return false;
        }
        return true;
    }
};