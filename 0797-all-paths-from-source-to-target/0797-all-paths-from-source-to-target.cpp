#define vi vector<int>
#define pb push_back();
class Solution {
public:
    void dfs(int node , vector<vi> &graph , vi &path , vector<vi> &ans){
        path.push_back(node);

        if(node == graph.size() - 1){
            ans.push_back(path);
            path.pop_back(); 
            return ;
        }
        for(int nei : graph[node]){
            dfs(nei , graph , path , ans);
        }
        path.pop_back();    
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vi path;
        vector<vi> ans;

        dfs(0 , graph , path , ans);
        return ans;
    }
};