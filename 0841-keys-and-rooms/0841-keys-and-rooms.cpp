
#define vi vector<int> 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);

        int n = rooms.size();
        vi vis(n , 0);


        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = 1;

            for(int v : rooms[u]){
                if(!vis[v])
                    q.push(v);
            }
        }
        for(int i = 0;i < n;i++){
            if(!vis[i])
                return false;
        }
        return true;
    }
};