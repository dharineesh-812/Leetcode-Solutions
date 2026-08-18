#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vi indegree(numCourses);
        vvi adj(numCourses);
        vi ans;
        for(int i = 0; i < prerequisites.size();i++){
            int u = prerequisites[i][0] , v = prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i = 0; i < numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt += 1;
            ans.push_back(node);
            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(cnt == numCourses)
            return ans;
        return {};
    }
};
