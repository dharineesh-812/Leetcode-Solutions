#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vvi adj(n);

        for(int i = 0; i < n;i++){
            for(int nei : rooms[i])
                adj[i].pb(nei);
        }

        queue<int>q;
        q.push(0);

        vi vis(n , 0);
        vis[0] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v :adj[u]){
                if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                }
            }
        }
        for(int i = 0;i < n;i++)
            if(!vis[i])
                return false;
    return true;
    }
};