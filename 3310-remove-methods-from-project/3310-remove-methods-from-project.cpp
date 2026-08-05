class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        vector<vector<int>>adj(n);  
        for(auto i : invocations)
            adj[i[0]].push_back(i[1]);
        queue<int> q;
        q.push(k);
        vector<int> vis(n , 0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = 1;
            for(auto v : adj[u]){
                if(!vis[v])
                    q.push(v);
            }
        }
        bool flag = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                for(auto v : adj[i]){
                    if(vis[v]){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(!flag){
            for(int i = 0; i < n;i++){
                if(!vis[i])
                    ans.push_back(i);
            }
        }
        else{
            for(int i = 0;i < n;i++)
                ans.push_back(i);
        }
        return ans;
    }
};