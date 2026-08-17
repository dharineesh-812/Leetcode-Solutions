#define vi vector<int>

class Solution {
public:
    bool dfs(int node , int c , vi & color ,vector<vector<int>>& graph){
        color[node] = c;
        for(int nei : graph[node]){
            if(color[nei] == -1 && !dfs(nei , 1 - c , color , graph)){
                return false;
            }
            else if(color[nei] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vi color(n,-1);
        for(int i = 0;i < n;i++){
            if(color[i] == -1 && !dfs(i , 0 , color , graph))
                return false;
        }
        return true;
    }
};