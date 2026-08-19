#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vvi adj(n);
        vi outdegree(n);

        queue<int> q;

        for(int i = 0; i < n;i++){
            for(int num : graph[i]){
                adj[num].pb(i);
            }
            outdegree[i] = graph[i].size();
            if(outdegree[i] == 0)
                q.push(i);
        }
        vi safe(n,0);
        vi ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = 1;
            for(int nei : adj[node]){
                outdegree[nei]--;
                if(outdegree[nei] == 0)
                    q.push(nei);
            }
        }
        for(int i = 0; i < n;i++){
            if(safe[i])
                ans.pb(i);
        }
    return ans;
    }
};